// Copyright (c) 2018, Tobechukwu Osakwe.
//
// All rights reserved.
//
// Use of this source code is governed by an
// MIT-style license that can be found in the LICENSE file.
#include "VM.h"

using namespace manda;

manda::Fiber *manda::VM::CreateFiber(manda::Function *function) {
    auto *fiber = new Fiber(function);
    fibers.push_back(fiber);
    return fiber;
}

const std::vector<Fiber *> &manda::VM::GetFibers() const {
    return fibers;
}

void VM::ClearFibers() {
    for (auto *fiber : fibers) {
        delete fiber;
    }

    fibers.clear();
}
