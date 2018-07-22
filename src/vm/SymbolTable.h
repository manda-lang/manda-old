// Copyright (c) 2018, Tobechukwu Osakwe.
//
// All rights reserved.
//
// Use of this source code is governed by an
// MIT-style license that can be found in the LICENSE file.
#ifndef MANDA_SYMBOLTABLE_H
#define MANDA_SYMBOLTABLE_H

#include <vector>
#include "Symbol.h"

namespace manda
{
    class SymbolTable
    {
    public:
        std::vector<Symbol *> symbols;

        SymbolTable();

        ~SymbolTable();

        bool Add(const std::string &name, Object *value);

        SymbolTable *CreateChild();

        Symbol *Resolve(const std::string &name);

    private:
        explicit SymbolTable(SymbolTable *parent);

        SymbolTable *parent;
    };
}

#endif //MANDA_SYMBOLTABLE_H
