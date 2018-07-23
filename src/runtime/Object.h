// Copyright (c) 2018, Tobechukwu Osakwe.
//
// All rights reserved.
//
// Use of this source code is governed by an
// MIT-style license that can be found in the LICENSE file.
#ifndef MANDA_OBJECT_H
#define MANDA_OBJECT_H

#include <cstdint>

namespace manda
{
    class Object
    {
    public:
        enum ObjectType : uint8_t
        {
            INTEGER = 0x0,
            POINTER = 0x1,
        };

    public:
        explicit Object();

        explicit Object(uint64_t raw);

        explicit Object(double raw);

        uint64_t GetData() const;

        ObjectType GetType() const;

        double GetRawDouble() const;

        uint64_t GetRawUlong() const;

        void SetData(uint64_t data);

        void SetType(ObjectType type);

        float GetFloatData() const;

        void SetFloatData(float data);

    private:
        union
        {
            uint64_t asUlong;
            double asDouble;
        };
    };
}


#endif //MANDA_OBJECT_H
