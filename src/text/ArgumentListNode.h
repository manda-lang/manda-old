// Copyright (c) 2018, Tobechukwu Osakwe.
//
// All rights reserved.
//
// Use of this source code is governed by an
// MIT-style license that can be found in the LICENSE file.
#ifndef MANDA_ARGUMENTLISTNODE_H
#define MANDA_ARGUMENTLISTNODE_H

#include <vector>
#include "AstNode.h"
#include "ExpressionNode.h"
#include "Token.h"

namespace manda
{
    class ArgumentListNode : public AstNode
    {
    public:
        explicit ArgumentListNode(const Token *lParen);

        ~ArgumentListNode();

        const std::vector<const ExpressionNode *> &GetArguments() const;

        void AddArgument(const ExpressionNode *expression);

        const SourceSpan *GetSourceSpan() const override;

    private:
        std::vector<const ExpressionNode *> arguments;
        const Token *lParen;
    };
}

#endif //MANDA_ARGUMENTLISTNODE_H
