// Copyright (c) 2018, Tobechukwu Osakwe.
//
// All rights reserved.
//
// Use of this source code is governed by an
// MIT-style license that can be found in the LICENSE file.
#include "SymbolTable.h"

manda::Symbol *manda::SymbolTable::Assign(std::string name, const manda::MandaObject *value) {
    return Assign(std::move(name), new manda::MandaObjectOrType(value));
}

manda::Symbol *manda::SymbolTable::Assign(std::string name, const manda::MandaType *value) {
    return Assign(std::move(name), new manda::MandaObjectOrType(value));
}

manda::Symbol *manda::SymbolTable::Assign(std::string name, const manda::MandaObjectOrType *value) {
    for (auto *symbol : symbols) {
        if (symbol->GetName() == name) {
            return nullptr;
        }
    }

    auto *symbol = new Symbol(this, name, value);
    symbols.push_back(symbol);
    return symbol;
}

manda::SymbolTable::SymbolTable() {
    this->parent = nullptr;
}

manda::SymbolTable::~SymbolTable() {
    for (auto *symbol : symbols) {
        delete symbol;
    }
}

bool manda::SymbolTable::IsRoot() const {
    return parent == nullptr;
}

const manda::Symbol *manda::SymbolTable::Resolve(const std::string &name) const {
    for (auto *symbol : symbols) {
        if (symbol->GetName() == name) {
            return symbol;
        }
    }

    if (parent != nullptr) {
        return parent->Resolve(name);
    } else {
        return nullptr;
    }
}

manda::SymbolTable::SymbolTable(manda::SymbolTable *parent) {
    this->parent = parent;
}

const std::string &manda::Symbol::GetName() const {
    return name;
}

const manda::MandaObjectOrType *manda::Symbol::GetValue() const {
    return value;
}

manda::Symbol::Symbol(SymbolTable *symbolTable, std::string name, const manda::MandaObjectOrType *value)
        : name(std::move(name)) {
    this->symbolTable = symbolTable;
    this->value = value;
}

manda::Symbol::~Symbol() {
    delete value;
}
