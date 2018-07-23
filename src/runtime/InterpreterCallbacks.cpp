// Copyright (c) 2018, Tobechukwu Osakwe.
//
// All rights reserved.
//
// Use of this source code is governed by an
// MIT-style license that can be found in the LICENSE file.
#include "Interpreter.h"
using namespace manda;

void manda::ExpressionStatementNode::acceptInterpreter(manda::Interpreter *interpreter) {
    interpreter->VisitExpressionStatement(this);
}

jit_value_t manda::SimpleIdentifierNode::acceptInterpreter(manda::Interpreter *interpreter) {
    return interpreter->VisitSimpleIdentifier(this);
}

jit_value_t NumberLiteralNode::acceptInterpreter(Interpreter *interpreter) {
    return interpreter->VisitNumberLiteral(this);
}