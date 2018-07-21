// Copyright (c) 2018, Tobechukwu Osakwe.
//
// All rights reserved.
//
// Use of this source code is governed by an
// MIT-style license that can be found in the LICENSE file.
#ifndef MANDA_MANDA_H
#define MANDA_MANDA_H

#include "memory.h"
#include "struct.h"

/**
 * Create a Manda runtime environment, and execute a program.
 * @param options The options which should be used to configure the created runtime.
 * @return
 */
int manda_run(manda_options_t options);

#endif //MANDA_MANDA_H
