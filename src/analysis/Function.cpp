// Copyright (c) 2018, Tobechukwu Osakwe.
//
// All rights reserved.
//
// Use of this source code is governed by an
// MIT-style license that can be found in the LICENSE file.
#include "Function.h"

manda::Function::Function() = default;

manda::Function::~Function() {
    for (auto &pair : blocks) {
        delete pair.second;
    }

    blocks.clear();
}

bool manda::Function::HasBlock(std::string &name) const {
    return blocks.find(name) != blocks.end();
}

manda::Block *manda::Function::GetBlock(std::string &name) const {
    return blocks.at(name);
}

manda::Block *manda::Function::GetStartBlock() const {
    std::string start("start");
    return GetBlock(start);
}

void manda::Function::PutBlock(std::string &name, manda::Block *block) {
    blocks.insert(std::make_pair(name, block));
}
