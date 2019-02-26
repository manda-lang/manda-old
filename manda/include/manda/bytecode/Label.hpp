// Copyright (c) 2019, Tobechukwu Osakwe.
//
// All rights reserved.
//
// Use of this source code is governed by a
// license that can be found in the LICENSE file.
#ifndef MANDA_LABEL_HPP
#define MANDA_LABEL_HPP

#include <string>
#include <vector>
#include "Instruction.hpp"
#include "Node.hpp"

namespace manda
{
    namespace bytecode
    {
        class Label : public Node
        {
        public:
            Label();

            bool hasName() const;

            const std::string &getName() const;

            void setName(const std::string &name);

            std::vector<Instruction> &getInstructions();

            const std::vector<Instruction> &getInstructions() const;

            void accept(BytecodeVisitor &visitor) override;

        private:
            std::vector<Instruction> instructions;
            std::string name;
            bool mHasName;
        };
    }
}

#endif //MANDA_LABEL_HPP
