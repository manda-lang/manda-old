// Copyright (c) 2018, Tobechukwu Osakwe.
//
// All rights reserved.
//
// Use of this source code is governed by an
// MIT-style license that can be found in the LICENSE file.
#ifndef MANDA_IDENTIFIERNODE_H
#define MANDA_IDENTIFIERNODE_H

#include "ExpressionNode.h"
#include "Token.h"

namespace manda
{
    class SimpleIdentifierNode : public ExpressionNode
    {
    public:
        explicit SimpleIdentifierNode(const Token *token);

        ~SimpleIdentifierNode();

        const std::string &GetName() const;

        const SourceSpan *GetSourceSpan() const override;

        bool HasConstantValue() override;

        jit_value_t acceptInterpreter(Interpreter *interpreter) override;

    private:
        Token *token;
    };
}

#endif //MANDA_IDENTIFIERNODE_H
