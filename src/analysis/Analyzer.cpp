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

void Analyzer::EnterFunction(Function *function) {
    functionStack.push(function);
    EnterBlock(function->GetStartBlock());
}

void Analyzer::ExitFunction() {
    ExitBlock();
    functionStack.pop();
}

void Analyzer::EnterBlock(Block *block) {
    blockStack.push(block);
}

void Analyzer::ExitBlock() {
    blockStack.pop();
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

    // First, gather all top-level symbols.
    PrecursoryVisitCompilationUnit(module, ctx);

    // Next, visit every top-level statement, and load them into the implicit entry point.
    EnterFunction(module->GetImplicitFunction());

    for (auto *statement : ctx->GetStatements()) {
        if (!statement->HasFunctionDeclaration()) {
            VisitStatement(statement);
        }
    }

    ExitFunction();

    return module;
}

void Analyzer::VisitStatement(StatementNode *ctx) {
    ctx->AcceptAnalyzer(this);
}

void Analyzer::VisitExpressionStatement(ExpressionStatementNode *ctx) {

}

void Analyzer::VisitVariableDeclarationStatement(VariableDeclarationStatementNode *ctx) {

}

Object *Analyzer::VisitExpression(ExpressionNode *ctx) {
    return ctx->AcceptAnalyzer(this);
}

Object *Analyzer::VisitBinaryExpression(BinaryExpressionNode *ctx) {
    return nullptr;
}

Object *Analyzer::VisitNumberLiteral(NumberLiteralNode *ctx) {
    return nullptr;
}

Object *Analyzer::VisitSimpleIdentifier(SimpleIdentifierNode *ctx) {
    return nullptr;
}
