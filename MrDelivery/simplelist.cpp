#include "simplelist.h"

SimpleList::SimpleList()
{
    last = first = nullptr;
}

void SimpleList::insertarAlInicio(Path *camino){
    if (first == nullptr)
        last = first = new Node(camino);
    else {
        Node *nuevo = new Node(camino);
        nuevo->nxt = first;
        first = nuevo;
    }
}
