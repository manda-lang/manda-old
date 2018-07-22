// Copyright (c) 2018, Tobechukwu Osakwe.
//
// All rights reserved.
//
// Use of this source code is governed by an
// MIT-style license that can be found in the LICENSE file.
#ifndef MANDA_MEMORY_H
#define MANDA_MEMORY_H

#include <stdlib.h>

typedef void *(*MandaAllocator)(size_t size);

typedef void (*MandaDeallocator)(void *ptr);

#endif //MANDA_MEMORY_H
