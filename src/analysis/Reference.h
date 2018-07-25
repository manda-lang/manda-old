// Copyright (c) 2018, Tobechukwu Osakwe.
//
// All rights reserved.
//
// Use of this source code is governed by an
// MIT-style license that can be found in the LICENSE file.
#ifndef MANDA_REFERENCEINSTRUCTION_H
#define MANDA_REFERENCEINSTRUCTION_H

#include <string>
#include "Object.h"

namespace manda
{
    class Reference : public Object
    {
    public:
        explicit Reference(const std::string &name, const Type *type, const SourceSpan *sourceSpan);

        const std::string &GetName() const;

        bool IsReference() const override;

    private:
        std::string name;
    };
}

#endif //MANDA_REFERENCEINSTRUCTION_H
