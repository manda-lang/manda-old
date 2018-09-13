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

    private:
        const std::string simpleName;
        const uint64_t sizeInBytes;
        bool isUnsigned;
    };
}

#endif //PROJECT_MANDAINTEGERTYPE_H
