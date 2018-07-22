// Copyright (c) 2018, Tobechukwu Osakwe.
//
// All rights reserved.
//
// Use of this source code is governed by an
// MIT-style license that can be found in the LICENSE file.
#include <iostream>
#include "SymbolTable.h"

manda::SymbolTable::SymbolTable() = default;

manda::SymbolTable::~SymbolTable() {
    for (auto *symbol : symbols) {
        delete symbol;
    }
}

bool manda::SymbolTable::Add(const std::string &name, manda::Object *value) {
    for (auto *symbol : symbols) {
        if (symbol->name == name) {
            return false;
        }
    }

    std::cout << "alloc " << name << std::endl;
    auto *symbol = new Symbol;
    symbol->name += name;
    symbol->value = value;
    symbols.push_back(symbol);
    std::cout << "made " << symbol->name << std::endl;
    return true;
}

manda::Symbol *manda::SymbolTable::Resolve(const std::string &name) {
    for (auto symbol : symbols) {
        std::cout << symbol->name << " vs. " << name << std::endl;
        if (symbol->name == name) {
            return symbol;
        }
    }

    if (parent == nullptr) {
        return nullptr;
    } else {
        return parent->Resolve(name);
    }
}

manda::SymbolTable::SymbolTable(manda::SymbolTable *parent) {
    this->parent = parent;
}

manda::SymbolTable *manda::SymbolTable::CreateChild() {
    return new SymbolTable(this);
}
