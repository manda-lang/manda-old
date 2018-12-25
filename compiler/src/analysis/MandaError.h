// Copyright (c) 2018, Tobechukwu Osakwe.
//
// All rights reserved.
//
// Use of this source code is governed by an
// MIT-style license that can be found in the LICENSE file.
#ifndef PROJECT_MANDAERROR_H
#define PROJECT_MANDAERROR_H

#include <exception>
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

        const std::string &toString() const;

        MandaError(MandaErrorSeverity severity, const std::string &message, const SourceSpan &sourceSpan);
    };

    class MandaException : public std::exception
    {
    public:
        explicit MandaException(const MandaError &error);

        const MandaError &error;

        const char *what() const override;
    };
}

#endif //PROJECT_MANDAERROR_H
