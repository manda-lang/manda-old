// Copyright (c) 2018, Tobechukwu Osakwe.
//
// All rights reserved.
//
// Use of this source code is governed by an
// MIT-style license that can be found in the LICENSE file.
#include <iostream>
#include "SymbolTable.h"

template<typename T>
bool manda::SymbolTable<T>::Add(const std::string &name, T *value) {
    for (auto *symbol : symbols) {
        if (symbol->GetName() == name) {
            return false;
        }
    }

    std::cout << "alloc " << name << std::endl;
    auto *symbol = new Symbol<T>(name, value);
    symbols.push_back(symbol);
    std::cout << "made " << symbol->GetName() << std::endl;
    return true;
}

template<typename T>
manda::Symbol<T> *manda::SymbolTable<T>::Resolve(const std::string &name) const {
    for (auto symbol : symbols) {
        std::cout << symbol->GetName() << " vs. " << name << std::endl;
        if (symbol->GetName() == name) {
            return symbol;
        }
    }

    if (parent == nullptr) {
        return nullptr;
    } else {
        return parent->Resolve(name);
    }
}
