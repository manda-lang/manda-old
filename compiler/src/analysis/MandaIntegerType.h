// Copyright (c) 2018, Tobechukwu Osakwe.
//
// All rights reserved.
//
// Use of this source code is governed by an
// MIT-style license that can be found in the LICENSE file.
#ifndef PROJECT_MANDAINTEGERTYPE_H
#define PROJECT_MANDAINTEGERTYPE_H

#include "MandaType.h"

namespace manda
{
    class MandaIntegerType : public MandaType
    {
    public:
        MandaIntegerType(std::string simpleName, uint64_t size, bool isUnsigned = false);

        const std::string GetQualifiedName() const override;

        const std::string GetSimpleName() const override;

        uint64_t GetSizeInBytes() const override;

        bool IsUnsigned() const;

        const MandaObjectOrType *PerformBinaryOperation(const manda::MandaObject *left, const manda::MandaObject *right,
                                                        const std::string &op) const override;

        bool IsAssignableTo(const MandaType *other) const override;

        bool IsExactly(const MandaType *other) const override;

    private:
        const std::string simpleName;
        const uint64_t sizeInBytes;
        bool isUnsigned;
    };
}

#endif //PROJECT_MANDAINTEGERTYPE_H
