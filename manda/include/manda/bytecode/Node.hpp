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
        class BytecodeVisitor;

        class Node
        {
        public:
            virtual void accept(BytecodeVisitor &visitor) = 0;
        };
    }
}

#endif //MANDA_NODE_HPP
