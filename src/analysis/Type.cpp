// Copyright (c) 2018, Tobechukwu Osakwe.
//
// All rights reserved.
//
// Use of this source code is governed by an
// MIT-style license that can be found in the LICENSE file.
#include <sstream>
#include "Type.h"

std::string &manda::Type::GetQualifiedName() const {
    std::ostringstream ss;

    ss << GetModule()->GetQualifiedName() << "::" << GetName();
    auto s = ss.str();
    return s;
}

bool manda::Type::IsExactly(const manda::Type *other) const {
    return other != nullptr && other->GetQualifiedName() == GetQualifiedName();
}
