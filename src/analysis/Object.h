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
    class Function;

    class Type;

    class Object
    {
    public:
        explicit Object(const Type *type, const SourceSpan *span);

        ~Object();

        const Type *GetType() const;

        const SourceSpan *GetSourceSpan() const;

        virtual bool IsReference() const {
            return false;
        }

        enum RawObjectType
        {
            NONE, STRING, DOUBLE, LONG, FUNCTION
        };

        struct
        {
            RawObjectType type = NONE;
            union
            {
                const char *asString;
                uint64_t asUint64;
                double asDouble = 0.0;
                Function *function;
            } value;
        } rawObject;

    protected:
        explicit Object();

        const Type *type = nullptr;
        const SourceSpan *sourceSpan = nullptr;
    };
}

#endif //MANDA_OBJECT_H
