// Copyright (c) 2018, Tobechukwu Osakwe.
//
// All rights reserved.
//
// Use of this source code is governed by an
// MIT-style license that can be found in the LICENSE file.
#include <sstream>
#include "MandaError.h"

manda::MandaError::MandaError(manda::MandaError::MandaErrorSeverity severity, const std::string &message,
                              const SourceSpan &sourceSpan)
        : message(std::move(message)),
          sourceSpan(sourceSpan),
          severity(severity) {
}

const std::string &manda::MandaError::toString() const {
    std::ostringstream oss;

    switch (severity) {
        case kError:
            oss << "error";
            break;
        case kWarning:
            oss << "warning";
            break;
        case kInfo:
            oss << "info";
            break;
        case kHint:
            oss << "hint";
            break;
    }

    oss << ": " << sourceSpan.GetLine() << ":" << sourceSpan.GetCharPositionInLine();
    oss << ": " << message;

    return oss.str();
}

manda::MandaException::MandaException(const manda::MandaError &error)
        : error(error) {}

const char *manda::MandaException::what() const {
    return error.message.c_str();
}
