#include "cola.h"

bool Cola::isEmpty(){
    return front == nullptr;
}

void Cola::encolar(Pedido *pedido){
    if (isEmpty())
        front = new Nodo(pedido);
    else {
        Nodo *actual = front;
        while (actual->nxt != nullptr) {
            actual = actual->nxt;
        }
        Nodo *nuevo = new Nodo(pedido);
        actual->nxt = nuevo;
    }
}


Nodo *Cola::desencolar(){
    if (isEmpty())
        return nullptr;
    else {
        Nodo *borrado = front;
        front = front->nxt;
        borrado->nxt = nullptr;
        return borrado;
    }
}

Nodo *Cola::verFront(){
    return front;
}
