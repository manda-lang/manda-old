// Copyright (c) 2018, Tobechukwu Osakwe.
//
// All rights reserved.
//
// Use of this source code is governed by an
// MIT-style license that can be found in the LICENSE file.
#ifndef PROJECT_MANDABINARYOBJECT_H
#define PROJECT_MANDABINARYOBJECT_H

#include <string>
#include "MandaObject.h"

namespace manda
{
    class MandaBinaryObject : public MandaObject
    {
    public:
        MandaBinaryObject(const MandaObject *left, const MandaObject *right, std::string op, const MandaType *type,
                          const SourceSpan &sourceSpan);

        const MandaObject *GetLeft() const;

        const MandaObject *GetRight() const;

        const std::string &GetOperator() const;

    private:
        const MandaObject *left, *right;
        const std::string op;
    };
}

#endif //PROJECT_MANDABINARYOBJECT_H
