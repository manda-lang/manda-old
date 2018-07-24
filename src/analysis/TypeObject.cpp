// Copyright (c) 2018, Tobechukwu Osakwe.
//
// All rights reserved.
//
// Use of this source code is governed by an
// MIT-style license that can be found in the LICENSE file.
#include "TypeObject.h"

manda::TypeObject::TypeObject(const manda::Type *type) {
    this->refType = type;
}

const manda::Type *manda::TypeObject::GetReferencedType() const {
    return refType;
}

manda::TypeObject::~TypeObject() {
    delete refType;
}
