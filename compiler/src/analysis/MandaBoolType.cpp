// Copyright (c) 2018, Tobechukwu Osakwe.
//
// All rights reserved.
//
// Use of this source code is governed by an
// MIT-style license that can be found in the LICENSE file.
#include "MandaBinaryObject.h"
#include "MandaBoolType.h"
#include "MandaObject.h"

const std::string manda::MandaBoolType::GetQualifiedName() const {
    return "Manda::Bool";
}

const std::string manda::MandaBoolType::GetSimpleName() const {
    return "Bool";
}

bool manda::MandaBoolType::IsAssignableTo(const manda::MandaType *other) const {
    return other == this;
}

uint64_t manda::MandaBoolType::GetSizeInBytes() const {
    return 1;
}

manda::MandaObjectOrType *
manda::MandaBoolType::PerformBinaryOperation(const manda::MandaObject *left, const manda::MandaObject *right,
                                             const std::string &op, const manda::SourceSpan &sourceSpan) const {
    // TODO: Do we need XOR, NOR, etc...?
    if (op == "==" || op == "!=" || op == "&&" || op == "||") {
        // See if we can fold this as a constant.
        if (left->constantValueType == MandaObject::kNone || right->constantValueType == MandaObject::kNone) {
            return new MandaObjectOrType(new MandaBinaryObject(left, right, op, this, sourceSpan));
        } else {
            auto l = left->constantValue, r = right->constantValue;

            // Create a combined, constant value.
            auto *combined = new MandaObject(this, sourceSpan);
            combined->constantValueType = left->constantValueType;

            if (op == "==")
                combined->constantValue.asBool = l.asBool == r.asBool;
            else if (op == "!=")
                combined->constantValue.asBool = l.asBool != r.asBool;
            else if (op == "&&")
                combined->constantValue.asBool = l.asBool && r.asBool;
            else if (op == "||")
                combined->constantValue.asBool = l.asBool || r.asBool;

            delete left;
            delete right;
            return new MandaObjectOrType(combined);
        }
    }

    return nullptr;
}
