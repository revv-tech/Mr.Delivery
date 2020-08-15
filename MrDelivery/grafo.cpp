#include "grafo.h"
#include <QDebug>
#include <QString>
//Constructor
Grafo::Grafo()
{
    max = 100;
    cantidadVertices = 0;

    for (int i = 0 ; i < 100 ; i++){
        vertices[i] = "";
        visitados[i] = 0;

        for (int j = 0 ; j < 100 ; j++){
            matrizCosto[i][j] = 0;
            matrizDistancia[i][j] = 0.0;
            matrizMinutos[i][j] = 0.0;
            matrizStates[i][j] = false;
        }
    }
}
//AGREGAR VERTICE
void Grafo::agregarVertice(QString v)
{
    // si hay campo y v no est'a en el grafo
    if (cantidadVertices < max && indexOfVertice(v) == -1)
    {
        vertices[cantidadVertices] = v;
        cantidadVertices++;
    }
}

//Index de Un Vertice
int Grafo::indexOfVertice(QString v)
{
    for (int i = 0; i < cantidadVertices; i++) {
        if (vertices[i] == v)
            return i;
    }

    return -1;
}
// Agregar Arista
void Grafo::agregarArista(QString origen, QString destino, bool activo, int peso,double km,double minutos){

    int orig = indexOfVertice(origen);
    int dest = indexOfVertice(destino);

    if (orig != -1 && dest != -1){
        matrizCosto[orig][dest] = peso;
        matrizDistancia[orig][dest] = km;
        matrizMinutos[orig][dest] = minutos;
        matrizStates[orig][dest] = activo;
    }
}

void Grafo::limpiarVisitados()
{
    for (int i=0; i < cantidadVertices;i++)
        visitados[i] = false;
}

// min vertice
int Grafo::minVertex (int * distanciasCortas)
{
    int x = 999999;
    int y = -1;
    // RECORRE EL ARREGLO DE DISTANCIAS CORTAS BUSCANDO EL MENOR NO VISITADO
    for (int i = 0; i < cantidadVertices; i++) {
        qDebug() <<distanciasCortas[i] << "   ";
        // CONDICION PARA OBTENER NO VISITADO Y EL MENOS DE TODOS
        if (!visitados[i] and distanciasCortas[i] < x)
        {
            y = i;
            x = distanciasCortas[i];
        }
    }
    qDebug() <<"min: " << y << "  valor = " << x <<Qt::endl;
    return y;// RETORNA LA POSICION DEL MENOR
}

void Grafo::imprimir(){
    qDebug() <<" \t";
    for (int i = 0; i < cantidadVertices; i++) {
        qDebug() <<vertices[i]<<"\t";
    }

    qDebug() <<Qt::endl;

    for (int i = 0; i < cantidadVertices; i++) {
        qDebug() <<vertices[i]<<"\t";
        for (int j = 0; j < cantidadVertices; j++) {
            qDebug() << "";
            qDebug() <<"Costo: "<<  matrizCosto[i][j]<< "\t";
            qDebug() <<"Distancia: "<<  matrizDistancia[i][j]<< "\t";
            qDebug() <<"Minutos: "<<  matrizMinutos[i][j]<< "\t";
            qDebug() <<"Estado: "<<  matrizStates[i][j]<< "\t";
            qDebug() <<"";
        }
        qDebug() << Qt::endl;
    }
}

QString Grafo::printGrafo(){
    QString msg = "Vertices: ";
    for (int i = 0; i < cantidadVertices; i++) {
        msg = msg + vertices[i] +" ";
    }
    msg = msg + "\n";
    for (int i = 0; i < cantidadVertices; i++) {
        msg = msg + vertices[i] +"\n";
        for (int j = 0; j < cantidadVertices; j++) {
            msg = msg + "Arista con: " + vertices[j];
            msg = msg + "\n";
            msg = msg + "Costo: " +  QString::number(matrizCosto[i][j]) +  "\n";
            msg = msg + "Distancia: " +  QString::number(matrizDistancia[i][j]) +  "\n";
            msg = msg + "Minutos: " +  QString::number(matrizMinutos[i][j]) +  "\n";
            msg = msg + "Estado: " +  QString::number(matrizStates[i][j]) +  "\n";
            msg = msg + "\n";

        }

    }
    return msg;
}


//Costos Hacia
QString Grafo::CostosHacia(QString vertice){
    QString msg = "";
    // arreglo para llevar los nodos visitados
    limpiarVisitados();
    // arreglo que almacena las distancias más cortas desde el vertice
    int distanciasCortas[100];
    // obtiene el índice del vertice en la matriz
    int node = indexOfVertice(vertice);
    // coloca visitado el nodo inicial
    visitados[node] = true;
    distanciasCortas[node] = 0;
    for (int i = 0; i < cantidadVertices; i++) {
        if (matrizCosto[i][node] != 0)
            // como sí hay camino, coloca el peso
            distanciasCortas[i] = matrizCosto[i][node];
        else /// si no, infinito
            distanciasCortas[i] = 999999;
    }
    for (int i = 0 ; i < (cantidadVertices-1) ; i++){
        int next = minVertex(distanciasCortas);
        visitados[next] = true;
        for (int j = 0 ; j < cantidadVertices ; j++){
            int d = distanciasCortas[next] + matrizCosto[j][next];
            if (distanciasCortas[j] > d and matrizCosto[j][next] > 0)
                distanciasCortas[j] = distanciasCortas[next] + matrizCosto[j][next];
        }
    }


    for (int i = 0; i < cantidadVertices; i++){
        msg = msg + vertices[i] + " " +  QString::number(distanciasCortas[i]) + "\n";
    }
    return msg;
}
bool Grafo::verifyConnection(QString v1, QString v2){
    int i = indexOfVertice(v1);
    int j = indexOfVertice(v2);

    if (matrizStates[i][j])
        return true;
    return false;
}
//Recorrido por Anchura
QString Grafo::recorridoAnchura(QString vertice){
    QString msg = "";
    //Marcar todos los vertices como no visitados
    limpiarVisitados();
    //Obtiene el nodo
    int node = indexOfVertice(vertice);
    //Nuevo array para BFS
    AuxQueue *queue = new AuxQueue();
    // coloca visitado el nodo inicial
    visitados[node] = true;
    queue->encolar(vertice);
    msg = "Se empieza desde " + vertice + "\n";
    while(!queue->isEmpty()){
        NodoAUX *front = queue->desencolar();

        msg = msg + front->vert + "\n";

        for (int w = 1 ; w<cantidadVertices ; ++w){
            qDebug() << vertices[w] + "  " + front->vert;
            if (verifyConnection(front->vert,vertices[w]) and matrizStates[node][w]){
                queue->encolar(vertices[w]);
                visitados[w] = true;
            }
        }

    }
    return msg;
}

//Recorrido Por Profundidad

QString Grafo::recorridoProfundidad(QString vertice){
    QString msg = "";
    //Marcar todos los vertices como no visitados
    limpiarVisitados();
    //Obtiene el nodo
    int node = indexOfVertice(vertice);
    //Nuevo array para DFS
    AuxQueue *queue = new AuxQueue();

    // coloca visitado el nodo
    visitados[node] = true;
    queue->encolar(vertice);

    while(!queue->isEmpty()){

    }
    return msg;
}

//Desactiva Vertices
void Grafo::desacVertices(QString v){
    int i = indexOfVertice(v);
    for (int j = 0 ; j < cantidadVertices ; ++j){
        if (verifyConnection(v,vertices[i]))
            matrizStates[i][j] = !matrizStates[i][j];
    }
}
//Desactiva Aristas
void Grafo::desacAristas(QString v1, QString v2){
    int i = indexOfVertice(v1);
    int j = indexOfVertice(v2);
    if (verifyConnection(v1,v2))
        matrizStates[i][j] = !matrizStates[i][j];
}

//
bool Grafo::hasPath(int vertex){
    VisitedList* visitados = new VisitedList();
    visitados->add(vertex);
    while (!visitados->isComplete()){
        vertex = visitados->getFirst()->id;
        for (int i = 0; i < cantidadVertices; i++){
            if (matrizStates[vertex][i] == true && !visitados->isHere(i))
                visitados->add(i);
        }
        visitados->setVisited(vertex);
    }
    return compareLists(visitados);
}

bool Grafo::compareLists(VisitedList *visitados){
    for (int i = 0; i < cantidadVertices; i++){
        if (!visitados->isHere(i)){
            return false;
        }
    }
    return true;
}

bool Grafo::hasPath(){
    for (int i = 0; i <= cantidadVertices; i++){
        if (!hasPath(i))
            return false;
    }
    return true;
}


