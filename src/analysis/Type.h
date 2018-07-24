// Copyright (c) 2018, Tobechukwu Osakwe.
//
// All rights reserved.
//
// Use of this source code is governed by an
// MIT-style license that can be found in the LICENSE file.
#ifndef MANDA_TYPE_H
#define MANDA_TYPE_H

#include <string>
#include "Module.h"

namespace manda
{
    class Module;

    class Type
    {
    public:
        virtual const Module *GetModule() const = 0;

        virtual ~Type();

        virtual std::string GetName() const = 0;

        virtual const Type* GetParent() const = 0;

        virtual std::string GetQualifiedName() const;

        virtual bool IsExactly(const Type* other) const;
    };
}

#endif //MANDA_TYPE_H
