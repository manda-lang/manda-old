// Copyright (c) 2018, Tobechukwu Osakwe.
//
// All rights reserved.
//
// Use of this source code is governed by an
// MIT-style license that can be found in the LICENSE file.
#ifndef PROJECT_SYMBOLTABLE_H
#define PROJECT_SYMBOLTABLE_H

#include <vector>
#include "MandaObjectOrType.h"

namespace manda
{
    class SymbolTable;

    class Symbol
    {
    public:
        Symbol(SymbolTable *symbolTable, std::string name, const MandaObjectOrType *value);

        const std::string &GetName() const;

        const MandaObjectOrType *GetValue() const;

    private:

        const std::string name;
        const MandaObjectOrType *value;
        SymbolTable *symbolTable;
    };

    class SymbolTable
    {
    public:
        SymbolTable();

        ~SymbolTable();

        manda::Symbol *Assign(std::string name, const MandaObject *value);

        manda::Symbol *Assign(std::string name, const MandaType *value);

        bool IsRoot() const;

        const Symbol *Resolve(const std::string &name) const;

    private:
        SymbolTable *parent;
        std::vector<Symbol *> symbols;

        explicit SymbolTable(SymbolTable *parent);

        manda::Symbol *Assign(std::string name, const MandaObjectOrType *value);
    };
}

#endif //PROJECT_SYMBOLTABLE_H
