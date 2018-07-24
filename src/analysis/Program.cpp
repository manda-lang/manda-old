// Copyright (c) 2018, Tobechukwu Osakwe.
//
// All rights reserved.
//
// Use of this source code is governed by an
// MIT-style license that can be found in the LICENSE file.
#include "Program.h"
using namespace manda;

manda::Program::Program() {
    mainModule = nullptr;
}

manda::Program::~Program() {
    for (auto &pair : modules) {
        delete pair.second;
    }

    modules.clear();
}

std::unordered_map<std::string, Module *> &manda::Program::GetModules() {
    return modules;
}

Module *Program::GetMainModule() {
    mainModule;
}

void Program::SetMainModule(Module *module) {
    mainModule = module;
}
