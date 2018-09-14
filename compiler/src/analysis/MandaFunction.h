// Copyright (c) 2018, Tobechukwu Osakwe.
//
// All rights reserved.
//
// Use of this source code is governed by an
// MIT-style license that can be found in the LICENSE file.
#ifndef PROJECT_MANDAFUNCTION_H
#define PROJECT_MANDAFUNCTION_H

#include <vector>
#include "../cfg/cfg.h"
#include "MandaFunctionParameter.h"
#include "MandaObject.h"

namespace manda
{
    class MandaFunction : public MandaObject
    {
    public:
        explicit MandaFunction(const MandaType *returnType, const SourceSpan &sourceSpan);

        ~MandaFunction();

        const MandaType *GetReturnType() const;

        const std::vector<MandaFunctionParameter *> &GetParameters() const;

        void AddParameter(MandaFunctionParameter *parameter);

    private:
        std::vector<MandaFunctionParameter *> parameters;
        const MandaType *returnType;
    };
}

#endif //PROJECT_MANDAFUNCTION_H
