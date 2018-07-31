// Copyright (c) 2018, Tobechukwu Osakwe.
//
// All rights reserved.
//
// Use of this source code is governed by an
// MIT-style license that can be found in the LICENSE file.
#ifndef MANDA_PARAMETERNODE_H
#define MANDA_PARAMETERNODE_H

#include <string>
#include "AstNode.h"
#include "ExpressionNode.h"
#include "SimpleIdentifierNode.h"
#include "TypeNode.h"

namespace manda
{
    class ParameterNode : public AstNode
    {
    public:
        explicit ParameterNode(const SimpleIdentifierNode *name, const TypeNode *type, const ExpressionNode *defaultValue);

        explicit ParameterNode(const SimpleIdentifierNode* name);

        explicit ParameterNode(const SimpleIdentifierNode* name, const TypeNode *type);

        explicit ParameterNode(const SimpleIdentifierNode* name, const ExpressionNode *defaultValue);
        
        ~ParameterNode();

        const SimpleIdentifierNode *GetIdentifier() const;

        const ExpressionNode *GetDefaultValue() const;

        const TypeNode *GetType() const;

        const SourceSpan *GetSourceSpan() const override;

    private:
        const SimpleIdentifierNode *identifier;
        const ExpressionNode *defaultValue;
        const TypeNode *type;
    };
}

#endif //MANDA_PARAMETERNODE_H
