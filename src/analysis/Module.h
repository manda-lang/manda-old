// Copyright (c) 2018, Tobechukwu Osakwe.
//
// All rights reserved.
//
// Use of this source code is governed by an
// MIT-style license that can be found in the LICENSE file.
#ifndef MANDA_MODULE_H
#define MANDA_MODULE_H

#include <vector>
#include "../runtime/SymbolTable.h"
#include "Function.h"
#include "Object.h"

namespace manda
{
    class Module
    {
    public:
        explicit Module(SymbolTable<Object *> *scope);
        ~Module();

        std::vector<Function *> &GetFunctions();

    private:
        std::vector<Function *> functions;
        SymbolTable<Object *> *scope;
    };
}

#endif //MANDA_MODULE_H
