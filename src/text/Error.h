// Copyright (c) 2018, Tobechukwu Osakwe.
//
// All rights reserved.
//
// Use of this source code is governed by an
// MIT-style license that can be found in the LICENSE file.
#ifndef MANDA_ERROR_H
#define MANDA_ERROR_H

#include <string>
#include "SourceSpan.h"

namespace manda
{
    enum ErrorSeverity
    {
        SEVERITY_ERROR, SEVERITY_WARNING, SEVERITY_INFO, SEVERITY_HINT
    };

    typedef struct
    {
        ErrorSeverity severity;
        std::string message;
        SourceSpan span;
    } Error;
}

#endif //MANDA_ERROR_H
