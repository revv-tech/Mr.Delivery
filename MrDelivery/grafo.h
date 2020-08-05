#ifndef GRAFO_H
#define GRAFO_H
#include <QString>
struct Vertice{
    int id;
    bool visitado;
    Vertice(int id){
        this->id = id;
        this->visitado = false;
    }
};

struct Grafo
{
    int max;
    int matriz[100][100];
    int vertices[100];
    bool visitados[100];
    int cantidadVertices;

    Grafo();

    //Methods
    int indexOfVertice(int);
    void agregarVertice(int);
    void agregarArista(int, int, int);
    void imprimir();
    int minVertex (int[]);
    int* dijkstra(int ) ;
    void limpiarVisitados();
    void warshall_floyd();

};

#endif // GRAFO_H
