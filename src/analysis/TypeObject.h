// Copyright (c) 2018, Tobechukwu Osakwe.
//
// All rights reserved.
//
// Use of this source code is governed by an
// MIT-style license that can be found in the LICENSE file.
#ifndef MANDA_TYPEOBJECT_H
#define MANDA_TYPEOBJECT_H

#include "Object.h"
#include "Type.h"

namespace manda
{
    class TypeObject : public Object
    {
    public:
        explicit TypeObject(const Type *type);
        ~TypeObject();

        const Type *GetReferencedType() const;

    private:
        const Type *refType;
    };
}

#endif //MANDA_TYPEOBJECT_H
