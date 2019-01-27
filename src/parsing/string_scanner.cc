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
    out << "{" << span.start << ", " << span.end << "}";
    return out;
}

manda::parsing::string_scanner::string_scanner(const std::string source_url, std::istream &in)
        : in(in),
          source_url(source_url) {
    m_line = 1;
    m_column = 0;
    m_offset = 0;
}

bool manda::parsing::string_scanner::done() const {
    return !in.good();
}

unsigned long manda::parsing::string_scanner::line() const {
    return m_line;
}

unsigned long manda::parsing::string_scanner::column() const {
    return m_column;
}

int manda::parsing::string_scanner::read() {
    auto ch = in.get();

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
    return in.peek();
}

manda::parsing::string_scanner_state manda::parsing::string_scanner::state() const {
    return {source_url, m_line, m_column, m_offset};
}

bool manda::parsing::string_scanner::matches(int ch) {
    return in.peek() == ch;
}

bool manda::parsing::string_scanner::matches(const std::string &str) {
    auto start = state();
    std::deque<int> cache;
    bool result = true;

    for (char desired : str) {
        auto actual = peek();

        if (actual != desired) {
            // If we didn't find the next character, backtrack.
            result = false;
            break;
        } else {
            cache.push_back(read());
        }
    }

    if (result) {
        // We found all characters. Set the last span.
        m_last_span = {start, state()};
    }

    // Backtrack, regardless of whether we matched.
    m_offset = start.offset;
    m_column = start.column;
    m_line = start.line;

    while (!cache.empty()) {
        in.putback((char) cache.front());
        cache.pop_front();
    }

    return true;
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

manda::parsing::source_span manda::parsing::string_scanner::last_span() const {
    return m_last_span;
}
