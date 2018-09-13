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

namespace manda
{
    class MandaType
    {
    public:
        virtual const std::string GetQualifiedName() const = 0;

        virtual const std::string GetSimpleName() const = 0;

        virtual uint64_t GetSizeInBytes() const = 0;
    };
}

#endif //PROJECT_MANDATYPE_H
