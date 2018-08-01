// Copyright (c) 2018, Tobechukwu Osakwe.
//
// All rights reserved.
//
// Use of this source code is governed by an
// MIT-style license that can be found in the LICENSE file.
#ifndef MANDA_CALLINSTRUCTION_H
#define MANDA_CALLINSTRUCTION_H

#include "Object.h"

namespace manda
{
    class Call : public Object
    {
    public:
        explicit Call(const Type *type, const Object *callee);

        ~Call();

        const Object *GetCallee() const;

        const std::vector<const Object *> &GetArguments() const;

        void AddArgument(const Object *argument);

        const Type *GetType() const override;

        const SourceSpan *GetSourceSpan() const override;

        bool IsCall() const override;

    private:
        const Object *callee;
        std::vector<const Object *> arguments;
    };
}

#endif //MANDA_CALLINSTRUCTION_H
