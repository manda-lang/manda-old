// Copyright (c) 2018, Tobechukwu Osakwe.
//
// All rights reserved.
//
// Use of this source code is governed by an
// MIT-style license that can be found in the LICENSE file.
#include "Fiber.h"

using namespace manda;

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
    return false;
}

manda::Fiber::Fiber() {
    scope = new SymbolTable<double>;
}
