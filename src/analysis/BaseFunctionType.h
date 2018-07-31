// Copyright (c) 2018, Tobechukwu Osakwe.
//
// All rights reserved.
//
// Use of this source code is governed by an
// MIT-style license that can be found in the LICENSE file.
#ifndef MANDA_BASEFUNCTIONTYPE_H
#define MANDA_BASEFUNCTIONTYPE_H

#include "Module.h"
#include "Type.h"

namespace manda
{
    class BaseFunctionType : public Type
    {
    public:
        explicit BaseFunctionType(Module *module);

        const Module *GetModule() const override;

        std::string GetName() const override;

        const Type *GetParent() const override;

    private:
        Module *module;
    };
}

#endif //MANDA_BASEFUNCTIONTYPE_H
