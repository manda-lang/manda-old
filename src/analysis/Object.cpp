// Copyright (c) 2018, Tobechukwu Osakwe.
//
// All rights reserved.
//
// Use of this source code is governed by an
// MIT-style license that can be found in the LICENSE file.
#include "Object.h"

using namespace manda;

manda::Object::Object(manda::Type *type, manda::SourceSpan *span) {
    this->type = type;
    this->sourceSpan = new SourceSpan(span);
}

Object::Object() = default;

manda::Object::~Object() {
    delete sourceSpan;
}

const manda::Type *manda::Object::GetType() const {
    return type;
}

const manda::SourceSpan *manda::Object::GetSourceSpan() const {
    return sourceSpan;
}
