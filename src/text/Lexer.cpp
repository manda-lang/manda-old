// Copyright (c) 2018, Tobechukwu Osakwe.
//
// All rights reserved.
//
// Use of this source code is governed by an
// MIT-style license that can be found in the LICENSE file.
#include <cctype>
#include <cstdint>
#include "Lexer.h"

using namespace manda;

const std::vector<Token *> &manda::Lexer::GetTokens() const {
    return tokens;
}

void manda::Lexer::Scan(std::string &sourceText, std::string &sourceUri) {
    std::string txt = sourceText;
    int64_t line = 1, column = 0;

    while (!txt.empty()) {
        // Skip whitespace.
        while (!txt.empty() && iswspace(txt.at(0))) {
            if (txt.at(0) == '\n') {
                line++;
                column = -1;
            }

            column++;
            txt = txt.substr(1);
        }

        if (!txt.empty()) {
            std::vector<Token *> staging;

            for (auto &pair : patterns) {
                std::smatch match;

                if (std::regex_search(txt, match, pair.first)) {
                    auto str = match.str(0);
                    auto s1 = match.str(1);
                    auto *span = new SourceSpan(sourceUri, str, line, column);
                    auto *token = new Token(pair.second, span);
                    token->SetMatch(s1);
                    staging.push_back(token);
                }
            }

            if (staging.empty()) {
                if (!hasErrantText) {
                    errantLine = line;
                    errantColumn = column;
                }

                errantText.put(txt.at(0));
                txt = txt.substr(1);
                column++;
                hasErrantText = true;
            } else {
                FlushErrantText(sourceUri);

                unsigned long longestLength = 0;
                Token *longestToken = nullptr;

                for (auto *token : staging) {
                    if (token->GetSourceSpan()->GetText().size() > longestLength) {
                        longestToken = token;
                        longestLength = token->GetSourceSpan()->GetText().size();
                    }
                }

                // Delete all the other tokens.
                for (auto *token: staging) {
                    if (token != longestToken) {
                        delete token;
                    }
                }

                // Propagate the chosen token.
                tokens.push_back(longestToken);
                column += longestLength;
                txt = txt.substr(longestLength);
            }
        }
    }

    FlushErrantText(sourceUri);
}

Lexer::Lexer() {
    hasErrantText = false;
    errantLine = 1;
    errantColumn = 0;

    // Keywords
    patterns.push_back(std::make_pair(std::regex("^async"), Token::ASYNC));
    patterns.push_back(std::make_pair(std::regex("^await"), Token::AWAIT));
    patterns.push_back(std::make_pair(std::regex("^catch"), Token::CATCH));
    patterns.push_back(std::make_pair(std::regex("^constructor"), Token::CONSTRUCTOR));
    patterns.push_back(std::make_pair(std::regex("^do"), Token::DO));
    patterns.push_back(std::make_pair(std::regex("^enum"), Token::ENUM));
    patterns.push_back(std::make_pair(std::regex("^for"), Token::FOR));
    patterns.push_back(std::make_pair(std::regex("^func"), Token::FUNC));
    patterns.push_back(std::make_pair(std::regex("^import"), Token::IMPORT));
    patterns.push_back(std::make_pair(std::regex("^in"), Token::IN));
    patterns.push_back(std::make_pair(std::regex("^interface"), Token::INTERFACE));
    patterns.push_back(std::make_pair(std::regex("^let"), Token::LET));
    patterns.push_back(std::make_pair(std::regex("^property"), Token::PROPERTY));
    patterns.push_back(std::make_pair(std::regex("^return"), Token::RETURN));
    patterns.push_back(std::make_pair(std::regex("^throw"), Token::THROW));
    patterns.push_back(std::make_pair(std::regex("^try"), Token::TRY));
    patterns.push_back(std::make_pair(std::regex("^type"), Token::TYPE));
    patterns.push_back(std::make_pair(std::regex("^var"), Token::VAR));
    patterns.push_back(std::make_pair(std::regex("^while"), Token::WHILE));
    patterns.push_back(std::make_pair(std::regex("^with"), Token::WITH));

    // Kw-operators
    patterns.push_back(std::make_pair(std::regex("^as"), Token::AS));
    patterns.push_back(std::make_pair(std::regex("^is"), Token::IS));

    // Misc.
    patterns.push_back(std::make_pair(std::regex("^:"), Token::COLON));
    patterns.push_back(std::make_pair(std::regex("^,"), Token::COMMA));
    patterns.push_back(std::make_pair(std::regex("^;"), Token::SEMICOLON));

    // Operators
    patterns.push_back(std::make_pair(std::regex("^\\("), Token::LPAREN));
    patterns.push_back(std::make_pair(std::regex("^\\)"), Token::RPAREN));
    patterns.push_back(std::make_pair(std::regex("^\\["), Token::LBRACKET));
    patterns.push_back(std::make_pair(std::regex("^\\]"), Token::RBRACKET));
    patterns.push_back(std::make_pair(std::regex("^{"), Token::LCURLY));
    patterns.push_back(std::make_pair(std::regex("^}"), Token::RCURLY));
    patterns.push_back(std::make_pair(std::regex("^\\."), Token::DOT));
    patterns.push_back(std::make_pair(std::regex("^="), Token::EQUALS));\
    patterns.push_back(std::make_pair(std::regex("^\\*"), Token::TIMES));
    patterns.push_back(std::make_pair(std::regex("^/"), Token::DIV));
    patterns.push_back(std::make_pair(std::regex("^%"), Token::MODULO));
    patterns.push_back(std::make_pair(std::regex("^\\+"), Token::PLUS));
    patterns.push_back(std::make_pair(std::regex("^\\-"), Token::MINUS));
    patterns.push_back(std::make_pair(std::regex("^<"), Token::LT));
    patterns.push_back(std::make_pair(std::regex("^<="), Token::LTE));
    patterns.push_back(std::make_pair(std::regex("^>"), Token::RT));
    patterns.push_back(std::make_pair(std::regex("^>="), Token::RTE));
    patterns.push_back(std::make_pair(std::regex("^|"), Token::PIPE));

    // Expressions
    patterns.push_back(std::make_pair(std::regex("^0b([0-1]+)"), Token::BINARY));
    patterns.push_back(std::make_pair(std::regex("^0x([A-Fa-f0-9]+)"), Token::HEX));
    patterns.push_back(std::make_pair(std::regex("^0o([0-7]+)"), Token::OCTAL));
    patterns.push_back(std::make_pair(std::regex("^[0-9]+"), Token::DECIMAL));
    patterns.push_back(std::make_pair(std::regex("^[0-9]+(\\.[0-9]+)"), Token::FLOAT));
    patterns.push_back(std::make_pair(std::regex("^[A-Za-z_][A-Za-z0-9_]*"), Token::ID));
    //patterns.push_back(std::make_pair(std::regex("^[0-9]+(\\.[0-9])?"), Token::DECIMAL));
}

void Lexer::FlushErrantText(std::string &sourceUri) {
    if (hasErrantText) {
        auto text = errantText.str();
        std::ostringstream message;
        message << "Unexpected text '";
        message << text;
        message << "'.";
        auto *span = new SourceSpan(sourceUri, text, errantLine, errantColumn);
        auto *error = new Error(Error::ERROR, message.str(), span);
        errors.push_back(error);
        errantText = std::ostringstream();
        hasErrantText = false;
    }
}
