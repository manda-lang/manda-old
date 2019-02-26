// Copyright (c) 2019, Tobechukwu Osakwe.
//
// All rights reserved.
//
// Use of this source code is governed by a
// license that can be found in the LICENSE file.
#ifndef MANDA_NODE_HPP
#define MANDA_NODE_HPP

namespace manda
{
    namespace bytecode
    {
        template<typename T>
        class BytecodeVisitor;

        class Node
        {
        public:
            template<typename T>
            virtual T accept(BytecodeVisitor<T> &visitor) = 0;
        };
    }
}

#endif //MANDA_NODE_HPP
