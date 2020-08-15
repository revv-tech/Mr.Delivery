#include "mainwindow.h"

#include <QApplication>
#include "threadloader.h"
#include <iostream>
#include "filemanager.h"
#include <fstream>
#include <QJsonArray>

int main(int argc, char *argv[])
{
    /*
    ThreadLoader *thread = new ThreadLoader();
    thread->__init__(nullptr,"/home/rev/Documents/GitHub/Mr.Delivery");
    thread->run();
    */
    Grafo* file = FileManager::readJson("/home/thelopezepol/Escritorio/C++/ED S1 2020/Mr.Delivery/DirectoryJson/pconexo.json");
    qDebug() << file->hasPath();
    //qDebug() << file->recorridoAnchura("A");
    //qDebug() << file->recorridoProfundidad("B");

    /*QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();*/
}
