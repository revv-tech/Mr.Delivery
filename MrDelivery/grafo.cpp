#include "grafo.h"
#include <QDebug>
//Constructor
Grafo::Grafo()
{
    max = 100;
    cantidadVertices = 0;

    for (int i = 0 ; i < 100 ; i++){
        vertices[i] = "";
        visitados[i] = 0;

        for (int j = 0 ; j < 100 ; j++){
            matriz[i][j] = nullptr;
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
void Grafo::agregarArista(QString origen, QString destino, Pedido *peso)
   {
       int orig = indexOfVertice(origen);
       int dest = indexOfVertice(destino);

       if (orig != -1 && dest != -1)
       {
           matriz[dest][orig] = peso;
       }
   }

//limpiar visitados
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
            if (!visitados[i] && distanciasCortas[i] < x)
            {
                y = i;
                x = distanciasCortas[i];
            }
        }
        qDebug() <<"min: " << y << "  valor = " << x <<Qt::endl;
        return y;// RETORNA LA POSICION DEL MENOR
    }


