// Copyright (c) 2018, Tobechukwu Osakwe.
//
// All rights reserved.
//
// Use of this source code is governed by an
// MIT-style license that can be found in the LICENSE file.
#ifndef MANDA_STATEMENT_H
#define MANDA_STATEMENT_H

#include "../runtime/TaggedPointer.h"
#include "AstNode.h"

namespace manda
{
    class Interpreter;

    class StatementNode : public AstNode
    {
    public:
        virtual ~StatementNode() = 0;

        virtual void acceptInterpreter(Interpreter *interpreter) = 0;
    };
}

#endif //MANDA_STATEMENT_H
