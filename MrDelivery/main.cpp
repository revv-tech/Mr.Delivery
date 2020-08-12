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
    std::string utf8_text = file.toUtf8().constData();
    json j = json::parse(utf8_text);
    std::cout << j["vertices"];
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}
