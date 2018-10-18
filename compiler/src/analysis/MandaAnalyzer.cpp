// Copyright (c) 2018, Tobechukwu Osakwe.
//
// All rights reserved.
//
// Use of this source code is governed by an
// MIT-style license that can be found in the LICENSE file.
#include <sstream>
#include <string>
#include "../cfg/cfg.h"
#include "MandaAnalyzer.h"
#include "MandaObject.h"

manda::MandaAnalyzer::MandaAnalyzer() {
    this->coreTypes = new MandaCoreTypes;
    this->currentScope = new SymbolTable;
    coreTypes->InjectIntoSymbolTable(*currentScope);
}

const std::vector<manda::MandaError *> &manda::MandaAnalyzer::GetErrors() const {
    return errors;
}

Any manda::MandaAnalyzer::visitCompilationUnit(MandaParser::CompilationUnitContext *ctx) {
    unit = ctx;
    return MandaBaseVisitor::visitCompilationUnit(ctx);
}

Any manda::MandaAnalyzer::visitExprStmt(MandaParser::ExprStmtContext *ctx) {
    Any valueAny = ctx->expr()->accept(this);

    if (valueAny.isNull()) {
        errors.push_back(new MandaError(
                MandaError::kError,
                "Evaluating this expression produced an error.",
                SourceSpan::fromParserRuleContext(ctx)));
        return Any();
    } else {
        auto *value = valueAny.as<MandaObjectOrType *>();
        // TODO: Only allow calls here
        auto *stmt = new CfgValueStatement(value, currentScope, false);
        return Any((CfgStatement *) stmt);
    }
}

Any manda::MandaAnalyzer::visitReturnStmt(MandaParser::ReturnStmtContext *ctx) {
    Any valueAny = ctx->expr()->accept(this);

    if (valueAny.isNull()) {
        errors.push_back(new MandaError(
                MandaError::kError,
                "Evaluating this expression produced an error.",
                SourceSpan::fromParserRuleContext(ctx)));
        return Any();
    } else {
        auto *value = valueAny.as<MandaObjectOrType *>();
        // TODO: Only allow calls here
        auto *stmt = new CfgValueStatement(value, currentScope, true);
        return Any((CfgStatement *) stmt);
    }
}

Any manda::MandaAnalyzer::resolveBinary(antlr4::ParserRuleContext *ctx, MandaParser::ExprContext *leftCtx,
                                        MandaParser::ExprContext *rightCtx, const std::string &op) {
    Any leftAny = leftCtx->accept(this), rightAny = rightCtx->accept(this);

    if (leftAny.isNull() || rightAny.isNull()) {
        errors.push_back(new MandaError(MandaError::kError, "Could not resolve this binary expression.",
                                        SourceSpan::fromParserRuleContext(ctx)));
        return Any();
    } else {
        auto *leftValue = leftAny.as<MandaObjectOrType *>(), *rightValue = rightAny.as<MandaObjectOrType *>();

        if (leftValue->IsType() || rightValue->IsType()) {
            errors.push_back(
                    new MandaError(
                            MandaError::kError,
                            "Binary operators may not be applied directly to types.",
                            SourceSpan::fromParserRuleContext(ctx)));
            return Any();
        } else {
            auto *left = leftValue->AsObject(), *right = rightValue->AsObject();

            // Binary operators must be applied to values of compatible types.
            if (!(left->GetType()->IsAssignableTo(right->GetType()))) {
                errors.push_back(
                        new MandaError(
                                MandaError::kError,
                                "Cannot perform a binary operation on two values of incompatible types.",
                                SourceSpan::fromParserRuleContext(ctx)));
                return Any();
            }

            // Let the left type handle the computation.
            auto *result = left->GetType()->PerformBinaryOperation(left, right, op,
                                                                   SourceSpan::fromParserRuleContext(ctx));

            if (result == nullptr) {
                errors.push_back(
                        new MandaError(
                                MandaError::kError,
                                "Evaluating this binary operation produced an error.",
                                SourceSpan::fromParserRuleContext(ctx)));
                return Any();
            } else {
                return Any(result);
            }
        }
    }
}

Any manda::MandaAnalyzer::visitMulDivOrModExpr(MandaParser::MulDivOrModExprContext *ctx) {
    return resolveBinary(ctx, ctx->left, ctx->right, ctx->op->getText());
}

Any manda::MandaAnalyzer::visitAddOrSubExpr(MandaParser::AddOrSubExprContext *ctx) {
    return resolveBinary(ctx, ctx->left, ctx->right, ctx->op->getText());
}

Any manda::MandaAnalyzer::visitTrueExpr(MandaParser::TrueExprContext *ctx) {
    auto *object = new MandaObject(coreTypes->GetBoolType(), SourceSpan::fromParserRuleContext(ctx));
    object->constantValueType = MandaObject::kBool;
    object->constantValue.asBool = true;
    return Any(new MandaObjectOrType(object));
}

Any manda::MandaAnalyzer::visitFalseExpr(MandaParser::FalseExprContext *ctx) {
    auto *object = new MandaObject(coreTypes->GetBoolType(), SourceSpan::fromParserRuleContext(ctx));
    object->constantValueType = MandaObject::kBool;
    object->constantValue.asBool = false;
    return Any(new MandaObjectOrType(object));
}


Any manda::MandaAnalyzer::visitIntegerExpr(MandaParser::IntegerExprContext *ctx) {
    uint64_t value = strtol(ctx->getText().c_str(), nullptr, 10);
    auto *object = new MandaObject(coreTypes->GetInt32Type(), SourceSpan::fromParserRuleContext(ctx));
    object->constantValueType = MandaObject::kSigned;
    object->constantValue.asSigned = value;
    return Any(new MandaObjectOrType(object));
}

Any manda::MandaAnalyzer::visitHexExpr(MandaParser::HexExprContext *ctx) {
    uint64_t value = stoul(ctx->getText(), nullptr, 16);
    auto *object = new MandaObject(coreTypes->GetInt32Type(), SourceSpan::fromParserRuleContext(ctx));
    object->constantValueType = MandaObject::kSigned;
    object->constantValue.asSigned = value;
    return Any(new MandaObjectOrType(object));
}

Any manda::MandaAnalyzer::visitFloatExpr(MandaParser::FloatExprContext *ctx) {
    // TODO: Parse float -> Float32
    return MandaBaseVisitor::visitFloatExpr(ctx);
}

Any manda::MandaAnalyzer::visitIdentifierExpr(MandaParser::IdentifierExprContext *ctx) {
    auto name = ctx->Identifier()->getText();
    auto *symbol = currentScope->Resolve(name);

    if (symbol == nullptr) {
        std::ostringstream message;
        message << "The name \"" << name << "\" does not exist in the current context.";
        auto *error = new MandaError(MandaError::kError, message.str(), SourceSpan::fromParserRuleContext(ctx));
        errors.push_back(error);
        return Any();
    } else {
        return Any((MandaObjectOrType *) symbol->GetValue());
    }
}

Any manda::MandaAnalyzer::visitParenExpr(MandaParser::ParenExprContext *ctx) {
    return ctx->expr()->accept(this);
}

MandaParser::CompilationUnitContext * manda::MandaAnalyzer::GetCompilationUnit() const {
    return unit;
}