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
        SymbolTable();

        ~SymbolTable();

        bool Add(const std::string &name, Object *value);

        bool IsRoot() const;

        SymbolTable *GetParent() const;

        SymbolTable *CreateChild() const;

        Symbol *Resolve(const std::string &name) const;

    private:
        explicit SymbolTable(SymbolTable *parent);

        SymbolTable *parent;
        std::vector<Symbol *> symbols;
    };
}

#endif //MANDA_SYMBOLTABLE_H
