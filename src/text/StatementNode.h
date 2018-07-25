// Copyright (c) 2018, Tobechukwu Osakwe.
//
// All rights reserved.
//
// Use of this source code is governed by an
// MIT-style license that can be found in the LICENSE file.
#ifndef MANDA_STATEMENT_H
#define MANDA_STATEMENT_H

#include "AstNode.h"

namespace manda
{
    class Analyzer;

    class StatementNode : public AstNode
    {
    public:
        virtual ~StatementNode() = 0;

        virtual bool HasFunctionDeclaration() const = 0;

        virtual bool IsExpressionStatement() const = 0;

        virtual void AcceptAnalyzer(Analyzer *analyzer) = 0;
    };
}

#endif //MANDA_STATEMENT_H
