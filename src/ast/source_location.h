// Copyright (c) 2018, Tobechukwu Osakwe.
//
// All rights reserved.
//
// Use of this source code is governed by an
// MIT-style license that can be found in the LICENSE file.
#ifndef PROJECT_SOURCE_LOCATION_H
#define PROJECT_SOURCE_LOCATION_H

#include <cstdint>
#include <string>

namespace manda
{
    struct SourceLocation
    {
        uint64_t line;
        uint64_t column;
        std::string sourceUrl;
    };
}

#endif //PROJECT_SOURCE_LOCATION_H
