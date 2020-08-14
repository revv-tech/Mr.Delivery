#include "mainwindow.h"

#include <QApplication>
#include "threadloader.h"
#include <iostream>
#include "filemanager.h"
#include <fstream>
#include "grafo.h"

int main(int argc, char *argv[])
{
    //ThreadLoader *thread = new ThreadLoader();
    //thread->__init__(nullptr,"/home/rev/Documents/GitHub/Mr.Delivery");
    QString file = FileManager::readFile("/home/rev/Documents/GitHub/Mr.Delivery/DirectoryJson/p.json");
    //Grafo
    Grafo *prueba = new Grafo();
    prueba->agregarVertice("A");
    prueba->agregarVertice("B");
    prueba->agregarVertice("C");
    prueba->agregarVertice("D");
    prueba->agregarVertice("E");
    prueba->agregarVertice("F");
    prueba->agregarVertice("G");
    prueba->agregarVertice("H");
    prueba->agregarVertice("I");
    prueba->agregarArista("A","B",20,4.0,5.0);
    prueba->agregarArista("A","C",10,8.0,5.0);
    prueba->agregarArista("B","E",5,8.0,5.0);
    prueba->agregarArista("E","F",28,7.0,5.0);
    prueba->agregarArista("F","I",21,9.0,5.0);
    prueba->agregarArista("C","D",40,7.0,5.0);
    prueba->agregarArista("D","G",2,6.0,5.0);
    prueba->agregarArista("G","H",10,2.0,5.0);
    prueba->agregarArista("H","I",8,10.0,5.0);
    //qDebug() << p10->km;
    prueba->imprimir();
    //qDebug() << prueba->CostosHacia("H");
    qDebug() << prueba->recorridoAnchura("F");
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}
