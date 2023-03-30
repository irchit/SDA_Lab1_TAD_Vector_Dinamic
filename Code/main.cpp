#include <iostream>
#include "tests.h"

void testAll();

int main() {
    testAll();
    std::cout << "OK!\n";
    return 0;
}

void testAll() {
    testScurt();
    testExtins();
}
