// Copyright (c) 2018, Tobechukwu Osakwe.
//
// All rights reserved.
//
// Use of this source code is governed by an
// MIT-style license that can be found in the LICENSE file.
#ifndef PROJECT_MANDAOBJECT_H
#define PROJECT_MANDAOBJECT_H

#include "MandaType.h"

namespace manda
{
    class MandaObject
    {
    public:
        const MandaType& GetType() const;
    };
}

#endif //PROJECT_MANDAOBJECT_H
