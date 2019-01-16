#ifndef MANDA_STRING_SCANNER_H
#define MANDA_STRING_SCANNER_H

#include <istream>
#include <ostream>
#include <string>

namespace manda::parsing
{
    struct string_scanner_state
    {
        unsigned long line, column;
    };

    std::ostream &operator<<(std::ostream &out, const string_scanner_state &state);

    struct source_span
    {
        string_scanner_state start, end;
    };

    std::ostream &operator<<(std::ostream &out, const source_span &span);

    class string_scanner
    {
    public:
        explicit string_scanner(std::istream &in);

        bool done() const;

        unsigned long line() const;

        unsigned long column() const;

        int read();

        int peek() const;

        string_scanner_state state() const;

        bool scan(int ch);

        bool scan(const std::string &str);

        source_span last_span() const;

    private:
        unsigned long m_line, m_column;
        source_span m_last_span;
        std::istream &in;
    };
} // namespace manda::parsing

#endif