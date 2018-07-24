// Copyright (c) 2018, Tobechukwu Osakwe.
//
// All rights reserved.
//
// Use of this source code is governed by an
// MIT-style license that can be found in the LICENSE file.
#ifndef MANDA_NUMTYPE_H
#define MANDA_NUMTYPE_H

#include "Type.h"

namespace manda
{
    class NumType : public Type
    {
    public:
        explicit NumType(Module *module);

        const Module *GetModule() const override;

        const std::string &GetName() const override;

        const Type *GetParent() const override;

    private:
        Module *module;
    };
}

#endif //MANDA_NUMTYPE_H
