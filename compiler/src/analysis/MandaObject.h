// Copyright (c) 2018, Tobechukwu Osakwe.
//
// All rights reserved.
//
// Use of this source code is governed by an
// MIT-style license that can be found in the LICENSE file.
#ifndef PROJECT_MANDAOBJECT_H
#define PROJECT_MANDAOBJECT_H

#include <jit/jit.h>
#include "MandaType.h"
#include "SourceSpan.h"

namespace manda
{
    class MandaType;

    class JITInterpreter;

    typedef union
    {
        uint64_t asUnsigned;
        int64_t asSigned;
        const char *asString;
        bool asBool;
    } MandaConstantValue;

    class MandaObject
    {
    public:
        explicit MandaObject(const MandaType *type, SourceSpan sourceSpan);

        ~MandaObject();

        virtual jit_value_t Accept(JITInterpreter &interpreter) const = 0;

        const MandaType *GetType() const;

        enum ConstantValueType
        {
            kNone,
            kUnsigned,
            kSigned,
            kString,
            kBool
        };

        ConstantValueType constantValueType;

        MandaConstantValue constantValue;

    private:
        const MandaType *type;
        const SourceSpan sourceSpan;
    };
}

#endif //PROJECT_MANDAOBJECT_H
