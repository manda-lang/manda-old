// Copyright (c) 2018, Tobechukwu Osakwe.
//
// All rights reserved.
//
// Use of this source code is governed by an
// MIT-style license that can be found in the LICENSE file.
#include "../manda_src.h"

manda::AssignmentInstruction::AssignmentInstruction(const std::string &name, const manda::Object *object) {
    this->name += name;
    this->object = object;
}

manda::AssignmentInstruction::~AssignmentInstruction() {
    delete object;
}

const std::string &manda::AssignmentInstruction::GetName() const {
    return name;
}

const manda::Object *manda::AssignmentInstruction::GetObject() const {
    return object;
}

void manda::AssignmentInstruction::AcceptInterpreter(manda::Interpreter *interpreter) const {
    interpreter->VisitAssignmentInstruction(this);
}
