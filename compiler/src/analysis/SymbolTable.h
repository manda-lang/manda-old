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

    struct Symbol
    {
        friend class SymbolTable;

    public:
        const std::string name;
        const MandaObjectOrType &value;
        const SymbolTable &symbolTable;
    private:
        Symbol(const SymbolTable &symbolTable, std::string name, const MandaObjectOrType &value);
    };

    class SymbolTable
    {
    public:
        SymbolTable();

        bool isRoot() const;

        manda::Symbol &assign(std::string name, const MandaObjectOrType &value);

        const Symbol &resolve(const std::string &name) const;

        SymbolTable &createChild() const;

    private:
        const SymbolTable *parent;
        std::vector<Symbol> symbols;

        explicit SymbolTable(const SymbolTable *parent);
    };

    class SymbolTableException : public std::exception
    {
    public:
        explicit SymbolTableException(const std::string &message);

        const char *what() const override;

        const std::string message;


    };
}

#endif //PROJECT_SYMBOLTABLE_H
