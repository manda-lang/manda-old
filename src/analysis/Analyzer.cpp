// Copyright (c) 2018, Tobechukwu Osakwe.
//
// All rights reserved.
//
// Use of this source code is governed by an
// MIT-style license that can be found in the LICENSE file.
#include <iostream>
#include "../manda_src.h"
#include "Object.h"

using namespace manda;

manda::Analyzer::Analyzer(bool isRepl) {
    this->isRepl = isRepl;
    globalScope = new SymbolTable<Object *>;
}

manda::Analyzer::~Analyzer() {
    delete globalScope;
}

void Analyzer::LoadParser(Parser *parser) {
    for (auto *error: parser->GetErrors()) {
        errors.push_back(error);
    }

    parser->GetErrors().clear();
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

void Analyzer::CreateCoreModule() {
    if (coreModule == nullptr) {
        std::string name("Core");
        coreModule = new Module(name, globalScope->CreateChild());
        coreModule->GetScope()->Add("Function", new TypeObject(new BaseFunctionType(coreModule)));
        coreModule->GetScope()->Add("Num", new TypeObject(new NumType(coreModule)));
    }
}

const Type *Analyzer::GetCoreType(const char *name) {
    std::string n(name);
    auto *symbol = coreModule->GetScope()->Resolve(n);
    auto *typeObject = (TypeObject *) symbol->GetValue();
    return typeObject->GetReferencedType();
}

manda::Program *manda::Analyzer::VisitCompilationUnit(const manda::CompilationUnitNode *ctx) {
    auto *program = new Program;
    programStack.push(program);

    // Create the Core module.
    CreateCoreModule();
    program->GetModules().insert(std::make_pair(coreModule->GetName(), coreModule));

    // TODO: Actual names for modules
    auto *module = VisitSingleCompilationUnit(ctx);
    std::string name("Main");
    program->GetModules().insert(std::make_pair(name, module));
    program->SetMainModule(module);
    programStack.pop();
    return program;
}

void Analyzer::PrecursoryVisitCompilationUnit(Module *module, const CompilationUnitNode *ctx) {
    // Create an implicit entry function.
    auto *entry = new Function;
    auto *startBlock = new Block(module->GetScope()->CreateChild());
    entry->SetStartBlock(startBlock);
    module->SetImplicitFunction(entry);

    // TODO: Look for top-level types
}

manda::Module *manda::Analyzer::VisitSingleCompilationUnit(const manda::CompilationUnitNode *ctx) {
    std::string moduleName("Main");
    auto *module = new Module(moduleName, globalScope->CreateChild());

    // First, gather all top-level symbols.
    PrecursoryVisitCompilationUnit(module, ctx);

    // Next, visit every top-level statement, and load them into the implicit entry point.
    moduleStack.push(module);
    EnterFunction(module->GetImplicitFunction());

    // Hoist up all function declarations
    for (auto *statement : ctx->GetStatements()) {
        if (statement->HasFunctionDeclaration()) {
            VisitStatement(statement);
        }
    }

    // Visit all other statements
    for (auto *statement : ctx->GetStatements()) {
        if (!statement->HasFunctionDeclaration()) {
            VisitStatement(statement);
        }
    }

    moduleStack.pop();
    ExitFunction();

    return module;
}

void Analyzer::VisitStatement(const StatementNode *ctx) {
    ctx->AcceptAnalyzer(this);
}

void Analyzer::VisitExpressionStatement(const ExpressionStatementNode *ctx) {
    if (!isRepl && ctx->GetExpression()->CanStandAlone()) {
        AddError("Expression must be a call or assignment, otherwise, its value will be discarded.",
                 ctx->GetExpression()->GetSourceSpan());
    } else {
        auto *object = VisitExpression(ctx->GetExpression());

        // If the object is nullptr, then presumably an error has already been thrown.
        if (object != nullptr) {
            blockStack.top()->GetInstructions().push_back(new ObjectInstruction(object));
        }
    }
}

void Analyzer::VisitFunctionDeclarationStatement(const FunctionDeclarationStatementNode *ctx) {
    // Create a reference to the function.
    auto *function = new Function();
    auto *ref = new Object(GetCoreType("Function"), ctx->GetSourceSpan());
    ref->rawObject.type = Object::FUNCTION;
    ref->rawObject.value.function = function;

    if (!(blockStack.top()->GetScope()->GetParent()->Add(ctx->GetIdentifier()->GetName(), ref))) {
        std::ostringstream oss;
        oss << "The name '" << ctx->GetIdentifier()->GetName() << "' already exists in this context.";
        AddError(oss.str(), ctx->GetIdentifier()->GetSourceSpan());
        delete function;
        delete ref;
        return;
    }

    auto *module = moduleStack.top();
    auto *startBlock = new Block(module->GetScope()->CreateChild());
    function->SetName(ctx->GetIdentifier()->GetName());
    function->SetStartBlock(startBlock);
    module->GetFunctions().push_back(function);

    EnterFunction(function);

    for (unsigned long i = 0; i < ctx->GetBody()->GetStatementCount(); i++) {
        VisitStatement(ctx->GetBody()->GetStatements()[i]);
    }

    ExitFunction();
}

void Analyzer::VisitVariableDeclarationStatement(const VariableDeclarationStatementNode *ctx) {
    auto *initializer = VisitExpression(ctx->GetInitializer());

    if (initializer != nullptr) {
        if (!blockStack.top()->GetScope()->Add(ctx->GetIdentifier()->GetName(), initializer)) {
            std::ostringstream oss;
            oss << "The name '" << ctx->GetIdentifier()->GetName() << "' already exists in this context.";
            AddError(oss.str(), ctx->GetIdentifier()->GetSourceSpan());
            delete initializer;
        } else {
            auto ssaName = blockStack.top()->GetScope()->UniqueName(ctx->GetIdentifier()->GetName());
            blockStack.top()->GetScope()->GetSsaNames().insert(
                    std::make_pair(ctx->GetIdentifier()->GetName(), ssaName));
            programStack.top()->RegisterVariable(ssaName);
            blockStack.top()->GetInstructions().push_back(new AssignmentInstruction(ssaName, initializer));
        }
    }
}

Object *Analyzer::VisitExpression(const ExpressionNode *ctx) {
    return ctx->AcceptAnalyzer(this);
}

Object *Analyzer::VisitBinaryExpression(const BinaryExpressionNode *ctx) {
    return nullptr;
}

Object *Analyzer::VisitNumberLiteral(const NumberLiteralNode *ctx) {
    auto *object = new Object(GetCoreType("Num"), ctx->GetSourceSpan());
    auto type = ctx->GetToken()->GetType();

    if (type == Token::FLOAT) {
        auto *text = ctx->GetToken()->GetSourceSpan()->GetText().c_str();
        object->rawObject.type = Object::DOUBLE;
        object->rawObject.value.asDouble = strtod(text, nullptr);
    } else if (type == Token::OCTAL) {
        auto *text = ctx->GetToken()->GetMatch().c_str();
        object->rawObject.type = Object::LONG;
        object->rawObject.value.asUint64 = (uint64_t) strtol(text, nullptr, 8);
    } else if (type == Token::HEX) {
        auto *text = ctx->GetToken()->GetMatch().c_str();
        object->rawObject.type = Object::LONG;
        object->rawObject.value.asUint64 = (uint64_t) strtol(text, nullptr, 16);
    } else if (type == Token::BINARY) {
        auto *text = ctx->GetToken()->GetMatch().c_str();
        object->rawObject.type = Object::LONG;
        object->rawObject.value.asUint64 = (uint64_t) strtol(text, nullptr, 2);
    } else if (type == Token::DECIMAL) {
        auto *text = ctx->GetToken()->GetSourceSpan()->GetText().c_str();
        object->rawObject.type = Object::LONG;
        object->rawObject.value.asUint64 = (uint64_t) strtol(text, nullptr, 10);
    }

    return object;
}

Object *Analyzer::VisitSimpleIdentifier(const SimpleIdentifierNode *ctx) {
    // Find the corresponding symbol.
    const auto &name = ctx->GetName();
    auto *symbol = blockStack.top()->GetScope()->Resolve(name);

    if (symbol == nullptr) {
        std::ostringstream ss;
        ss << "The name '" << name << "' does not exist in this context.";
        AddError(ss.str(), ctx->GetSourceSpan());
        return nullptr;
    } else {
        auto *obj = symbol->GetValue();

        // If this is a constant symbol WITH a constant value, just return that
        // object.
        if (symbol->IsImmutable() && obj->rawObject.type != Object::NONE) {
            return obj;
        } else {
            // Otherwise, the value can potentially change at runtime, so return
            // a reference to it.
            bool found;
            auto ssaName = blockStack.top()->GetScope()->GetSsaName(name, &found);

            if (!found) {
                std::ostringstream ss;
                ss << "The name '" << name << "' does not exist in this context.";
                AddError(ss.str(), ctx->GetSourceSpan());
                return nullptr;
            } else {
                return new Reference(ssaName, obj->GetType(), obj->GetSourceSpan());
            }
        }
    }
}

Object *Analyzer::VisitCallExpression(const CallExpressionNode *ctx) {
    auto *callee = VisitExpression(ctx->GetCallee());

    if (callee == nullptr) {
        AddError("An error occurred while processing this call.", ctx->GetArgumentList()->GetSourceSpan());
        return nullptr;
    }

    const Type *type = GetCoreType("Num");// TODO: Actually resolve the type
    auto *call = new Call(type, callee);

    for (auto *arg : ctx->GetArgumentList()->GetArguments()) {
        // TODO: Handle named arguments
        auto *argument = VisitExpression(arg->GetExpression());

        if (argument == nullptr) {
            AddError("An error occurred while processing this argument.", arg->GetSourceSpan());
            delete call;
            delete callee;
        } else {
            call->AddArgument(argument);
        }
    }

    return call;
}
