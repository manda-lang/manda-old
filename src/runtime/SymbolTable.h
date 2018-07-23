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
    template<typename T>
    class SymbolTable
    {
    public:
        SymbolTable() = default;

        ~SymbolTable() {
            for (auto *symbol : symbols) {
                delete symbol;
            }
        }

        bool Add(const std::string &name, T *value);

        bool IsRoot() const {
            return parent == nullptr;
        }

        SymbolTable<T> *GetParent() const {
            return parent;
        }

        SymbolTable<T> *CreateChild() const {
            return new SymbolTable<T>((SymbolTable<T> *) this);
        }

        Symbol<T> *Resolve(const std::string &name) const;

    private:
        explicit SymbolTable(SymbolTable<T> *parent) {
            this->parent = parent;
        }

        SymbolTable<T> *parent;
        std::vector<Symbol<T> *> symbols;
    };
}

#endif //MANDA_SYMBOLTABLE_H
