#include "mainwindow.h"

#include <QApplication>
#include "threadloader.h"
#include <iostream>
#include <jsoncpp/json/json.h>
#include <fstream>
int main(int argc, char *argv[])
{
    ThreadLoader *thread = new ThreadLoader();
    thread->__init__(nullptr,"/home/rev/Documents/GitHub/Mr.Delivery");
    Json::Reader reader;

    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}
