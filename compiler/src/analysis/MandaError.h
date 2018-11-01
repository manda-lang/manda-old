// Copyright (c) 2018, Tobechukwu Osakwe.
//
// All rights reserved.
//
// Use of this source code is governed by an
// MIT-style license that can be found in the LICENSE file.
#ifndef PROJECT_MANDAERROR_H
#define PROJECT_MANDAERROR_H

#include <string>
#include "SourceSpan.h"

namespace manda
{
    struct MandaError
    {
        enum MandaErrorSeverity
        {
            kError,
            kWarning,
            kInfo,
            kHint
        };

        MandaErrorSeverity severity;
        const std::string message;
        const SourceSpan &sourceSpan;

        const std::string& toString() const;

        MandaError(MandaErrorSeverity severity, const std::string &message, const SourceSpan &sourceSpan);
    };
}

#endif //PROJECT_MANDAERROR_H
