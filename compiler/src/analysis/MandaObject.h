// Copyright (c) 2018, Tobechukwu Osakwe.
//
// All rights reserved.
//
// Use of this source code is governed by an
// MIT-style license that can be found in the LICENSE file.
#ifndef PROJECT_MANDAOBJECT_H
#define PROJECT_MANDAOBJECT_H

#include "MandaType.h"
#include "SourceSpan.h"

namespace manda
{
    class MandaObject
    {
    public:
        explicit MandaObject(const MandaType *type, SourceSpan sourceSpan);

        ~MandaObject();

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

        union
        {
            uint64_t asUnsigned;
            int64_t asSigned;
            const char *asString;
            bool asBool;
        } constantValue;

    private:
        const MandaType *type;
        const SourceSpan sourceSpan;
    };
}

#endif //PROJECT_MANDAOBJECT_H
