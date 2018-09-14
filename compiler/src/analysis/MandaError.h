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
    class MandaError
    {
    public:
        enum MandaErrorSeverity
        {
            kError,
            kWarning,
            kInfo,
            kHint
        };

        MandaError(MandaErrorSeverity severity, std::string message, SourceSpan sourceSpan);

        MandaErrorSeverity GetSeverity() const;

        const std::string &GetMessage() const;

        const SourceSpan &GetSourceSpan() const;

        std::string ToString() const;

    private:
        MandaErrorSeverity severity;
        const std::string message;
        const SourceSpan sourceSpan;
    };
}

#endif //PROJECT_MANDAERROR_H
