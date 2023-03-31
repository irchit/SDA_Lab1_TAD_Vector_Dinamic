#include <iostream>
#include "tests.h"

void testAll();

void testCerintaLab();

int main() {
    testAll();
    std::cout << "OK!\n";
    std::cout << "Enter to close";
    std::cin.get();
    return 0;
}

void testAll() {
    testScurt();
    testExtins();
    testCerintaLab();
}

void testCerintaLab() {
    VectorDinamic v(4);
    v.adaugaSfarsit(5);
    v.adaugaSfarsit(2);
    v.adaugaSfarsit(2);
    v.adaugaSfarsit(2);
    v.adaugaSfarsit(4);
    assert(v.elementeUnice(0, 4) == 3);
}
