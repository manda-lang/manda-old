// Copyright (c) 2018, Tobechukwu Osakwe.
//
// All rights reserved.
//
// Use of this source code is governed by an
// MIT-style license that can be found in the LICENSE file.
#include "Function.h"
using namespace manda;

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

const char *Function::GetName() const {
    if (name.empty()) {
        return "(anonymous)";
    } else {
        return name.c_str();
    }
}

void Function::SetName(const std::string &name) {
    this->name.clear();
    this->name += name;
}

manda::Block *manda::Function::GetStartBlock() const {
    std::string start("start");
    return GetBlock(start);
}

void manda::Function::SetStartBlock(manda::Block *block) {
    std::string start("start");
    PutBlock(start, block);
}

void manda::Function::PutBlock(std::string &name, manda::Block *block) {
    blocks.insert(std::make_pair(name, block));
}

const std::unordered_map<std::string, Block *> &manda::Function::GetBlocks() const {
    return blocks;
}
