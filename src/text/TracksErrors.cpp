// Copyright (c) 2018, Tobechukwu Osakwe.
//
// All rights reserved.
//
// Use of this source code is governed by an
// MIT-style license that can be found in the LICENSE file.
#include "TracksErrors.h"
using namespace manda;

std::vector<Error *> &manda::TracksErrors::GetErrors() {
    return errors;
}

void TracksErrors::AddError(Error::ErrorSeverity severity, const char *message, const SourceSpan *span) {
    std::string msg(message);
    AddError(severity, msg, span);
}

void TracksErrors::AddError(Error::ErrorSeverity severity, const std::string &message, const SourceSpan *span) {
    auto *error = new Error(severity, message, new SourceSpan(span));
    errors.push_back(error);
}

void TracksErrors::AddError(const char *message, const SourceSpan *span) {
    AddError(Error::ERROR, message, span);
}

void TracksErrors::AddError(const std::string &message, const SourceSpan *span) {
    AddError(Error::ERROR, message, span);
}