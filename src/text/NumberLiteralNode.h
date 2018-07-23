// Copyright (c) 2018, Tobechukwu Osakwe.
//
// All rights reserved.
//
// Use of this source code is governed by an
// MIT-style license that can be found in the LICENSE file.
#ifndef MANDA_DECIMALLITERAL_H
#define MANDA_DECIMALLITERAL_H

#include "ExpressionNode.h"
#include "Token.h"

namespace manda
{
    class NumberLiteralNode : public ExpressionNode
    {
    public:
        explicit NumberLiteralNode(const Token *token);

        ~NumberLiteralNode();

        const Token *GetToken() const;

        const SourceSpan *GetSourceSpan() const override;

        bool HasConstantValue() override;

        jit_value_t acceptInterpreter(Interpreter *interpreter) override;


    private:
        const Token *token;
    };
}

#endif //MANDA_DECIMALLITERAL_H
