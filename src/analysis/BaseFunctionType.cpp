// Copyright (c) 2018, Tobechukwu Osakwe.
//
// All rights reserved.
//
// Use of this source code is governed by an
// MIT-style license that can be found in the LICENSE file.
#include "BaseFunctionType.h"

const manda::Module *manda::BaseFunctionType::GetModule() const {
    return module;
}

std::string manda::BaseFunctionType::GetName() const {
    return std::string("Function");
}

const manda::Type *manda::BaseFunctionType::GetParent() const {
    return nullptr;
}

manda::BaseFunctionType::BaseFunctionType(manda::Module *module) {
    this->module = module;
}