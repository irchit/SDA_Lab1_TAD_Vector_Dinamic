#include <iostream>
#include <cstring>
#include <vector>
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
    v.eliminaIntre(1, 3);
    assert(v.dim() == 2);
    int i[5] = {-1, 3, 1, 1, 1};
    int j[5] = {1, 1, -1, 3, 0};
    for (int I = 0; I < 5; I ++)
        try{
            v.eliminaIntre(i[I], j[I]);
        }catch(int error){
            assert(error == -1);
        }
}
