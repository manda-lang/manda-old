// Copyright (c) 2018, Tobechukwu Osakwe.
//
// All rights reserved.
//
// Use of this source code is governed by an
// MIT-style license that can be found in the LICENSE file.
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

Any manda::MandaAnalyzer::visitIntegerExpr(MandaParser::IntegerExprContext *ctx) {
    uint64_t value = strtoul(ctx->getText().c_str(), nullptr, 10);
    auto *object = new MandaObject(coreTypes->GetInt32Type(), SourceSpan::fromParserRuleContext(ctx));
    object->constantValueType = MandaObject::kSigned;
    object->constantValue.asUnsigned = value;
    return Any(new MandaObjectOrType(object));
}

Any manda::MandaAnalyzer::visitHexExpr(MandaParser::HexExprContext *ctx) {
    uint64_t value = strtoul(ctx->getText().substr(2).c_str(), nullptr, 16);
    auto *object = new MandaObject(coreTypes->GetInt32Type(), SourceSpan::fromParserRuleContext(ctx));
    object->constantValueType = MandaObject::kSigned;
    object->constantValue.asUnsigned = value;
    return Any(new MandaObjectOrType(object));
}

Any manda::MandaAnalyzer::visitFloatExpr(MandaParser::FloatExprContext *ctx) {
    // TODO: Parse float -> Float32
    return MandaBaseVisitor::visitFloatExpr(ctx);
}

Any manda::MandaAnalyzer::visitParenExpr(MandaParser::ParenExprContext *ctx) {
    return ctx->expr()->accept(this);
}
