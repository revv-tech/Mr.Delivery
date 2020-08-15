#ifndef COLA_H
#define COLA_H
#include "grafo.h"
#include <QMutex>
struct Nodo{
    Grafo *pedido;
    Nodo *nxt;

    //Constr.
    Nodo(Grafo *pedido){
        this->pedido = pedido;
        this->nxt = nullptr;
    }
};
struct Cola{
    Nodo *front;
    QMutex *m;

    Cola(){}
    Cola(QMutex *m){
        front = nullptr;
        this->m = m;
    }

    //Methods
    void encolar(Grafo *pedido);
    Nodo *desencolar();
    Nodo *verFront();
    bool isEmpty();
    void print();
};

#endif // COLA_H
