// Copyright (c) 2018, Tobechukwu Osakwe.
//
// All rights reserved.
//
// Use of this source code is governed by an
// MIT-style license that can be found in the LICENSE file.
#include <deque>
#include <iostream>
#include "BinaryExpressionParselet.h"
#include "Parser.h"

using namespace manda;

manda::Parser::Parser(manda::Lexer *lexer) {
    this->lexer = lexer;
    this->index = -1;

    for (auto *error : lexer->GetErrors()) {
        errors.push_back(error);
    }

    lexer->GetErrors().clear();

    int precedence = 4;
    infixParselets[Token::TIMES] = new BinaryExpressionParselet(precedence--);
    infixParselets[Token::DIV] = new BinaryExpressionParselet(precedence--);
    infixParselets[Token::MODULO] = new BinaryExpressionParselet(precedence--);
    infixParselets[Token::PLUS] = new BinaryExpressionParselet(precedence--);
    infixParselets[Token::MINUS] = new BinaryExpressionParselet(precedence--);
}

Parser::~Parser() {
    // TODO: Delete all infix parselets
}

const manda::Token *manda::Parser::GetCurrentToken() const {
    return lexer->GetTokens().at((unsigned long) index);
}

bool manda::Parser::IsDone() const {
    return (index >= (int64_t) (lexer->GetTokens().size() - 1));
}

bool manda::Parser::Next(manda::Token::TokenType type) {
    auto *token = Peek();

    if (token == nullptr) {
        return false;
    } else if (token->GetType() != type) {
        return false;
    } else {
        index++;
        return true;
    }
}

bool Parser::Next(Token::TokenType *types, int typeCount) {
    for (int i = 0; i < typeCount; i++) {
        if (Next(types[i])) {
            return true;
        }
    }

    return false;
}

const manda::Token *manda::Parser::Peek() const {
    if (IsDone()) {
        return nullptr;
    } else {
        return lexer->GetTokens().at((unsigned long) index + 1);
    }
}

const manda::Token *manda::Parser::Consume() {
    auto *peek = Peek();

    if (peek != nullptr) {
        index++;
    }

    return peek;
}

CompilationUnitNode *Parser::ParseCompilationUnit() {
    auto *program = new CompilationUnitNode;

    while (!IsDone()) {
        auto *statement = ParseStatement();

        if (statement != nullptr) {
            program->GetMutableStatements().push_back(statement);
        } else {
            std::ostringstream message;
            auto *token = Consume();

            if (token != nullptr) {
                message << "Unexpected text '";
                message << token->GetSourceSpan()->GetText();
                message << "'.";
                auto *error = new Error(Error::ERROR, message.str(), new SourceSpan(token->GetSourceSpan()));
                errors.push_back(error);
                delete token;
            }
        }
    }

    return program;
}

void Parser::ParseStatements(std::vector<StatementNode *> &statements) {
    auto *statement = ParseStatement();

    while (statement != nullptr) {
        statements.push_back(statement);
        statement = ParseStatement();
    }
}

StatementNode *Parser::ParseStatement() {
    StatementNode *result = nullptr;
    if ((result = ParseFunctionDeclarationStatement()) != nullptr) return result;
    if ((result = ParseVariableDeclarationStatement()) != nullptr) return result;
    if ((result = ParseExpressionStatement()) != nullptr) return result;
    return result;
}

FunctionDeclarationStatementNode *Parser::ParseFunctionDeclarationStatement() {
    if (!Next(Token::FUNC))
        return nullptr;

    auto *func = GetCurrentToken();
    auto *name = ParseSimpleIdentifier();

    if (name == nullptr) {
        AddError("Missing identifier after 'func'.", func->GetSourceSpan());
        delete func;
        return nullptr;
    }

    delete func;
    auto *signature = ParseFunctionSignature();

    if (signature == nullptr) {
        std::ostringstream oss;
        oss << "Missing signature for function '" << name->GetName() << "'.";
        AddError(oss.str(), name->GetSourceSpan());
        delete name;
        return nullptr;
    }

    auto *body = ParseFunctionBody();

    if (body == nullptr) {
        std::ostringstream oss;
        oss << "Missing body for function '" << name->GetName() << "'.";
        AddError(oss.str(), name->GetSourceSpan());
        delete name;
        delete signature;
        return nullptr;
    }

    return new FunctionDeclarationStatementNode(name, signature, body);
}

FunctionBodyNode *Parser::ParseFunctionBody() {
    return ParseArrowFunctionBody();
}

ArrowFunctionBodyNode *Parser::ParseArrowFunctionBody() {
    if (!Next(Token::ARROW)) {
        return nullptr;
    }

    auto *arrow = GetCurrentToken();
    auto *expr = ParseExpression(0);
    AddError("Missing expression after '=>' in arrow function body.", arrow->GetSourceSpan());
    if (expr == nullptr) {
        delete arrow;
        return nullptr;
    } else {
        delete arrow;
        return new ArrowFunctionBodyNode(expr);
    }
}

FunctionSignatureNode *Parser::ParseFunctionSignature() {
    auto *parameterList = ParseParameterList();

    if (parameterList == nullptr)
        return nullptr;

    // Check for :type
    TypeNode *returnType = nullptr;

    if (Next(Token::COLON)) {
        auto *colon = GetCurrentToken();

        if ((returnType = ParseType()) == nullptr) {
            AddError("Missing return type for function after ':'.", colon->GetSourceSpan());
            delete parameterList;
            delete colon;
            return nullptr;
        } else {
            delete colon;
        }
    }

    return new FunctionSignatureNode(parameterList, returnType);
}

ParameterListNode *Parser::ParseParameterList() {
    if (!Next(Token::LPAREN))
        return nullptr;

    std::deque<ParameterNode *> parameters;
    auto *lParen = GetCurrentToken();
    auto *lastSpan = lastSpan->GetSourceSpan();
    auto *parameter = ParseParameter();
    const Token *lastComma = nullptr;

    while (parameter != nullptr) {
        parameters.push_back(parameter);
        lastSpan = parameter->GetSourceSpan();

        if (!Next(Token::COMMA))
            break;

        delete *lastComma;
        lastComma = GetCurrentToken();
        lastSpan = lastComma->GetSourceSpan();
        parameter = ParseParameter();
    }

    if (!Next(Token::RPAREN)) {
        AddError("Missing ')' in parameter list.", lastSpan);
        delete lastComma;
        delete lParen;

        while (!parameters.empty()) {
            delete parameters.front();
            parameters.pop_front();
        }
    }

    auto *rParen = GetCurrentToken();
    delete rParen;

    auto *list = new ParameterListNode(lParen->GetSourceSpan());
    delete lParen;
    delete lastComma;

    while (!parameters.empty()) {
        list->GetParameters().push_back(parameters.front());
        parameters.pop_front();
    }

    return list;
}

ParameterNode *Parser::ParseParameter() {
    auto *name = ParseSimpleIdentifier();

    if (name == nullptr)
        return nullptr;

    // Check for type annotation
    TypeNode *type = nullptr;

    if (Next(Token::COLON)) {
        auto *colon = GetCurrentToken();

        if ((type = ParseType()) == nullptr) {
            std::ostringstream oss;
            oss << "Missing type after ':' for parameter '" << name->GetName() << "'.";
            AddError(oss.str(), colon->GetSourceSpan());
            delete name;
            delete colon;
            return nullptr;
        } else {
            delete colon;
        }
    }

    // Check for defaultValue
    ExpressionNode *defaultValue = nullptr;

    if (Next(Token::EQUALS)) {
        auto *equals = GetCurrentToken();

        if ((defaultValue = ParseExpression(0)) == nullptr) {
            std::ostringstream oss;
            oss << "Missing default value after '=' for parameter '" << name->GetName() << "'.";
            AddError(oss.str(), equals->GetSourceSpan());
            delete name;
            delete equals;
            delete type;
        } else {
            delete equals;
        }
    }

    return new ParameterNode(name, type, defaultValue);
}

VariableDeclarationStatementNode *Parser::ParseVariableDeclarationStatement() {
    if (!Next(Token::LET)) {
        return nullptr;
    }

    auto *let = GetCurrentToken();
    auto *id = ParseSimpleIdentifier();

    if (id == nullptr) {
        AddError("Missing identifier after 'let' keyword.", let->GetSourceSpan());
        delete let;
        return nullptr;
    }

    if (!Next(Token::EQUALS)) {
        AddError("Missing '=' in variable declaration.", id->GetSourceSpan());
        delete let;
        delete id;
        return nullptr;
    }

    auto *equals = GetCurrentToken();
    auto *initializer = ParseExpression(0);

    if (initializer == nullptr) {
        AddError("Missing expression after '=' in variable declaration.", equals->GetSourceSpan());
        delete let;
        delete id;
        delete equals;
        return nullptr;
    }

    return new VariableDeclarationStatementNode(let, id, equals, initializer);
}

TypeNode *Parser::ParseType() {
    // TODO: Pratt for types
    return ParseTypeReference();
}

TypeReferenceNode *Parser::ParseTypeReference() {
    auto *id = ParseSimpleIdentifier();
    return id == nullptr ? nullptr : new TypeReferenceNode(id);
}

ExpressionStatementNode *Parser::ParseExpressionStatement() {
    auto *expression = ParseExpression();
    return expression == nullptr ? nullptr : new ExpressionStatementNode(expression);
}

manda::ExpressionNode *manda::Parser::ParsePrefixExpression() {
    ExpressionNode *result = nullptr;
    if ((result = ParseSimpleIdentifier()) != nullptr) return result;
    if ((result = ParseNumberLiteral()) != nullptr) return result;
    return result;
}

ExpressionNode *Parser::ParseExpression(int precedence) {
    auto *left = ParsePrefixExpression();

    while (left != nullptr && precedence < GetPrecedence()) {
        auto *token = Consume();

        if (token != nullptr) {
            auto it = infixParselets.find(token->GetType());

            if (it != infixParselets.end()) {
                InfixParselet *infix = infixParselets.at(token->GetType());
                left = infix->Parse(this, left, token);
            }
        } else {
            break;
        }
    }

    return left;
}

manda::SimpleIdentifierNode *Parser::ParseSimpleIdentifier() {
    if (!Next(Token::ID)) {
        return nullptr;
    } else {
        return new SimpleIdentifierNode(GetCurrentToken());
    }
}

manda::NumberLiteralNode *manda::Parser::ParseNumberLiteral() {
    Token::TokenType numberTypes[5] = {Token::DECIMAL, Token::FLOAT, Token::BINARY, Token::HEX, Token::OCTAL};

    if (Next(numberTypes, sizeof(numberTypes) / sizeof(Token::TokenType))) {
        return new NumberLiteralNode(GetCurrentToken());
    } else {
        return nullptr;
    }
}

int Parser::GetPrecedence() const {
    auto *token = Peek();

    if (token != nullptr) {
        auto it = infixParselets.find(token->GetType());

        if (it != infixParselets.end()) {
            InfixParselet *infix = infixParselets.at(token->GetType());
            return infix->GetPrecedence();
        }
    }

    return 0;
}
