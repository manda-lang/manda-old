// Copyright (c) 2018, Tobechukwu Osakwe.
//
// All rights reserved.
//
// Use of this source code is governed by an
// MIT-style license that can be found in the LICENSE file.
#ifndef PROJECT_MANDATYPE_H
#define PROJECT_MANDATYPE_H

#include <cstdint>
#include <string>
#include "MandaObjectOrType.h"
#include "MandaObject.h"
#include "SourceSpan.h"

namespace manda
{
    class MandaObject;

    class MandaType : public MandaObjectOrType
    {
    public:
        ~MandaType() override;

    public:
        virtual const std::string GetQualifiedName() const = 0;

        virtual const std::string GetSimpleName() const = 0;

        virtual uint64_t GetSizeInBytes() const = 0;

        virtual MandaObjectOrType &PerformBinaryOperation(const MandaObject &left,
                                                          const MandaObject &right,
                                                          const std::string &op,
                                                          const manda::SourceSpan &sourceSpan) const = 0;

        virtual bool IsAssignableTo(const MandaType &other) const = 0;

        virtual bool IsExactly(const MandaType &other) const = 0;
    };
}

#endif //PROJECT_MANDATYPE_H
