#ifndef SIMPLELIST_H
#define SIMPLELIST_H
#include <QString>
#include "path.h"
struct Node{
    Node *nxt;
    Path *camino;
    Node(Path *camino){
        this->nxt = nullptr;
        this->camino = camino;
    }
};

struct SimpleList{
    Node *first, *last;
    SimpleList();
    // encabezados de funcion
    void insertarAlInicio (Path *camino);
    Node*buscar(QString v);
    Node* borrarAlInicio(void);
    int getValue();
};

#endif // SIMPLELIST_H
