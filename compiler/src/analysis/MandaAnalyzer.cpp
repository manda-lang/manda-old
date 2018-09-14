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
        auto *stmt = new CfgValueStatement(value, currentScope);
        return Any((CfgStatement *) stmt);
    }
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
        return Any(symbol->GetValue());
    }
}

Any manda::MandaAnalyzer::visitParenExpr(MandaParser::ParenExprContext *ctx) {
    return ctx->expr()->accept(this);
}
