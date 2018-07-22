// Copyright (c) 2018, Tobechukwu Osakwe.
//
// All rights reserved.
//
// Use of this source code is governed by an
// MIT-style license that can be found in the LICENSE file.
#ifndef MANDA_NUMBER_H
#define MANDA_NUMBER_H

#include "Object.h"

namespace manda
{
    class Number : public Object
    {
    public:
        explicit Number(double value);
        double value;
        ObjectType get_primitive_type() override;

        const char* ansiColor() override;

        void toString(std::ostream &out) override;
    };
}


#endif //MANDA_NUMBER_H
