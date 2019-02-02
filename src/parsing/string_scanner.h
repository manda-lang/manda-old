#ifndef MANDA_STRING_SCANNER_H
#define MANDA_STRING_SCANNER_H

#include <istream>
#include <ostream>
#include <regex>
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

        unsigned long length() const;

        const std::string &uri() const;

        source_span operator+(const source_span& other);
    };

    std::ostream &operator<<(std::ostream &out, const source_span &span);

    class string_scanner
    {
    public:
        string_scanner(const std::string &source_url, const std::string &in);

        bool done() const;

        unsigned long line() const;

        unsigned long column() const;

        int read();

        int peek() const;

        string_scanner_state state() const;

        bool matches(const std::string &str);

        bool matches(const std::regex& rgx);

        bool scan(const std::string &str);

        bool scan(const std::regex& rgx);

        std::smatch last_match() const;

        source_span last_span() const;

    private:
        bool matches(int ch);

        bool scan(int ch);

        unsigned long m_line, m_column, m_offset;
        std::smatch m_last_match;
        source_span m_last_span;
        std::string in;
        std::string source_url;
    };
} // namespace manda::parsing

#endif