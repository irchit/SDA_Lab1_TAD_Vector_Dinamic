//
// Created by irchit on 3/30/2023.
//
#include "VectorDinamic.h"
#include "IteratorVectorDinamic.h"
#include <exception>
#include <iostream>
#include <stdexcept>

using namespace std;

int VectorDinamic::elementeUnice(int st, int dr) const {
    /**
     * * Returneaza numarul de elemente unice din vector
     * * Complexitatea este theta(n^2)
     */
    if (st < 0 || dr >= this->dimensiune || st > dr)
        return -1;
    int nr = 0;
    for (int i = st; i <= dr; i++) {
        bool ok = true;
        for (int j = st; j < i; j++)
            if (this->elemente[i] == this->elemente[j])
                ok = false;
        if (ok)
            nr++;
    }
    return nr;
}

void VectorDinamic::redim() {
    /**
     * * Redimensioneaza vectorul de elemente
     * * Complexitatea este theta(n)
     */
    this->capacitate *= 2;
    auto *aux = new TElem[this->capacitate];
    for (int i = 0; i < this->dimensiune; i++)
        aux[i] = this->elemente[i];
    delete[] this->elemente;
    this->elemente = aux;
}

VectorDinamic::VectorDinamic(int cp) {
    /**
     * * Constructorul clasei VectorDinamic
     * * Complexitatea este theta(1)
     */
    this->capacitate = cp;
    this->dimensiune = 0;
    this->elemente = new TElem[cp];
}

VectorDinamic::~VectorDinamic() {
    delete[] this->elemente;
}

int VectorDinamic::dim() const{
    /**
     * * Returneaza dimensiunea vectorului
     * * Complexitatea este theta(1)
     */
    return this->dimensiune;
}

TElem VectorDinamic::element(int i) const{
    /**
     * * Returneaza elementul de pe pozitia i
     * * Complexitatea este theta(1)
     */
    if (i >= 0 && i < this->dimensiune)
        return this->elemente[i];
    return -1;
}

void VectorDinamic::adaugaSfarsit(TElem e) {
    /**
     * * Adauga un element la sfarsitul vectorului
     * * Complexitatea este theta(1) in cazul in care nu este nevoie de redimensionare
     * * Complexitatea este theta(n) in cazul in care este nevoie de redimensionare
     * * Complexitatea totala este O(n)
     */
    if (this->dimensiune == this->capacitate)
        this->redim();
    this->elemente[this->dimensiune] = e;
    this->dimensiune++;
}

void VectorDinamic::adauga(int i, TElem e) {
    /**
     * * Adauga un element pe pozitia i
     * * Complexitatea este theta(n)
     */
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
    /**
     * * Modifica elementul de pe pozitia i
     * * Complexitatea este theta(1)
     */
    if (i >= 0 && i < this->dimensiune) {
        TElem old = this->elemente[i];
        this->elemente[i] = e;
        return old;
    }
    return -1;
}

TElem VectorDinamic::sterge(int i) {
    /**
     * * Sterge elementul de pe pozitia i
     * * Complexitatea este theta(n)
     */
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

void VectorDinamic::eliminaIntre(int i, int j) {
    /**
     * Conditii:
     *      pre:
     *          vector -> VectorDinamic, unde dimensiunea lenght=vector.dim()
     *          i, j -> int
     *
     *      post:
     *          vector' -> VectorDinamic, unde lenght' = lenght - (j - i + 1)
     *
     * Pseudocod:
     *      eliminaIntre(vector, i, j):
     *      |    daca i < 0 sau j < 0 sau i >= vector.dimensiune sau j >= vector.dimensiune atunci:
     *      |    |   arunca exceptie "Pozitii invalide"
     *      |    ++
     *      |    daca i > j atucni:
     *      |    |   arunca exceptie "Pozitii invalide"
     *      |    ++
     *      |    pentru k <- j, i, -1 executa:
     *      |    |   sterge(vector, k)
     *      |    ++
     *      ++
     *
     * Complexitate:
     *      Best case (i == j || j < i || i < 0 || j < 0 || i >= vector.dim() || j >= vector.dim()): theta(1)
     *      Worst case (i == 0 && j == vector.dim() - 1): theta(n)
     *      Avg case (i < j): theta(j - i) <=> theta(n)
     *
     *      Complexitate generala: O(n)
     */
    if (i < 0 || i >= this->dimensiune || j < 0 || j >= this->dimensiune)
        throw -1;
    if (i > j)
        throw -1;
    for (int k = j; k >= i; k--)
        this->sterge(k);
}





