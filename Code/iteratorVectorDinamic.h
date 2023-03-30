//
// Created by irchit on 3/30/2023.
//

#ifndef CODE_ITERATORVECTORDINAMIC_H
#define CODE_ITERATORVECTORDINAMIC_H

#include "VectorDinamic.h"

class IteratorVectorDinamic {

    friend class VectorDinamic;
private:

    //constructorul primeste o referinta catre Container
    //iteratorul va referi primul element din container

    explicit IteratorVectorDinamic(const VectorDinamic&);

    //contine o referinta catre containerul pe care il itereaza
    const VectorDinamic& v;

    int pozitie;

public:

    //reseteaza pozitia iteratorului la inceputul containerului
    void prim();

    //muta iteratorul in container
    // arunca exceptie daca iteratorul nu e valid
    void urmator();

    //verifica daca iteratorul e valid (indica un element al containerului)
    [[nodiscard]] bool valid() const;

    //returneaza valoarea elementului din container referit de iterator
    //arunca exceptie daca iteratorul nu e valid
    [[nodiscard]] TElem element() const;

};

#endif //CODE_ITERATORVECTORDINAMIC_H
