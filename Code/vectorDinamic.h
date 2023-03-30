//
// Created by irchit on 3/30/2023.
//

#ifndef CODE_VECTORDINAMIC_H
#define CODE_VECTORDINAMIC_H
//tip de data generic (pentru moment este intreg)

typedef int TElem;

class IteratorVectorDinamic;

class VectorDinamic {

private:
    int capacitate;
    int dimensiune;
    TElem *elemente;
    // redimensionare
    void redim();

public:
    explicit VectorDinamic(int);
    [[nodiscard]] int dim() const;
    [[nodiscard]] TElem element(int) const;
    [[nodiscard]] TElem modifica(int, TElem);
    void adaugaSfarsit(TElem);
    void adauga(int, TElem);
    [[nodiscard]] TElem sterge(int);
    IteratorVectorDinamic iterator();
    ~VectorDinamic();
};

#endif //CODE_VECTORDINAMIC_H
