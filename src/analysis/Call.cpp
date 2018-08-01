// Copyright (c) 2018, Tobechukwu Osakwe.
//
// All rights reserved.
//
// Use of this source code is governed by an
// MIT-style license that can be found in the LICENSE file.
#include "Call.h"

using namespace manda;

manda::Call::Call(const manda::Type *type, const manda::Object *callee) {
    this->type = type;
    this->callee = callee;
}

Call::~Call() {
    for (auto *argument : arguments) {
        delete argument;
    }

    delete callee;
    callee = nullptr;
    arguments.clear();
}

const manda::Object *manda::Call::GetCallee() const {
    return callee;
}

const std::vector<const Object *> &manda::Call::GetArguments() const {
    return arguments;
}

void manda::Call::AddArgument(const manda::Object *argument) {
    arguments.push_back(argument);
}

const Type *Call::GetType() const {
    return type;
}

const SourceSpan *Call::GetSourceSpan() const {
    return callee->GetSourceSpan();
}

bool Call::IsCall() const {
    return true;
}
