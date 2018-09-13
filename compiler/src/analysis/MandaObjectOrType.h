// Copyright (c) 2018, Tobechukwu Osakwe.
//
// All rights reserved.
//
// Use of this source code is governed by an
// MIT-style license that can be found in the LICENSE file.
#ifndef PROJECT_MANDAOBJECTORTYPE_H
#define PROJECT_MANDAOBJECTORTYPE_H

#include "MandaObject.h"
#include "MandaType.h"

namespace manda
{
    class MandaObjectOrType
    {
    public:
        explicit MandaObjectOrType(manda::MandaObject value);

        explicit MandaObjectOrType(manda::MandaType *value);

        const MandaObject AsObject() const;

        const MandaType *AsType() const;

        bool IsType() const;

    private:
        manda::MandaObject asObject;
        manda::MandaType *asType;
    };
}

#endif //PROJECT_MANDAOBJECTORTYPE_H
