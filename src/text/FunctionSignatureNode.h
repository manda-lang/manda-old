// Copyright (c) 2018, Tobechukwu Osakwe.
//
// All rights reserved.
//
// Use of this source code is governed by an
// MIT-style license that can be found in the LICENSE file.
#ifndef MANDA_FUNCTIONSIGNATURENODE_H
#define MANDA_FUNCTIONSIGNATURENODE_H

#include "AstNode.h"
#include "ParameterListNode.h"
#include "TypeNode.h"

namespace manda
{
    class FunctionSignatureNode : public AstNode
    {
    public:
        explicit FunctionSignatureNode(const ParameterListNode *parameterList, const TypeNode *returnType);

        ~FunctionSignatureNode();

        const ParameterListNode *GetParameterList() const;

        const TypeNode *GetReturnType() const;

    private:
        const ParameterListNode *parameterList;
        const TypeNode *returnType;
    };
}

#endif //MANDA_FUNCTIONSIGNATURENODE_H
