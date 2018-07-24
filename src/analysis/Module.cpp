// Copyright (c) 2018, Tobechukwu Osakwe.
//
// All rights reserved.
//
// Use of this source code is governed by an
// MIT-style license that can be found in the LICENSE file.
#include "Module.h"

using namespace manda;

manda::Module::Module() = default;

std::vector<Function *> &manda::Module::GetFunctions() {
    return functions;
}

Module::~Module() {
    for (auto *function : functions) {
        delete function;
    }

    functions.clear();
}
