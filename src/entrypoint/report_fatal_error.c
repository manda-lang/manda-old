// Copyright (c) 2018, Tobechukwu Osakwe.
//
// All rights reserved.
//
// Use of this source code is governed by an
// MIT-style license that can be found in the LICENSE file.
#include "entrypoint.h"

void reportFatalError(const char *msg) {
    fprintf(stderr, "fatal error: %s\n", msg);
}