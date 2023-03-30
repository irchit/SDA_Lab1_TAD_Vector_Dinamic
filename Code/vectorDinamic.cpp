//
// Created by irchit on 3/30/2023.
//
#include "VectorDinamic.h"
#include "IteratorVectorDinamic.h"
#include <exception>

using namespace std;

void VectorDinamic::redim() {
    this->capacitate *= 2;
    auto *aux = new TElem[this->capacitate];
    for (int i = 0; i < this->dimensiune; i++)
        aux[i] = this->elemente[i];
    delete[] this->elemente;
    this->elemente = aux;
}

VectorDinamic::VectorDinamic(int cp) {
    this->capacitate = cp;
    this->dimensiune = 0;
    this->elemente = new TElem[cp];
}

VectorDinamic::~VectorDinamic() {
    delete[] this->elemente;
}

int VectorDinamic::dim() const{
    return this->dimensiune;
}

TElem VectorDinamic::element(int i) const{
    if (i >= 0 && i < this->dimensiune)
        return this->elemente[i];
    return -1;
}

void VectorDinamic::adaugaSfarsit(TElem e) {
    if (this->dimensiune == this->capacitate)
        this->redim();
    this->elemente[this->dimensiune] = e;
    this->dimensiune++;
}

void VectorDinamic::adauga(int i, TElem e) {
    if (i >= 0 && i <= this->dimensiune)
    {
        if (this->dimensiune == this->capacitate)
            this->redim();
        for (int j = this->dimensiune; j > i; j--)
            this->elemente[j] = this->elemente[j - 1];
        this->elemente[i] = e;
        this->dimensiune++;
    }
}

TElem VectorDinamic::modifica(int i, TElem e) {
    if (i >= 0 && i < this->dimensiune) {
        TElem old = this->elemente[i];
        this->elemente[i] = e;
        return old;
    }
    return -1;
}

TElem VectorDinamic::sterge(int i) {
    if (i >= 0 && i < this->dimensiune) {
        TElem old = this->elemente[i];
        for (int j = i; j < this->dimensiune - 1; j++)
            this->elemente[j] = this->elemente[j + 1];
        this->dimensiune--;
        return old;
    }
    return -1;
}

IteratorVectorDinamic VectorDinamic::iterator() {
    return IteratorVectorDinamic(*this);
}





