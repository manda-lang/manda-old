// Copyright (c) 2018, Tobechukwu Osakwe.
//
// All rights reserved.
//
// Use of this source code is governed by an
// MIT-style license that can be found in the LICENSE file.
#ifndef PROJECT_MANDABOOLTYPE_H
#define PROJECT_MANDABOOLTYPE_H

#include "MandaType.h"

namespace manda
{
    class MandaBoolType : public MandaType
    {
    public:
        const std::string GetQualifiedName() const override;

        const std::string GetSimpleName() const override;

        bool IsAssignableTo(const MandaType &other) const override;

        bool IsExactly(const MandaType &other) const override;

        uint64_t GetSizeInBytes() const override;

        MandaObjectOrType &
        PerformBinaryOperation(const MandaObject &left, const MandaObject &right, const std::string &op,
                               const manda::SourceSpan &sourceSpan) const override;
    };
}

#endif //PROJECT_MANDABOOLTYPE_H
