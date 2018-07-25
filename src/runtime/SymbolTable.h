// Copyright (c) 2018, Tobechukwu Osakwe.
//
// All rights reserved.
//
// Use of this source code is governed by an
// MIT-style license that can be found in the LICENSE file.
#ifndef MANDA_SYMBOLTABLE_H
#define MANDA_SYMBOLTABLE_H

#include <sstream>
#include <unordered_map>
#include <vector>
#include "Symbol.h"

namespace manda
{
    template<typename T>
    class SymbolTable
    {
    public:
        SymbolTable() {
            parent = nullptr;
        }

        ~SymbolTable() {
            for (auto *symbol : symbols) {
                delete symbol;
            }
        }

        bool Add(const std::string &name, T value) {
            if (!symbols.empty()) {
                for (auto *symbol : symbols) {
                    if (symbol != nullptr && symbol->GetName() == name) {
                        return false;
                    }
                }
            }

            auto *symbol = new Symbol<T>(name, value);
            symbols.push_back(symbol);
            return true;
        }

        bool Add(const char *name, T value) {
            std::string n(name);
            return Add(n, value);
        }

        bool IsRoot() const {
            return parent == nullptr;
        }

        SymbolTable<T> *GetParent() const {
            return parent;
        }

        SymbolTable<T> *CreateChild() const {
            return new SymbolTable<T>((SymbolTable<T> *) this);
        }

        Symbol<T> *Resolve(const std::string &name) const {
            if (!symbols.empty()) {
                for (auto *symbol : symbols) {
                    if (symbol != nullptr && symbol->GetName() == name) {
                        return symbol;
                    }
                }
            }

            if (parent == nullptr) {
                return nullptr;
            } else {
                return parent->Resolve(name);
            }
        }

        std::string UniqueName(const std::string &name) {
            auto it = nameCounts.find(name);
            long result;

            if (it == nameCounts.end()) {
                result = nameCounts[name] = 0;
            } else {
                result = nameCounts[name]++;
            }

            std::ostringstream oss;
            oss << name << result;
            return oss.str();
        }

        bool ExistsAtThisLevel(const std::string &name) const;

    private:
        explicit SymbolTable(SymbolTable<T> *parent) {
            this->parent = parent;
        }

        SymbolTable<T> *parent;
        std::unordered_map<std::string, long> nameCounts;
        std::vector<Symbol<T> *> symbols;
    };
}

#endif //MANDA_SYMBOLTABLE_H
