#ifndef GRAFO_H
#define GRAFO_H
#include <QString>
#include "auxqueue.h"
#include "visitedlist.h"
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
    int matrizCosto[100][100];
    double matrizDistancia[100][100];
    double matrizMinutos[100][100];
    bool matrizStates[100][100];
    QString vertices[100];
    bool visitados[100];
    int cantidadVertices;


    Grafo();

    //Methods
    int indexOfVertice(QString);
    void agregarVertice(QString);
    void agregarArista(QString origen, QString destino, bool activo, int peso,double km,double minutos);
    void imprimir();
    int minVertex (int[]);
    void limpiarVisitados();
    void warshall_floyd();

    //Funciones
    QString printGrafo();
    //Costos hacia
    QString CostosHacia(QString vertice);
    int* inializarDC();
    //Recorrido por Profundidad
    QString recorridoProfundidad(QString vertice);
    //Recorrido por Anchura
    QString recorridoAnchura(QString vertice);
    bool verifyConnection(QString v1,QString v2);
    //Desactiva vertices
    void desacVertices(QString v);
    //Desactiva aristas
    void desacAristas(QString v1,QString v2);
    //Saber si un vertice tiene camino hacia los demas vertices del grafo
    bool hasPath(int vertex);
    //Saber si el grafo es conexo (Todos los vertices tienen camino a los demas caminos)
    bool hasPath();
    //Compara un VisitedList con el array de vertices
    bool compareLists(VisitedList* visitados);

};

#endif // GRAFO_H
