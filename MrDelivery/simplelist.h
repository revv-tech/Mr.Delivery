#ifndef SIMPLELIST_H
#define SIMPLELIST_H
#include <QString>
struct Node{
    Node *nxt;
    QString v;
    int costo;
    Node(QString v, int costo){
        this->nxt = nullptr;
        this->costo = costo;
        this->v = v;
    }
};

struct SimpleList{
    Node *first, *last;
    SimpleList();
    // encabezados de funcion
    void insertarAlInicio (QString v,int costo);
    void insertarAlFinal(QString v,int costo);
    Node*buscar(QString v);
    Node* borrarAlInicio(void);
    int getValue();
};

#endif // SIMPLELIST_H
