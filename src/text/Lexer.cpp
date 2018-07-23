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

            // TODO: Parse keywords

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
                // TODO: How to handle incorrect input?
                txt = txt.substr(1);
                column++;
            } else {
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
}

Lexer::Lexer() {
    // Patterns
    patterns.push_back(std::make_pair(std::regex("^[0-9]+"), Token::DECIMAL));
    //patterns.push_back(std::make_pair(std::regex("^[0-9]+(\\.[0-9])?"), Token::DECIMAL));
}
