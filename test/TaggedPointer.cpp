// Copyright (c) 2018, Tobechukwu Osakwe.
//
// All rights reserved.
//
// Use of this source code is governed by an
// MIT-style license that can be found in the LICENSE file.
#include <gtest/gtest.h>
#include <manda_src.h>

TEST(tagged_pointer_test, float_data) {
    manda::TaggedPointer ptr;
    ptr.SetFloatData(32.4);
    EXPECT_EQ(ptr.GetFloatData(), 32.4);
}