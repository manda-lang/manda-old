#ifndef MANDA_STRING_SCANNER_H
#define MANDA_STRING_SCANNER_H

#include <istream>

namespace manda::parsing
{
    class string_scanner
    {
    public:
        explicit string_scanner(std::istream &in);

        bool done() const;

        unsigned long line() const;

        unsigned long column() const;

    private:
        unsigned long m_line, m_column;
        std::istream &in;
    };
} // namespace manda::parsing

#endif