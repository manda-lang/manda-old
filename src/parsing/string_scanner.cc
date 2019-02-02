#include <deque>
#include <utility>
#include "string_scanner.h"

unsigned long manda::parsing::source_span::length() const {
    return end.offset - start.offset;
}

const std::string &manda::parsing::source_span::uri() const {
    return start.uri;
}

manda::parsing::source_span manda::parsing::source_span::operator+(const manda::parsing::source_span &other) {
    // TODO: Prevent joining of disjoint spans
    // TODO: Prevent joining of spans from different files
    auto s = start, e = end;

    if (other.start.offset < s.offset) s = other.start;
    if (other.end.offset > e.offset) e = other.end;

    return {s, e};
}

std::ostream &manda::parsing::operator<<(std::ostream &out, const manda::parsing::string_scanner_state &state) {
    out << state.uri << ":" << state.line << ":" << state.column;
    return out;
}

std::ostream &manda::parsing::operator<<(std::ostream &out, const manda::parsing::source_span &span) {
    out << span.start;
    return out;
}

manda::parsing::string_scanner::string_scanner(const std::string &source_url, const std::string &in)
        : in(in),
          source_url(source_url) {
    m_line = 1;
    m_column = 0;
    m_offset = 0;
}

bool manda::parsing::string_scanner::done() const {
    return m_offset >= in.length() - 1;
}

unsigned long manda::parsing::string_scanner::line() const {
    return m_line;
}

unsigned long manda::parsing::string_scanner::column() const {
    return m_column;
}

int manda::parsing::string_scanner::read() {
    if (done()) return -1;

    auto ch = in[m_offset];

    if (ch == '\n') {
        m_line++;
        m_column = 0;
    } else {
        m_column++;
    }

    m_offset++;
    return ch;
}

int manda::parsing::string_scanner::peek() const {
    if (done()) return -1;

    return in[m_offset + 1];
}

manda::parsing::string_scanner_state manda::parsing::string_scanner::state() const {
    return {source_url, m_line, m_column, m_offset};
}

bool manda::parsing::string_scanner::matches(int ch) {
    return peek() == ch;
}

bool manda::parsing::string_scanner::matches(const std::string &str) {
    auto start = state();

    for (unsigned long i = 0; i < str.length(); i++) {
        auto desired = str[i];
        auto index = m_offset + i;
        if (index >= in.length()) return false;
        auto actual = in[i];
        if (actual != desired) return false;

    }

    // We found all characters. Set the last span.
    // Just assume that the search string is always on the same line.
    string_scanner_state end = {source_url, m_line, m_column + str.length(), m_offset + str.length()};
    m_last_span = {start, end};

    // Backtrack, regardless of whether we matched.
    m_offset = start.offset;
    m_column = start.column;
    m_line = start.line;

    return true;
}

bool manda::parsing::string_scanner::matches(const std::regex &rgx) {
    auto s = in.substr(m_offset);
    std::smatch sm;

    if (!std::regex_search(s, sm, rgx)) {
        return false;
    } else {
        auto start = state();
        auto str = sm.str();
        string_scanner_state end = {source_url, m_line, m_column + str.length(), m_offset + str.length()};
        m_last_span = {start, end};
        m_last_match = sm;
        return true;
    }
}

bool manda::parsing::string_scanner::scan(int ch) {
    if (matches(ch)) {
        read();
        return true;
    } else {
        return false;
    }
}

bool manda::parsing::string_scanner::scan(const std::string &str) {
    if (matches(str)) {
        auto span = last_span();

        for (unsigned long i = 0; i < str.length(); i++) {
            read();
        }

        m_last_span = span;
        return true;
    } else {
        return false;
    }
}

bool manda::parsing::string_scanner::scan(const std::regex &rgx) {
    if (!matches(rgx)) return false;
    auto start = state();

    for (unsigned long i = 0; i < m_last_match.str().length(); i++) {
        read();
    }

    m_last_span = {start, state()};
    return true;
}

std::smatch manda::parsing::string_scanner::last_match() const {
    return m_last_match;
}

manda::parsing::source_span manda::parsing::string_scanner::last_span() const {
    return m_last_span;
}
