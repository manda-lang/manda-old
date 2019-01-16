#include <iostream>
#include <sstream>
#include "lexer.h"

using namespace manda::parsing;
using namespace std;

int main() {
    istringstream ss("hello manda");
    string_scanner scanner("strss", ss);
    lexer lex(scanner);

    lex.scan();

    cout << lex.errors().size() << endl;
}