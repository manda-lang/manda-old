#include <deque>
#include "string_scanner.h"

std::ostream &manda::parsing::operator<<(std::ostream &out, const manda::parsing::string_scanner_state &state) {
    out << state.line << ":" << state.column;
    return out;
}

std::ostream &manda::parsing::operator<<(std::ostream &out, const manda::parsing::source_span &span) {
    out << "{" << span.start << ", " << span.end << "}";
    return out;
}

manda::parsing::string_scanner::string_scanner(std::istream &in) : in(in) {
    m_line = 1;
    m_column = 0;
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

    return ch;
}

int manda::parsing::string_scanner::peek() const {
    return in.peek();
}

manda::parsing::string_scanner_state manda::parsing::string_scanner::state() const {
    return {m_line, m_column};
}

bool manda::parsing::string_scanner::scan(int ch) {
    if (in.peek() == ch) {
        read();
        return true;
    } else {
        return false;
    }
}

bool manda::parsing::string_scanner::scan(const std::string &str) {
    auto start = state();
    std::deque<int> cache;

    for (char desired : str) {
        auto actual = peek();

        if (actual != desired) {
            // If we didn't find the next character, backtrack.
            while (!cache.empty()) {
                in.putback((char) cache.front());
                cache.pop_front();
            }

            return false;
        } else {
            cache.push_back(read());
        }
    }

    // We found all characters. Set the last span.
    m_last_span = {start, state()};
    return true;
}

manda::parsing::source_span manda::parsing::string_scanner::last_span() const {
    return m_last_span;
}
