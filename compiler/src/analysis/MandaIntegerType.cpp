// Copyright (c) 2018, Tobechukwu Osakwe.
//
// All rights reserved.
//
// Use of this source code is governed by an
// MIT-style license that can be found in the LICENSE file.
#include <sstream>
#include <utility>
#include "MandaBinaryObject.h"
#include "MandaCoreTypes.h"
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

manda::MandaObjectOrType &
manda::MandaIntegerType::PerformBinaryOperation(const MandaObject &left, const MandaObject &right,
                                                const std::string &op, const SourceSpan &sourceSpan) const {
    // The analyzer has already asserted that the left is a number.
    // We want to determine if both items are constant, and if so, fold them.
    if (left->constantValueType != MandaObject::kNone && right->constantValueType != MandaObject::kNone) {
        auto l = left->constantValue, r = right->constantValue;

        // Create a combined, constant value.
        auto *combined = new MandaObject(this, sourceSpan);
        combined->constantValueType = left->constantValueType;

        // TODO: Perform these on floats
        if (left->constantValueType == MandaObject::kSigned) {
            if (op == "*") {
                combined->constantValue.asSigned = l.asSigned * r.asSigned;
            } else if (op == "/") {
                combined->constantValue.asSigned = l.asSigned / r.asSigned;
            } else if (op == "%") {
                combined->constantValue.asSigned = l.asSigned % r.asSigned;
            } else if (op == "+") {
                combined->constantValue.asSigned = l.asSigned + r.asSigned;
            } else if (op == "-") {
                combined->constantValue.asSigned = l.asSigned - r.asSigned;
            } else if (op == "==") {
                combined->constantValueType = MandaObject::kBool;
                combined->constantValue.asBool = l.asSigned == r.asSigned;
            } else if (op == "!=") {
                combined->constantValueType = MandaObject::kBool;
                combined->constantValue.asBool = l.asSigned != r.asSigned;
            } else if (op == "<") {
                combined->constantValueType = MandaObject::kBool;
                combined->constantValue.asBool = l.asSigned < r.asSigned;
            } else if (op == "<=") {
                combined->constantValueType = MandaObject::kBool;
                combined->constantValue.asBool = l.asSigned <= r.asSigned;
            } else if (op == ">") {
                combined->constantValueType = MandaObject::kBool;
                combined->constantValue.asBool = l.asSigned > r.asSigned;
            } else if (op == ">=") {
                combined->constantValueType = MandaObject::kBool;
                combined->constantValue.asBool = l.asSigned >= r.asSigned;
            }
        } else {
            if (op == "*") {
                combined->constantValue.asUnsigned = l.asUnsigned * r.asUnsigned;
            } else if (op == "/") {
                combined->constantValue.asUnsigned = l.asUnsigned / r.asUnsigned;
            } else if (op == "%") {
                combined->constantValue.asUnsigned = l.asUnsigned % r.asUnsigned;
            } else if (op == "+") {
                combined->constantValue.asUnsigned = l.asUnsigned + r.asUnsigned;
            } else if (op == "-") {
                combined->constantValue.asUnsigned = l.asUnsigned - r.asUnsigned;
            } else if (op == "==") {
                combined->constantValueType = MandaObject::kBool;
                combined->constantValue.asBool = l.asUnsigned == r.asUnsigned;
            } else if (op == "!=") {
                combined->constantValueType = MandaObject::kBool;
                combined->constantValue.asBool = l.asUnsigned != r.asUnsigned;
            } else if (op == "<") {
                combined->constantValueType = MandaObject::kBool;
                combined->constantValue.asBool = l.asUnsigned < r.asUnsigned;
            } else if (op == "<=") {
                combined->constantValueType = MandaObject::kBool;
                combined->constantValue.asBool = l.asUnsigned <= r.asUnsigned;
            } else if (op == ">") {
                combined->constantValueType = MandaObject::kBool;
                combined->constantValue.asBool = l.asUnsigned > r.asUnsigned;
            } else if (op == ">=") {
                combined->constantValueType = MandaObject::kBool;
                combined->constantValue.asBool = l.asUnsigned >= r.asUnsigned;
            }
        }

        // Now that we've combined the values, delete the two objects, since
        // we'll never touch them again.
        delete left;
        delete right;
        return new MandaObjectOrType(combined);
    } else {
        const MandaType *outType = this;

        if (op == "==" || op == "!=" || op == "<" || op == "<=" || op == ">" || op == ">=")
            outType = MandaCoreTypes::GetInstance().GetBoolType();

        return new MandaObjectOrType(new MandaBinaryObject(left, right, op, this, sourceSpan));
    }
}

bool manda::MandaIntegerType::IsAssignableTo(const MandaType &other) const {
    return IsExactly(other);
}

bool manda::MandaIntegerType::IsExactly(const MandaType &other) const {
    auto *asIntegerType = dynamic_cast<const MandaIntegerType *>(other);

    if (asIntegerType == nullptr) {
        return false;
    }

    return asIntegerType->isUnsigned == isUnsigned
           && asIntegerType->sizeInBytes == sizeInBytes;
}
