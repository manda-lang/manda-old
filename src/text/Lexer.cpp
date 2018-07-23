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

const std::vector<Error *> &manda::Lexer::GetErrors() const {
    return errors;
}

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
                    auto str = match[0].str();
                    auto *span = new SourceSpan(sourceUri, str, line, column);
                    auto *token = new Token(pair.second, span);
                    token->SetMatch(match);
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
    patterns.push_back(std::make_pair(std::regex("^let"), Token::LET));

    // Operators
    patterns.push_back(std::make_pair(std::regex("^="), Token::EQUALS));
    patterns.push_back(std::make_pair(std::regex("^\\*"), Token::TIMES));
    patterns.push_back(std::make_pair(std::regex("^/"), Token::DIV));
    patterns.push_back(std::make_pair(std::regex("^%"), Token::MODULO));
    patterns.push_back(std::make_pair(std::regex("^\\+"), Token::PLUS));
    patterns.push_back(std::make_pair(std::regex("^\\-"), Token::MINUS));

    // Expressions
    patterns.push_back(std::make_pair(std::regex("^0b[0-1]+"), Token::BINARY));
    patterns.push_back(std::make_pair(std::regex("^0x[A-Fa-f0-9]+"), Token::HEX));
    patterns.push_back(std::make_pair(std::regex("^0o[0-7]+"), Token::OCTAL));
    patterns.push_back(std::make_pair(std::regex("^[0-9]+(\\.[0-9])?"), Token::FLOAT));
    patterns.push_back(std::make_pair(std::regex("^[0-9]+"), Token::DECIMAL));
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
