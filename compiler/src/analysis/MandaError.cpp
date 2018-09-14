// Copyright (c) 2018, Tobechukwu Osakwe.
//
// All rights reserved.
//
// Use of this source code is governed by an
// MIT-style license that can be found in the LICENSE file.
#include "MandaError.h"

manda::MandaError::MandaError(manda::MandaError::MandaErrorSeverity severity, std::string message,
                              manda::SourceSpan sourceSpan)
        : message(std::move(message)), sourceSpan(std::move(sourceSpan)) {
    this->severity = severity;
}

manda::MandaError::MandaErrorSeverity manda::MandaError::GetSeverity() const {
    return severity;
}

const std::string &manda::MandaError::GetMessage() const {
    return message;
}

const manda::SourceSpan &manda::MandaError::GetSourceSpan() const {
    return sourceSpan;
}