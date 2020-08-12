#ifndef GRAFO_H
#define GRAFO_H
#include <QString>

struct Pedido{
    QString origen;
    QString destino;
    bool activo;
    int costo;
    double km;
    double tiempo;

    Pedido(QString origen, QString destino, int costo, double km, double tiempo){
        this->origen = origen;
        this->destino = destino;
        this->costo = costo;
        this->km = km;
        this->activo = true;
        this->tiempo = tiempo;

    }
};


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
    Pedido* matriz[100][100];
    QString vertices[100];
    bool visitados[100];
    int cantidadVertices;

    Grafo();

    //Methods
    int indexOfVertice(QString);
    void agregarVertice(QString);
    void agregarArista(QString, QString, Pedido*);
    void imprimir();
    int minVertex (int[]);
    int* dijkstra(int ) ;
    void limpiarVisitados();
    void warshall_floyd();

};

#endif // GRAFO_H
