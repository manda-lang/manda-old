// Copyright (c) 2018, Tobechukwu Osakwe.
//
// All rights reserved.
//
// Use of this source code is governed by an
// MIT-style license that can be found in the LICENSE file.
#include <sstream>
#include "MandaIntegerType.h"

manda::MandaIntegerType::MandaIntegerType(std::string simpleName, uint64_t size, bool isUnsigned)
        : simpleName(simpleName), sizeInBytes(size) {
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

const manda::MandaObjectOrType *
manda::MandaIntegerType::PerformBinaryOperation(const manda::MandaObject *left, const manda::MandaObject *right,
                                                const std::string &op) const {
    return nullptr;
}

bool manda::MandaIntegerType::IsAssignableTo(const manda::MandaType *other) const {
    return IsExactly(other);
}

bool manda::MandaIntegerType::IsExactly(const manda::MandaType *other) const {
    auto *asIntegerType = dynamic_cast<MandaIntegerType *>(other);

    if (asIntegerType == nullptr) {
        return false;
    }

    return asIntegerType->isUnsigned == isUnsigned
           && asIntegerType->sizeInBytes == sizeInBytes;
}
