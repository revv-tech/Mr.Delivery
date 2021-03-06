#ifndef GRAFO_H
#define GRAFO_H
#include <QString>
#include "auxqueue.h"
#include "simplelist.h"
#include "visitedlist.h"
#include <QQueue>
#include <list>
#include<iostream>
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
    bool matrizStatesCHECKER[100][100];
    QString vertices[100];
    bool visitados[100];
    int cantidadVertices;
    bool pathExist;
    QList<int> *adj;
    //AVanzar
    int costo = 0;
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
    //Avanzar
    QString avanzar(QString v1,QString v2);
    //Get Paths
    SimpleList *getPaths(QString vertice, QString destino);
    int getPathsAux(int v1, int v2, int path[],int index);
    //Retorna el camino mas eficiente segun un int parametro y 2 ints para el vertice de inicio y llegada
    QString pathFrom(int start, int end, int idx);
    //Saca el vertice con menos distancia
    int minDistance(int dist[], bool sptSet[]);

};

#endif // GRAFO_H
