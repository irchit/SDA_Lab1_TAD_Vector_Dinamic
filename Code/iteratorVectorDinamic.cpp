//
// Created by irchit on 3/30/2023.
//

#include "iteratorVectorDinamic.h"

IteratorVectorDinamic::IteratorVectorDinamic(const VectorDinamic& _v) : v(_v) {
    this->pozitie = 0;
}

void IteratorVectorDinamic::prim() {
    this->pozitie = 0;
}

bool IteratorVectorDinamic::valid() const{
    return (this->pozitie < this->v.dim());
}

TElem IteratorVectorDinamic::element() const{
    if (this->valid())
        return this->v.element(this->pozitie);
    return -1;
}

void IteratorVectorDinamic::urmator() {
    if (this->valid())
        this->pozitie++;
}
