#include "auxqueue.h"
bool AuxQueue::isEmpty(){
    return front == nullptr;
}
void AuxQueue::encolar(QString v){
    if (isEmpty())
        front = new NodoAUX(v);
    else {
        NodoAUX *actual = front;
        while (actual->nxt != nullptr) {
            actual = actual->nxt;
        }
        NodoAUX *nuevo = new NodoAUX(v);
        actual->nxt = nuevo;
    }
}


NodoAUX *AuxQueue::desencolar(){
    if (isEmpty())
        return nullptr;
    else {
        NodoAUX *borrado = front;
        front = front->nxt;
        borrado->nxt = nullptr;
        return borrado;
    }
}
NodoAUX *AuxQueue::verFront(){
    return front;
}
