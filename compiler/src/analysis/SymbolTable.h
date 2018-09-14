// Copyright (c) 2018, Tobechukwu Osakwe.
//
// All rights reserved.
//
// Use of this source code is governed by an
// MIT-style license that can be found in the LICENSE file.
#ifndef PROJECT_SYMBOLTABLE_H
#define PROJECT_SYMBOLTABLE_H

#include "MandaObjectOrType.h"

namespace manda
{
    class SymbolTable
    {
    public:
        void Assign(std::string name, const MandaObject* value);

        void Assign(std::string name, MandaType *value);

    private:
        void Assign(std::string name, MandaObjectOrType value);
    };
}

#endif //PROJECT_SYMBOLTABLE_H
