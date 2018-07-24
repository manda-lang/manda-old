// Copyright (c) 2018, Tobechukwu Osakwe.
//
// All rights reserved.
//
// Use of this source code is governed by an
// MIT-style license that can be found in the LICENSE file.
#include <sstream>
#include "Module.h"

using namespace manda;

manda::Module::Module(const std::string &name, SymbolTable<Object *> *scope) {
    this->name += name;
    this->scope = scope;
    implicitFunction = nullptr;
    parent = nullptr;
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

const std::string &Module::GetName() const {
    return name;
}

std::string Module::GetQualifiedName() const {
    std::ostringstream ss;

    if (parent != nullptr) {
        ss << parent->GetQualifiedName() << "::";
    }

    ss << name;
    return ss.str();
}

const Module *Module::GetParent() const {
    return parent;
}

Module::Module(const std::string &name, const Module *parent) {
    this->name += name;
    this->scope = parent->scope->CreateChild();
    implicitFunction = nullptr;
    this->parent = parent;
}

Module *Module::CreateChild(const std::string &name) const {
    return new Module(name, this);
}
