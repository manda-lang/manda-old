// Copyright (c) 2018, Tobechukwu Osakwe.
//
// All rights reserved.
//
// Use of this source code is governed by an
// MIT-style license that can be found in the LICENSE file.
#include "MandaBinaryObject.h"

manda::MandaBinaryObject::MandaBinaryObject
        (const MandaObject *left,
         const MandaObject *right,
         std::string op,
         const MandaType *type,
         const SourceSpan &sourceSpan)
        : MandaObject(type, sourceSpan),
          op(std::move(op)) {
    this->left = left;
    this->right = right;
}

const manda::MandaObject *manda::MandaBinaryObject::GetLeft() const {
    return left;
}

const manda::MandaObject *manda::MandaBinaryObject::GetRight() const {
    return right;
}

const std::string &manda::MandaBinaryObject::GetOperator() const {
    return op;
}
