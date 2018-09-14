// Copyright (c) 2018, Tobechukwu Osakwe.
//
// All rights reserved.
//
// Use of this source code is governed by an
// MIT-style license that can be found in the LICENSE file.
#include "MandaAnalyzer.h"
#include "MandaObject.h"

Any manda::MandaAnalyzer::visitIntegerExpr(MandaParser::IntegerExprContext *ctx) {
    uint64_t value = strtoul(ctx->getText().c_str(), nullptr, 10);
    auto *object = new MandaObject(nullptr, SourceSpan::fromParserRuleContext(ctx)); // TODO: Int32
    object->constantValueType = MandaObject::kUnsigned;
    object->constantValue.asUnsigned = value;
    return Any(new MandaObjectOrType(object));
}
