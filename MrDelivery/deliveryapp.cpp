#include "deliveryapp.h"

DeliveryApp::DeliveryApp(){}

void DeliveryApp::preStart(QString path){
    this->loader = new ThreadLoader();
    this->mutex = new QMutex();
    this->path = path;
    this->cola = new Cola(mutex);

}


void DeliveryApp::start(){
    loader->__init__(cola,path);
    loader->start();
}


void DeliveryApp::changeGraph(){
    cola->m->lock();
    Grafo *nuevo = cola->desencolar()->pedido;
    this->tmp = nuevo;
    this->tmpOriginal = nuevo;
    cola->m->unlock();
}
