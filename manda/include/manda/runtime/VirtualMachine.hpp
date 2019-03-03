// Copyright (c) 2019, Tobechukwu Osakwe.
//
// All rights reserved.
//
// Use of this source code is governed by a
// license that can be found in the LICENSE file.
#ifndef MANDA_VIRTUALMACHINE_HPP
#define MANDA_VIRTUALMACHINE_HPP

#include <memory>
#include <vector>
#include "Thread.hpp"

namespace manda
{
    namespace runtime
    {
        class VirtualMachine
        {
        public:
            std::unique_ptr<Thread> &spawnThread();

        private:
            std::vector<std::unique_ptr<Thread>> threads;
        };
    }
}

#endif //MANDA_VIRTUALMACHINE_HPP
