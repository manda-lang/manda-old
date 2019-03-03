// Copyright (c) 2019, Tobechukwu Osakwe.
//
// All rights reserved.
//
// Use of this source code is governed by a
// license that can be found in the LICENSE file.
#include <memory>
#include <manda/runtime/runtime.hpp>

std::unique_ptr<manda::runtime::Thread> &manda::runtime::VirtualMachine::spawnThread()
{
    auto thread = std::make_unique<manda::runtime::Thread>();
    threads.push_back(thread);
    return threads.at(threads.size() - 1);
}

