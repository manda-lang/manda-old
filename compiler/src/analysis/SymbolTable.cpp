// Copyright (c) 2018, Tobechukwu Osakwe.
//
// All rights reserved.
//
// Use of this source code is governed by an
// MIT-style license that can be found in the LICENSE file.
#include <sstream>
#include "SymbolTable.h"

manda::Symbol &manda::SymbolTable::assign(std::string name, const MandaObjectOrType &value) {
    for (auto symbol : symbols) {
        if (symbol.name == name) {
            std::ostringstream oss;
            oss << "The symbol \"" << name << "\" is already defined.";
            throw SymbolTableException(oss.str());
        }
    }

    Symbol symbol(*this, name, value);
    symbols.push_back(symbol);
    return symbol;
}

manda::SymbolTable::SymbolTable() {
    this->parent = nullptr;
}

bool manda::SymbolTable::isRoot() const {
    return parent == nullptr;
}

const manda::Symbol &manda::SymbolTable::resolve(const std::string &name) const {
    for (auto &symbol : symbols) {
        if (symbol.name == name) {
            return symbol;
        }
    }

    if (parent != nullptr) {
        return parent->resolve(name);
    } else {
        std::ostringstream message;
        message << "The name \"" << name << "\" does not exist in the current context.";
        throw SymbolTableException(message.str());
    }
}

manda::SymbolTable::SymbolTable(const manda::SymbolTable *parent) {
    this->parent = parent;
}

manda::SymbolTable &manda::SymbolTable::createChild() const {
    SymbolTable child(this);
    return child;
}

manda::Symbol::Symbol(const SymbolTable &symbolTable, std::string name, const manda::MandaObjectOrType &value)
        : name(std::move(name)),
          value(value),
          symbolTable(symbolTable) {}

manda::SymbolTableException::SymbolTableException(const std::string &message)
        : message(message) {}

const char *manda::SymbolTableException::what() const {
    return message.c_str();
}
