// Copyright (c) 2018, Tobechukwu Osakwe.
//
// All rights reserved.
//
// Use of this source code is governed by an
// MIT-style license that can be found in the LICENSE file.
#include <sstream>
#include <utility>
#include "MandaIntegerType.h"
#include "MandaObject.h"

manda::MandaIntegerType::MandaIntegerType(std::string simpleName, uint64_t size, bool isUnsigned)
        : simpleName(std::move(simpleName)), sizeInBytes(size) {
    this->isUnsigned = isUnsigned;
}

const std::string manda::MandaIntegerType::GetQualifiedName() const {
    std::ostringstream oss;
    oss << "Manda::" << simpleName;
    return oss.str();
}

const std::string manda::MandaIntegerType::GetSimpleName() const {
    return simpleName;
}

uint64_t manda::MandaIntegerType::GetSizeInBytes() const {
    return sizeInBytes;
}

bool manda::MandaIntegerType::IsUnsigned() const {
    return isUnsigned;
}

manda::MandaObjectOrType *
manda::MandaIntegerType::PerformBinaryOperation(const manda::MandaObject *left, const manda::MandaObject *right,
                                                const std::string &op, const SourceSpan &sourceSpan) const {
    // The analyzer has already asserted that the left is a number.
    // We want to determine if both items are constant, and if so, fold them.
    if (left->constantValueType != MandaObject::kNone && right->constantValueType != MandaObject::kNone) {
        auto l = left->constantValue, r = right->constantValue;

        // Create a combined, constant value.
        auto *combined = new MandaObject(this, sourceSpan);
        combined->constantValueType = left->constantValueType;

        // TODO: Actually do operations.
        if (left->constantValueType == MandaObject::kSigned) {
            combined->constantValue.asSigned = l.asSigned + r.asSigned;
        } else {
            combined->constantValue.asUnsigned = l.asUnsigned + r.asUnsigned;
        }

        // Now that we've combined the values, delete the two objects, since
        // we'll never touch them again.
        delete left;
        delete right;
        return new MandaObjectOrType(combined);
    } else {
        return nullptr;
    }
}

bool manda::MandaIntegerType::IsAssignableTo(const manda::MandaType *other) const {
    return IsExactly(other);
}

bool manda::MandaIntegerType::IsExactly(const manda::MandaType *other) const {
    auto *asIntegerType = dynamic_cast<const MandaIntegerType *>(other);

    if (asIntegerType == nullptr) {
        return false;
    }

    return asIntegerType->isUnsigned == isUnsigned
           && asIntegerType->sizeInBytes == sizeInBytes;
}
