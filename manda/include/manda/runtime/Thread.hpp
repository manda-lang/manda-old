// Copyright (c) 2019, Tobechukwu Osakwe.
//
// All rights reserved.
//
// Use of this source code is governed by a
// license that can be found in the LICENSE file.
#ifndef MANDA_THREAD_HPP
#define MANDA_THREAD_HPP

#include <manda/bytecode/bytecode.hpp>

namespace manda
{
    namespace runtime
    {
        class Thread
        {
        public:
            void loadKernel(bytecode::Kernel &kernel);
        };
    }
}

#endif //MANDA_THREAD_HPP
