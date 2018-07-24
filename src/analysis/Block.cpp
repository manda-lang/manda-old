// Copyright (c) 2018, Tobechukwu Osakwe.
//
// All rights reserved.
//
// Use of this source code is governed by an
// MIT-style license that can be found in the LICENSE file.
#include "Block.h"

manda::Block::Block() = default;

manda::Block::~Block() {
    for (auto *instruction : instructions) {
        delete instruction;
    }

    instructions.clear();
}

std::vector<Instruction *> &manda::Block::GetInstructions() const {
    return instructions;
}
