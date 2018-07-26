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
        virtual unsigned long GetStatementCount() = 0;

        virtual const StatementNode *GetStatements() = 0;
    };
}

#endif //MANDA_FUNCTIONBODYNODE_H
