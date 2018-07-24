// Copyright (c) 2018, Tobechukwu Osakwe.
//
// All rights reserved.
//
// Use of this source code is governed by an
// MIT-style license that can be found in the LICENSE file.
#ifndef MANDA_TRACKSERRORS_H
#define MANDA_TRACKSERRORS_H

#include <vector>
#include "Error.h"

namespace manda
{
    class TracksErrors
    {
    public:
        std::vector<Error *> &GetErrors();

        void AddError(Error::ErrorSeverity severity, const char *message, const SourceSpan *span);

        void AddError(Error::ErrorSeverity severity, const std::string &message, const SourceSpan *span);

        void AddError(const char *message, const SourceSpan *span);

        void AddError(const std::string &message, const SourceSpan *span);

    protected:
        std::vector<Error *> errors;
    };
}

#endif //MANDA_TRACKSERRORS_H
