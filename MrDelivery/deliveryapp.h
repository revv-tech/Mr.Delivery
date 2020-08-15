#ifndef DELIVERYAPP_H
#define DELIVERYAPP_H
#include "threadloader.h"
#include "cola.h"
#include <QMutex>
struct DeliveryApp{
    //Attr.
    QMutex *mutex;
    ThreadLoader *loader;
    Grafo *tmp;
    Grafo *tmpOriginal;
    Cola * cola;
    bool runner;
    DeliveryApp();
    QString path;
    //Methods
    void preStart(QString path);
    void start();
    void pauseEverything();
    void changeGraph();

};

#endif // DELIVERYAPP_H
