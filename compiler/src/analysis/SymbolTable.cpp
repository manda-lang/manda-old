// Copyright (c) 2018, Tobechukwu Osakwe.
//
// All rights reserved.
//
// Use of this source code is governed by an
// MIT-style license that can be found in the LICENSE file.
#include "SymbolTable.h"

void manda::SymbolTable::Assign(std::string name, manda::MandaObject value) {
    Assign(name, manda::MandaObjectOrType(value));
}

void manda::SymbolTable::Assign(std::string name, manda::MandaType *value) {
    Assign(name, manda::MandaObjectOrType(value));
}

void manda::SymbolTable::Assign(std::string name, manda::MandaObjectOrType value) {

}
