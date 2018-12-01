// Copyright (c) 2018, Tobechukwu Osakwe.
//
// All rights reserved.
//
// Use of this source code is governed by an
// MIT-style license that can be found in the LICENSE file.
#ifndef PROJECT_AST_NODE_H
#define PROJECT_AST_NODE_H

#include "source_span.h"

namespace manda
{
    struct AstNode
    {
        virtual explicit AstNode(const SourceSpan &span);

        AstNode() = delete;

        SourceSpan span;
    };
}

#endif //PROJECT_AST_NODE_H
