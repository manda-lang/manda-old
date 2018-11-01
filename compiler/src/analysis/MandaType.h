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
        virtual const std::string qualifiedName() const = 0;

        virtual const std::string simpleName() const = 0;

        virtual uint64_t sizeInBytes() const = 0;

        virtual MandaObjectOrType &binaryOperation(const MandaObject &left,
                                                   const MandaObject &right,
                                                   const std::string &op,
                                                   const manda::SourceSpan &sourceSpan) const = 0;

        virtual bool isAssignableTo(const MandaType &other) const = 0;

        virtual bool isExactly(const MandaType &other) const = 0;
    };
}

#endif //PROJECT_MANDATYPE_H
