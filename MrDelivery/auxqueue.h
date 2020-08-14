#ifndef AUXQUEUE_H
#define AUXQUEUE_H
#include <QString>
struct NodoAUX{
    QString vert;
    NodoAUX *nxt;

    //Constr.
    NodoAUX(QString vert){
        this->nxt = nullptr;
        this->vert = vert;
    }
};

struct AuxQueue{
    //Attr.

    AuxQueue(){
        front = nullptr;
    }
    NodoAUX *front;

    //Methods
    void encolar(QString v);
    NodoAUX *desencolar();
    NodoAUX *verFront();
    bool isEmpty();
    void print();
};

#endif // AUXQUEUE_H
