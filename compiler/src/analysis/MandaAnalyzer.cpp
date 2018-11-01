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

manda::MandaAnalyzer::MandaAnalyzer()
        : coreTypes(MandaCoreTypes()) {
    coreTypes.InjectIntoSymbolTable(currentScope);
}

const manda::MandaCoreTypes &manda::MandaAnalyzer::GetCoreTypes() const {
    return coreTypes;
}

Any manda::MandaAnalyzer::visitCompilationUnit(MandaParser::CompilationUnitContext *ctx) {
    unit = ctx;
    return MandaBaseVisitor::visitCompilationUnit(ctx);
}

Any manda::MandaAnalyzer::visitExprStmt(MandaParser::ExprStmtContext *ctx) {
    Any valueAny = ctx->expr()->accept(this);

    if (valueAny.isNull()) {
        errors.emplace_back(
                MandaError::kError,
                "Evaluating this expression produced an error.",
                SourceSpan(*ctx));
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
        errors.emplace_back(
                MandaError::kError,
                "Evaluating this expression produced an error.",
                SourceSpan(*ctx));
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
        errors.emplace_back(MandaError::kError, "Could not resolve this binary expression.",
                            SourceSpan(*ctx));
        return Any();
    } else {

        if (leftAny.is<MandaType *>() || rightAny.is<MandaType *>()) {
            errors.emplace_back(
                    MandaError::kError,
                    "Binary operators may not be applied directly to types.",
                    SourceSpan(*ctx));
            return Any();
        } else {
            auto *left = leftAny.as<MandaObject *>(), *right = rightAny.as<MandaObject *>();

            // Binary operators must be applied to values of compatible types.
            if (!(left->type.isAssignableTo(right->type))) {
                errors.emplace_back(
                        MandaError::kError,
                        "Cannot perform a binary operation on two values of incompatible types.",
                        SourceSpan(*ctx));
                return Any();
            }

            try {
                // Let the left type handle the computation.
                auto result = left->type.binaryOperation(*left, *right, op,
                                                         SourceSpan(*ctx));
                return Any(&result); // TODO: Untracked pointer?
            } catch (const MandaException &exc) {
                errors.push_back(exc.error);
                return Any();
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

Any manda::MandaAnalyzer::visitBoolAndOrExpr(MandaParser::BoolAndOrExprContext *ctx) {
    return resolveBinary(ctx, ctx->left, ctx->right, ctx->op->getText());
}

Any manda::MandaAnalyzer::visitBoolEqOrNeqExpr(MandaParser::BoolEqOrNeqExprContext *ctx) {
    return resolveBinary(ctx, ctx->left, ctx->right, ctx->op->getText());
}

Any manda::MandaAnalyzer::visitTrueExpr(MandaParser::TrueExprContext *ctx) {
    auto *object = new MandaObject(coreTypes.boolType, SourceSpan(*ctx));
    object->constantValueType = MandaObject::kBool;
    object->constantValue.asBool = true;
    return Any(object);
}

Any manda::MandaAnalyzer::visitFalseExpr(MandaParser::FalseExprContext *ctx) {
    auto *object = new MandaObject(coreTypes.boolType, SourceSpan(*ctx));
    object->constantValueType = MandaObject::kBool;
    object->constantValue.asBool = false;
    return Any(object);
}


Any manda::MandaAnalyzer::visitIntegerExpr(MandaParser::IntegerExprContext *ctx) {
    uint64_t value = strtoul(ctx->getText().c_str(), nullptr, 10);
    auto *object = new MandaObject(coreTypes.int32Type, SourceSpan(*ctx));
    object->constantValueType = MandaObject::kSigned;
    object->constantValue.asSigned = value;
    return Any(object);
}

Any manda::MandaAnalyzer::visitHexExpr(MandaParser::HexExprContext *ctx) {
    uint64_t value = stoul(ctx->getText(), nullptr, 16);
    auto *object = new MandaObject(coreTypes.int32Type, SourceSpan(*ctx));
    object->constantValueType = MandaObject::kSigned;
    object->constantValue.asSigned = value;
    return Any(object);
}

Any manda::MandaAnalyzer::visitFloatExpr(MandaParser::FloatExprContext *ctx) {
    // TODO: Parse float -> Float32
    return MandaBaseVisitor::visitFloatExpr(ctx);
}

Any manda::MandaAnalyzer::visitIdentifierExpr(MandaParser::IdentifierExprContext *ctx) {
    auto name = ctx->Identifier()->getText();

    try {
        auto &symbol = currentScope.resolve(name);
        return Any(static_cast<MandaObjectOrType*>(&symbol.value)); // TODO: Unwatched pointer
    } catch (const SymbolTableException &exc) {
        errors.emplace_back(MandaError::kError, exc.message, SourceSpan(*ctx));
        return Any();
    }
}

Any manda::MandaAnalyzer::visitParenExpr(MandaParser::ParenExprContext *ctx) {
    return ctx->expr()->accept(this);
}

MandaParser::CompilationUnitContext *manda::MandaAnalyzer::GetCompilationUnit() const {
    return unit;
}
