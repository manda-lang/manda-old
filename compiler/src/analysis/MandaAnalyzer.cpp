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

void manda::MandaAnalyzer::visitCompilationUnit(MandaParser::CompilationUnitContext *ctx) {
    unit = ctx;
    return MandaBaseVisitor::visitCompilationUnit(ctx);
}

void manda::MandaAnalyzer::visitExprStmt(MandaParser::ExprStmtContext *ctx) {
    Any valueAny = ctx->expr()->accept(this);

    if (valueAny.isNull()) {
        errors.emplace_back(
                MandaError::kError,
                "Evaluating this expression produced an error.",
                SourceSpan(*ctx));
        return;
    } else {
        auto *value = valueAny.as<MandaObjectOrType *>();
        // TODO: Only allow calls here
        auto *stmt = new CfgValueStatement(value, currentScope, false);
        return Any((CfgStatement *) stmt);
    }
}

void manda::MandaAnalyzer::visitReturnStmt(MandaParser::ReturnStmtContext *ctx) {
    Any valueAny = ctx->expr()->accept(this);

    if (valueAny.isNull()) {
        errors.emplace_back(
                MandaError::kError,
                "Evaluating this expression produced an error.",
                SourceSpan(*ctx));
        return;
    } else {
        auto *value = valueAny.as<MandaObjectOrType *>();
        // TODO: Only allow calls here
        auto *stmt = new CfgValueStatement(value, currentScope, true);
        return Any((CfgStatement *) stmt);
    }
}

manda::MandaObjectOrType &manda::MandaAnalyzer::resolveBinary(antlr4::ParserRuleContext *ctx,
                                                              MandaParser::ExprContext *leftCtx,
                                                              MandaParser::ExprContext *rightCtx,
                                                              const std::string &op) {
    auto leftAny = visitExpr(leftCtx), rightAny = visitExpr(rightCtx);

    if (dynamic_cast<MandaType *>(&leftAny) || dynamic_cast<MandaType *>(&rightAny)) {
        errors.emplace_back(
                MandaError::kError,
                "Binary operators may not be applied directly to types.",
                SourceSpan(*ctx));
        return Any();
    } else {
        auto &left = static_cast<MandaObject &>(leftAny), &right = static_cast<MandaObject &>(rightAny);

        // Binary operators must be applied to values of compatible types.
        if (!(left.type.isAssignableTo(right.type))) {
            errors.emplace_back(
                    MandaError::kError,
                    "Cannot perform a binary operation on two values of incompatible types.",
                    SourceSpan(*ctx));
            return Any();
        }

        // Let the left type handle the computation.
        auto result = left.type.binaryOperation(left, right, op,
                                                SourceSpan(*ctx));
        return result; // TODO: Untracked pointer?
    }
}

manda::MandaObjectOrType &manda::MandaAnalyzer::visitMulDivOrModExpr(MandaParser::MulDivOrModExprContext *ctx) {
    return resolveBinary(ctx, ctx->left, ctx->right, ctx->op->getText());
}

manda::MandaObjectOrType &manda::MandaAnalyzer::visitAddOrSubExpr(MandaParser::AddOrSubExprContext *ctx) {
    return resolveBinary(ctx, ctx->left, ctx->right, ctx->op->getText());
}

manda::MandaObjectOrType &manda::MandaAnalyzer::visitBoolAndOrExpr(MandaParser::BoolAndOrExprContext *ctx) {
    return resolveBinary(ctx, ctx->left, ctx->right, ctx->op->getText());
}

manda::MandaObjectOrType &manda::MandaAnalyzer::visitBoolEqOrNeqExpr(MandaParser::BoolEqOrNeqExprContext *ctx) {
    return resolveBinary(ctx, ctx->left, ctx->right, ctx->op->getText());
}

manda::MandaObject &manda::MandaAnalyzer::visitTrueExpr(MandaParser::TrueExprContext *ctx) {
    MandaObject object(coreTypes.boolType, SourceSpan(*ctx));
    object.constantValueType = MandaObject::kBool;
    object.constantValue.asBool = true;
    return object;
}

manda::MandaObject &manda::MandaAnalyzer::visitFalseExpr(MandaParser::FalseExprContext *ctx) {
    MandaObject object(coreTypes.boolType, SourceSpan(*ctx));
    object.constantValueType = MandaObject::kBool;
    object.constantValue.asBool = false;
    return object;
}


manda::MandaObject &manda::MandaAnalyzer::visitIntegerExpr(MandaParser::IntegerExprContext *ctx) {
    uint64_t value = strtoul(ctx->getText().c_str(), nullptr, 10);
    MandaObject object(coreTypes.int32Type, SourceSpan(*ctx));
    object.constantValueType = MandaObject::kSigned;
    object.constantValue.asSigned = value;
    return object;
}

manda::MandaObject &manda::MandaAnalyzer::visitHexExpr(MandaParser::HexExprContext *ctx) {
    uint64_t value = stoul(ctx->getText(), nullptr, 16);
    MandaObject object(coreTypes.int32Type, SourceSpan(*ctx));
    object.constantValueType = MandaObject::kSigned;
    object.constantValue.asSigned = value;
    return object;
}

manda::MandaObject &manda::MandaAnalyzer::visitFloatExpr(MandaParser::FloatExprContext *ctx) {
    // TODO: Parse float -> Float32
    return MandaBaseVisitor::visitFloatExpr(ctx);
}

manda::MandaObjectOrType &manda::MandaAnalyzer::visitIdentifierExpr(MandaParser::IdentifierExprContext *ctx) {
    auto name = ctx->Identifier()->getText();

    try {
        auto &symbol = currentScope.resolve(name);
        return Any(static_cast<MandaObjectOrType *>(&symbol.value)); // TODO: Unwatched pointer
    } catch (const SymbolTableException &exc) {
        errors.emplace_back(MandaError::kError, exc.message, SourceSpan(*ctx));
        return Any();
    }
}

manda::MandaObjectOrType &manda::MandaAnalyzer::visitParenExpr(MandaParser::ParenExprContext *ctx) {
    return visitExpr(ctx->expr());
}

MandaParser::CompilationUnitContext *manda::MandaAnalyzer::GetCompilationUnit() const {
    return unit;
}

manda::MandaObjectOrType &manda::MandaAnalyzer::visitExpr(MandaParser::ExprContext *ctx) {
    if (auto *trueCtx = dynamic_cast<MandaParser::TrueExprContext *>(ctx)) {
        return visitTrueExpr(trueCtx);
    }
}
