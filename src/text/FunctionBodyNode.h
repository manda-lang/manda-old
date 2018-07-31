// Copyright (c) 2018, Tobechukwu Osakwe.
//
// All rights reserved.
//
// Use of this source code is governed by an
// MIT-style license that can be found in the LICENSE file.
#ifndef MANDA_FUNCTIONBODYNODE_H
#define MANDA_FUNCTIONBODYNODE_H

#include "AstNode.h"
#include "StatementNode.h"

namespace manda
{
    class FunctionBodyNode : public AstNode
    {
    public:
        virtual ~FunctionBodyNode() = default;

        virtual unsigned long GetStatementCount() const = 0;

        virtual const StatementNode **GetStatements() const = 0;
    };
}

#endif //MANDA_FUNCTIONBODYNODE_H
