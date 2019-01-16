#include "string_scanner.h"

manda::parsing::string_scanner::string_scanner(std::istream &in) : in(in) {}

bool manda::parsing::string_scanner::done() const {
    return in.fail() || in.eof();
}

unsigned long manda::parsing::string_scanner::line() const {
    return m_line;
}

unsigned long manda::parsing::string_scanner::column() const {
    return m_column;
}

