// Copyright (c) 2019, Tobechukwu Osakwe.
//
// All rights reserved.
//
// Use of this source code is governed by a
// license that can be found in the LICENSE file.
#ifndef MANDA_SECTION_HPP
#define MANDA_SECTION_HPP

#include <manda/bytecode/Node.hpp>

namespace manda
{
    namespace bytecode
    {
        enum SectionType
        {
            DATA_SECTION,
            CODE_SECTION
        };

        class Section : public Node
        {
        public:
            virtual SectionType getType() const = 0;
        };
    }
}

#endif //MANDA_SECTION_HPP
