// Copyright (c) 2018, Tobechukwu Osakwe.
//
// All rights reserved.
//
// Use of this source code is governed by an
// MIT-style license that can be found in the LICENSE file.
#ifndef MANDA_OBJECT_H
#define MANDA_OBJECT_H

#include "../text/text.h"
#include "Type.h"

namespace manda
{
    class Type;

    class Object
    {
    public:
        explicit Object(Type *type, SourceSpan *span);

        ~Object();

        const Type *GetType() const;

        const SourceSpan *GetSourceSpan() const;

    protected:
        explicit Object();

        const Type *type;
        const SourceSpan *sourceSpan;
    };
}

#endif //MANDA_OBJECT_H
