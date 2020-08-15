#ifndef VISITEDLIST_H
#define VISITEDLIST_H
#include <QString>


struct VisitedNode{

    int id;
    bool visited;
    VisitedNode* nxt;

    VisitedNode();
    VisitedNode(int id);

};

struct VisitedList{

    VisitedNode* first;

    VisitedList();

    void add(int id);
    VisitedNode* getFirst(); //Devuelve el primero sin visitar
    bool isComplete(); //True = No quedan nodos sin visitar
    bool isHere(int id); //True = Ya esta en la lista
    void setVisited(int id); //Cambia el estado a true del nodo
};

#endif // VISITEDLIST_H
