// Copyright (c) 2018, Tobechukwu Osakwe.
//
// All rights reserved.
//
// Use of this source code is governed by an
// MIT-style license that can be found in the LICENSE file.
#include "Reference.h"

manda::Reference::Reference(const std::string &name, const Type *type, const SourceSpan *sourceSpan) {
    this->name += name;
    this->type = type;
    this->sourceSpan = sourceSpan;
}

const std::string &manda::Reference::GetName() const {
    return name;
}

bool manda::Reference::IsReference() const {
    return true;
}
