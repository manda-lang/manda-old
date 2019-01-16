#include <iostream>
#include <sstream>
#include "string_scanner.h"

using namespace manda::parsing;
using namespace std;

int main() {
    istringstream ss("hello manda");
    string_scanner scanner(ss);

    cout << scanner.scan("hell") << endl;
    cout << scanner.last_span() << endl;
}