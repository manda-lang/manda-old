// Copyright (c) 2018, Tobechukwu Osakwe.
//
// All rights reserved.
//
// Use of this source code is governed by an
// MIT-style license that can be found in the LICENSE file.
#ifndef MANDA_EXPRESSION_H
#define MANDA_EXPRESSION_H

#include <jit/jit.h>
#include "../runtime/Object.h"
#include "AstNode.h"

namespace manda
{
    class Interpreter;

    class ExpressionNode : public AstNode
    {
    public:
        virtual ~ExpressionNode();

        virtual bool HasConstantValue() = 0;

        virtual jit_value_t acceptInterpreter(Interpreter *interpreter) = 0;
    };
}

#endif //MANDA_EXPRESSION_H
