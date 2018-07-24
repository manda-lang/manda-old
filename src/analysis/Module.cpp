// Copyright (c) 2018, Tobechukwu Osakwe.
//
// All rights reserved.
//
// Use of this source code is governed by an
// MIT-style license that can be found in the LICENSE file.
#include "Module.h"

using namespace manda;

manda::Module::Module(SymbolTable<Object *> *scope) {
    this->scope = scope;
    implicitFunction = nullptr;
}

std::vector<Function *> &manda::Module::GetFunctions() {
    return functions;
}

Module::~Module() {
    for (auto *function : functions) {
        delete function;
    }

    functions.clear();
    delete implicitFunction;
}

Function *Module::GetImplicitFunction() {
    return implicitFunction;
}

void Module::SetImplicitFunction(Function *function) {
    implicitFunction = function;
}

SymbolTable<Object *> *Module::GetScope() {
    return scope;
}
