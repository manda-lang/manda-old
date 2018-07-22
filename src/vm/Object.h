// Copyright (c) 2018, Tobechukwu Osakwe.
//
// All rights reserved.
//
// Use of this source code is governed by an
// MIT-style license that can be found in the LICENSE file.
#ifndef MANDA_OBJECT_H
#define MANDA_OBJECT_H

#include <ostream>
#include "Type.h"

namespace manda
{
    class Object
    {
    public:
        enum ObjectType
        {
            NUMBER,
            CUSTOM
        };

        virtual ObjectType get_primitive_type() = 0;

        virtual const char *ansiColor() = 0;

        virtual void toString(std::ostream &out) = 0;
    };
}


#endif //MANDA_OBJECT_H
