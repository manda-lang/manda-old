// Copyright (c) 2018, Tobechukwu Osakwe.
//
// All rights reserved.
//
// Use of this source code is governed by an
// MIT-style license that can be found in the LICENSE file.
#include "Analyzer.h"

using namespace manda;

manda::Analyzer::Analyzer(Parser *parser) {
    globalScope = new SymbolTable<Object *>;

    for (auto *error: parser->GetErrors()) {
        errors.push_back(error);
    }

    parser->GetErrors().clear();
}

manda::Analyzer::~Analyzer() {
    delete globalScope;
}

manda::Program *manda::Analyzer::VisitCompilationUnit(manda::CompilationUnitNode *ctx) {
    auto *program = new Program;

    // TODO: Actual names for modules
    auto *module = VisitSingleCompilationUnit(ctx);
    std::string name("Main");
    program->GetModules().insert(std::make_pair(name, module));
    program->SetMainModule(module);

    return program;
}

void Analyzer::PrecursoryVisitCompilationUnit(Module *module, CompilationUnitNode *ctx) {
    // Create an implicit entry function.
    auto *entry = new Function;
    auto *startBlock = new Block(module->GetScope()->CreateChild());
    entry->SetStartBlock(startBlock);
    module->SetImplicitFunction(entry);

    // TODO: Look for top-level functions + types
}

manda::Module *manda::Analyzer::VisitSingleCompilationUnit(manda::CompilationUnitNode *ctx) {
    auto *module = new Module(globalScope->CreateChild());
    PrecursoryVisitCompilationUnit(module, ctx);
    return module;
}
