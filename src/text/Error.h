// Copyright (c) 2018, Tobechukwu Osakwe.
//
// All rights reserved.
//
// Use of this source code is governed by an
// MIT-style license that can be found in the LICENSE file.
#ifndef MANDA_ERROR_H
#define MANDA_ERROR_H

#include <sstream>
#include <string>
#include "SourceSpan.h"

namespace manda
{


    class Error
    {
    public:
        enum ErrorSeverity
        {
            ERROR, WARNING, INFO, HINT
        };

        explicit Error(ErrorSeverity severity, const std::string &message, SourceSpan *sourceSpan)
                : sourceSpan(sourceSpan) {
            this->severity = severity;
            this->message += message;
        }

        ErrorSeverity GetSeverity() const {
            return severity;
        }

        const std::string &GetMessage() const {
            return message;
        }

        const SourceSpan *GetSourceSpan() {
            return sourceSpan;
        }

        const std::string GetToolString() const {
            std::ostringstream oss;

            if (severity == ERROR) {
                oss << "error";
            } else if (severity == WARNING) {
                oss << "warning";
            } else if (severity == INFO) {
                oss << "info";
            } else if (severity == HINT) {
                oss << "hint";
            }

            oss << ": " << sourceSpan->GetToolString() << ": " << message;
            return oss.str();
        }

    private:
        ErrorSeverity severity;
        std::string message;
        SourceSpan *sourceSpan{};
    };
}

#endif //MANDA_ERROR_H
