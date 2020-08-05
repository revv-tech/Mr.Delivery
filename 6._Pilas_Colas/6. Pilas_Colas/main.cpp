#include "estructuras.h"


int main(int argc, char *argv[])
{
    
    Pila *p = new Pila();
//    
//    p->push(1);
//    p->push(2);
//    p->push(3);
//    p->push(4);
//    p->push(5);
//    p->imprimir();
//    p->pop();
//    p->pop();
//    p->imprimir();
//    cout << p->peek()->dato << endl;
//    p->imprimir();

//    p->push(20);
//    p->push(15);
//    p->push(10);
//    p->push(5);
//    p->imprimir();
//    
//    Nodo * tope = p->peek();
//    cout <<"Peek: "<< tope->dato<< endl;
//    
//    cout << p->pop()->dato << endl;
//    cout << p->pop()->dato << endl;
//    p->imprimir();
//
//
    Cola * c = new Cola();
    c->encolar(1);
    c->encolar(2);
    c->encolar(3);
    c->encolar(4);
    c->imprimir();


    cout << "Se antendio el cliente: "<<c->desencolar()->dato<<endl;
    cout << "Se antendio el cliente: "<<c->desencolar()->dato<<endl;
    c->imprimir();
//    
    system("PAUSE");
    return EXIT_SUCCESS;
}



