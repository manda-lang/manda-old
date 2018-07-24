// Copyright (c) 2018, Tobechukwu Osakwe.
//
// All rights reserved.
//
// Use of this source code is governed by an
// MIT-style license that can be found in the LICENSE file.
#include <iostream>
#include "SymbolTable.h"

template<typename T>
bool manda::SymbolTable<T>::ExistsAtThisLevel(const std::string &name) const {
    if (!symbols.empty()) {
        for (auto symbol : symbols) {
            if (symbol != nullptr && symbol->GetName() == name) {
                return true;
            }
        }
    }

    return false;
}
