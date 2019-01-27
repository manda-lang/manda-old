#ifndef MANDA_STRING_SCANNER_H
#define MANDA_STRING_SCANNER_H

#include <istream>
#include <ostream>
#include <string>

namespace manda::parsing
{
    struct string_scanner_state
    {
        std::string uri;
        unsigned long line, column, offset;
    };

    std::ostream &operator<<(std::ostream &out, const string_scanner_state &state);

    struct source_span
    {
        string_scanner_state start, end;

        const std::string &uri() const;

        source_span operator+(const source_span& other);
    };

    std::ostream &operator<<(std::ostream &out, const source_span &span);

    class string_scanner
    {
    public:
        string_scanner(std::string source_url, std::istream &in);

        bool done() const;

        unsigned long line() const;

        unsigned long column() const;

        int read();

        int peek() const;

        string_scanner_state state() const;

        bool matches(int ch);

        bool matches(const std::string &str);

        bool scan(int ch);

        bool scan(const std::string &str);

        source_span last_span() const;

    private:
        unsigned long m_line, m_column, m_offset;
        source_span m_last_span;
        std::istream &in;
        std::string source_url;
    };
} // namespace manda::parsing

#endif