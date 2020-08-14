#ifndef GRAFO_H
#define GRAFO_H
#include <QString>
#include <dlinklist.h>
#include "auxqueue.h"
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
    float matrizDistancia[100][100];
    float matrizMinutos[100][100];
    bool matrizStates[100][100];
    QString vertices[100];
    bool visitados[100];
    int cantidadVertices;


    Grafo();

    //Methods
    int indexOfVertice(QString);
    void agregarVertice(QString);
    void agregarArista(QString origen, QString destino, int peso,float km,float minutos);
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

};

#endif // GRAFO_H
