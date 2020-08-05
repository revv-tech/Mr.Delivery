
#include "estructuras.h"


void Cola::encolar (int dato)
{
if (vacia())
         frente = new Nodo (dato);
      else 
      {
            // referencia al primero para recorrer la lista
            Nodo* actual = frente;
            // recorre la lista hasta llegar al penultimo nodo
            while (actual->siguiente != NULL)
                          actual = actual->siguiente; 
              
            // Crea nuevo nodo, lo apunta con uN  
            Nodo* nuevo = new Nodo (dato);
            //le quita el enlace al que era ultimo
            actual->siguiente = nuevo;
        }
}

// funcion que elimina el primer elemento de las lista
// entradas: no tiene
// salidas: el puntero al primer nodo. Este puntero
// en siguiente apuntara a null. No se libera memoria

Nodo* Cola::desencolar(void)
{
      // si no hay elementos, no borra nada, retorna null
      if (vacia())
      {
         return NULL;
      }
      else
      {
          // un puntero que apunta al nodo que se
          // "despegara" de la lista y se retorna
          Nodo* borrado = frente;     
          // pN se pasa al segundo de la lista
          // porque el primero se eliminara
          frente = frente->siguiente;
          // el nodo borrado, se debe despegar
          // entonces siguiente apunta a null y no
          // al segundo de la lista que ahora es pN
          borrado->siguiente = NULL;
          // aca se deberia liberar la memoria si no se
          // retornara el borrado
          return borrado;
      }
}

bool Cola::vacia (void)
{
     if (frente == NULL)
        return true;
     else
         return false;
}

void Cola::imprimir(void)
{
     cout << "Frente" << endl;
     // puntero temporal que avanza
     // por toda la lista
     // apunta a los mismo que pN
     Nodo *tmp = frente;
     
     // mientras tmp no sea nulo, avanza
     while (tmp != NULL)
     {
           // imprime el dato del nodo en el que esta tmp
           cout << tmp->dato << "  " << endl;
           // tmp avanza al siguiente nodo
           // esto no puede faltar porque se encicla
           tmp = tmp->siguiente;
     }
     cout << "Final" << endl;
}


Nodo* Cola::verFrente()
{
      return frente;      
}

