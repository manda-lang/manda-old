// Copyright (c) 2018, Tobechukwu Osakwe.
//
// All rights reserved.
//
// Use of this source code is governed by an
// MIT-style license that can be found in the LICENSE file.
#include "MandaAnalyzer.h"
#include "MandaObject.h"

manda::MandaAnalyzer::MandaAnalyzer() {
    this->currentScope = new SymbolTable;
}

Any manda::MandaAnalyzer::visitIntegerExpr(MandaParser::IntegerExprContext *ctx) {
    uint64_t value = strtoul(ctx->getText().c_str(), nullptr, 10);
    auto *int32Type = currentScope->Resolve("Int32")->GetValue()->AsType();
    auto *object = new MandaObject(int32Type, SourceSpan::fromParserRuleContext(ctx));
    object->constantValueType = MandaObject::kSigned;
    object->constantValue.asUnsigned = value;
    return Any(new MandaObjectOrType(object));
}

Any manda::MandaAnalyzer::visitHexExpr(MandaParser::HexExprContext *ctx) {
    uint64_t value = strtoul(ctx->getText().substr(2).c_str(), nullptr, 16);
    auto *int32Type = currentScope->Resolve("Int32")->GetValue()->AsType();
    auto *object = new MandaObject(int32Type, SourceSpan::fromParserRuleContext(ctx));
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
