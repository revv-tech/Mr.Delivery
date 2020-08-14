#ifndef COLA_H
#define COLA_H

struct Nodo{
    //Pedido *pedido;
    Nodo *nxt;

    //Constr.
    Nodo(){
        this->nxt = nullptr;
    }
};
struct Cola{
    Nodo *front;

    Cola(){
        front = nullptr;
    }

    //Methods
    //void encolar(Pedido *pedido);
    Nodo *desencolar();
    Nodo *verFront();
    bool isEmpty();
    void print();
};

#endif // COLA_H
