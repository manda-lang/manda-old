// Copyright (c) 2018, Tobechukwu Osakwe.
//
// All rights reserved.
//
// Use of this source code is governed by an
// MIT-style license that can be found in the LICENSE file.
#ifndef PROJECT_MANDAFUNCTIONPARAMETER_H
#define PROJECT_MANDAFUNCTIONPARAMETER_H

#include <string>
#include "MandaType.h"
#include "SourceSpan.h"

namespace manda
{
    class MandaFunctionParameter
    {
    public:
        MandaFunctionParameter(std::string name, const MandaType *type, bool isProperty, SourceSpan sourceSpan);

        const std::string &GetName() const;

        bool IsProperty() const;

        const MandaType *GetType() const;

        const SourceSpan &GetSourceSpan() const;

    private:
        const std::string name;
        bool isProperty;
        const MandaType *type;
        const SourceSpan sourceSpan;
    };
}

#endif //PROJECT_MANDAFUNCTIONPARAMETER_H
