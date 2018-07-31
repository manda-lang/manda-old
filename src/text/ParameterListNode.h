// Copyright (c) 2018, Tobechukwu Osakwe.
//
// All rights reserved.
//
// Use of this source code is governed by an
// MIT-style license that can be found in the LICENSE file.
#ifndef MANDA_PARAMETERLIST_H
#define MANDA_PARAMETERLIST_H

#include <vector>
#include "AstNode.h"
#include "ParameterNode.h"

namespace manda
{
    class ParameterListNode : public AstNode
    {
    public:
        explicit ParameterListNode(const SourceSpan *span);

        ~ParameterListNode();

        const std::vector<ParameterNode *> &GetParameters() const;

        void AddParameter(ParameterNode *parameter);

    public:
        const SourceSpan *GetSourceSpan() const override;

    private:
        std::vector<ParameterNode *> parameters;
        SourceSpan *span;
    };
}

#endif //MANDA_PARAMETERLIST_H
