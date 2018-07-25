// Copyright (c) 2018, Tobechukwu Osakwe.
//
// All rights reserved.
//
// Use of this source code is governed by an
// MIT-style license that can be found in the LICENSE file.
#include "../manda_src.h"

manda::ObjectInstruction::ObjectInstruction(const manda::Object *object) {
    this->object = object;
}

const manda::Object *manda::ObjectInstruction::GetObject() const {
    return object;
}

manda::ObjectInstruction::~ObjectInstruction() {
    // We CAN delete the underlying object, because its result is not stored
    // ex. a function call
    delete object;
}

void manda::ObjectInstruction::AcceptInterpreter(manda::Interpreter *interpreter) const {
    interpreter->VisitObjectInstruction(this);
}
