// Copyright (c) 2018, Tobechukwu Osakwe.
//
// All rights reserved.
//
// Use of this source code is governed by an
// MIT-style license that can be found in the LICENSE file.
#include "NumType.h"

const manda::Module *manda::NumType::GetModule() const {
    return module;
}

const std::string &manda::NumType::GetName() const {
    return std::string("Num");
}

const manda::Type *manda::NumType::GetParent() const {
    return nullptr;
}

manda::NumType::NumType(manda::Module *module) {
    this->module = module;
}
