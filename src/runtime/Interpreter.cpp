// Copyright (c) 2018, Tobechukwu Osakwe.
//
// All rights reserved.
//
// Use of this source code is governed by an
// MIT-style license that can be found in the LICENSE file.
#include <jit/jit-dump.h>
#include <iostream>
#include "Interpreter.h"

using namespace manda;

manda::Interpreter::Interpreter(manda::VM *vm) {
    this->vm = vm;
    jit = jit_context_create();
}

jit_function_t Interpreter::GetCurrentFunction() {
    return functionStack.top();
}

void Interpreter::LoadProgram(Program *program) {
    this->program = program;
}

void Interpreter::Run() {
   bool anyFibersAreAlive = false;

    do {
        for (auto *fiber : vm->GetFibers()) {
            if (!fiber->HasExited()) {
                anyFibersAreAlive = true;
            }
        }
    } while (anyFibersAreAlive);
}

jit_value_t Interpreter::GetValue(jit_function_t function, jit_value_t nan) {
    // Shift right by three.
    auto three = jit_value_create_nint_constant(function, jit_type_int, 3);
    return jit_insn_shl(function, nan, three);
}

jit_value_t Interpreter::SetValue(jit_function_t function, jit_value_t nan, jit_value_t newValue) {
    //  TaggedPointerType currentType = GetType();
    jit_value_t currentType = GetType(function, nan);

    // asUlong = data << 3;
    auto three = jit_value_create_nint_constant(function, jit_type_int, 3);
    auto shifted = jit_insn_shl(function, newValue, three);

    // SetType(currentType);
    return SetType(function, shifted, currentType);
}

jit_value_t Interpreter::SetType(jit_function_t function, jit_value_t nan, TaggedPointer::TaggedPointerType type) {
    auto numberType = jit_value_create_nint_constant(function, jit_type_ubyte, type);
    return jit_insn_or(function, nan, numberType);
}

jit_value_t Interpreter::SetType(jit_function_t function, jit_value_t nan, jit_value_t type) {
    return jit_insn_or(function, nan, type);
}

jit_value_t Interpreter::Zero(jit_function_t function) {
    return jit_value_create_float64_constant(function, jit_type_float64, 0);
}

jit_value_t Interpreter::GetType(jit_function_t function, jit_value_t nan) {
    // Get the bottom 3 bits
    // auto bottom3 = (uint8_t) (asUlong & 0x7);
    auto seven = jit_value_create_nint_constant(function, jit_type_ubyte, 0x7);
    auto bottom3 = jit_insn_and(function, nan, seven);
    return jit_insn_convert(function, bottom3, jit_type_ubyte, 0);
}

uint8_t Interpreter::SymbolTableStore(Interpreter *interpreter, const char *name, double value) {
    std::string n(name);
    interpreter->fiber->GetScope()->Add(n, value);
    return 1;
}

uint8_t Interpreter::SymbolTableRetrieve(Interpreter *interpreter, const char *name, double *value) {
    std::string n(name);
    auto *symbol = interpreter->fiber->GetScope()->Resolve(n);

    if (symbol == nullptr) {
        return 0;
    } else {
        *value = symbol->GetValue();
        return 1;
    }
}
