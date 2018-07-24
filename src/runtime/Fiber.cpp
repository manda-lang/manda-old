// Copyright (c) 2018, Tobechukwu Osakwe.
//
// All rights reserved.
//
// Use of this source code is governed by an
// MIT-style license that can be found in the LICENSE file.
#include "Fiber.h"

using namespace manda;

Fiber::Fiber(Function *function) {
    this->function = function;
    scope = new SymbolTable<double>;
}

const Function *Fiber::GetFunction() const {
    return function;
}

manda::SymbolTable<double> *manda::Fiber::GetScope() const {
    return scope;
}

void manda::Fiber::PushScope() {
    auto *child = scope->CreateChild();
    scope = child;
}

void manda::Fiber::PopScope() {
    if (!scope->IsRoot()) {
        // TODO: Deref variables?
        scope = scope->GetParent();
    }
}

bool manda::Fiber::HasExited() const {
    return exited;
}

bool Fiber::IsWaiting() const {
    return waiting;
}

void Fiber::Exit() {
    exited = true;
    waiting = false;
}

void Fiber::Resume(double result) {
    waiting = false;
    // TODO:
}

void Fiber::WaitFor(void *task) {
    // TODO: Change this to a task pointer, etc.
    waiting = true;
}
