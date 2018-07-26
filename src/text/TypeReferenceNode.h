// Copyright (c) 2018, Tobechukwu Osakwe.
//
// All rights reserved.
//
// Use of this source code is governed by an
// MIT-style license that can be found in the LICENSE file.
#ifndef MANDA_TYPEREFERENCE_H
#define MANDA_TYPEREFERENCE_H

#include "SimpleIdentifierNode.h"
#include "TypeNode.h"

namespace manda
{
    class TypeReferenceNode : public TypeNode
    {
    public:
        explicit TypeReferenceNode(const SimpleIdentifierNode *identifier);

        ~TypeReferenceNode();

        const std::string &GetName() const;

        const SourceSpan *GetSourceSpan() const override;

    private:
        const SimpleIdentifierNode *identifier;
    };
}

#endif //MANDA_TYPEREFERENCE_H
