//
// Created by irchit on 3/30/2023.
//

#include "iteratorVectorDinamic.h"

IteratorVectorDinamic::IteratorVectorDinamic(const VectorDinamic& _v) : v(_v) {
    /*
     * * Constructorul clasei IteratorVectorDinamic
     * * Complexitatea este theta(1)
     */
    this->pozitie = 0;
}

void IteratorVectorDinamic::prim() {
    /*
     * * Mutarea iteratorului la inceputul vectorului
     * * Complexitatea este theta(1)
     */
    this->pozitie = 0;
}

bool IteratorVectorDinamic::valid() const{
    /*
     * * Verifica daca iteratorul este valid
     * * Complexitatea este theta(1)
     */
    return (this->pozitie < this->v.dim());
}

TElem IteratorVectorDinamic::element() const{
    /*
     * * Returneaza elementul de pe pozitia curenta
     * * Complexitatea este theta(1)
     */
    if (this->valid())
        return this->v.element(this->pozitie);
    return -1;
}

void IteratorVectorDinamic::urmator() {
    /*
     * * Mutarea iteratorului la urmatoarea pozitie
     * * Complexitatea este theta(1)
     */
    if (this->valid())
        this->pozitie++;
}
