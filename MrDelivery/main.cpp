#include "mainwindow.h"

#include <QApplication>
#include "threadloader.h"
#include <iostream>
#include <json.hpp>
#include "filemanager.h"
#include <fstream>
using json = nlohmann::json;
int main(int argc, char *argv[])
{
    //ThreadLoader *thread = new ThreadLoader();
    //thread->__init__(nullptr,"/home/rev/Documents/GitHub/Mr.Delivery");
    QString file = FileManager::readFile("/home/rev/Documents/GitHub/Mr.Delivery/DirectoryJson/p.json");

    json j = json::parse("{ \"vertices\" : [\"A\",\"B\",\"C\",\"D\",\"E\"], \"aristas\" : [    {\"origen\": \"A\" ,\"destino\": \"B\", \"activo\" : true, \"costo\": 20, \"km\": 2.7, \"minutos\" : 5},  {\"origen\": \"A\" ,\"destino\": \"C\", \"activo\" : true, \"costo\": 20, \"km\": 1.7, \"minutos\" : 2},  {\"origen\": \"A\" ,\"destino\": \"B\", \"activo\" : true, \"costo\": 20, \"km\": 0.7, \"minutos\" : 3}  ]  }");
    std::cout << j["aristas"][0];
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}
