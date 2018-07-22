// Copyright (c) 2018, Tobechukwu Osakwe.
//
// All rights reserved.
//
// Use of this source code is governed by an
// MIT-style license that can be found in the LICENSE file.
#ifndef MANDA_ASTNODE_H
#define MANDA_ASTNODE_H

#include "SourceSpan.h"

namespace manda
{
    class AstNode
    {
    public:
        // TODO: Comments
        virtual const SourceSpan *GetSourceSpan() const = 0;
    };
}

#endif //MANDA_ASTNODE_H
