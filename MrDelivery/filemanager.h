#ifndef FILEMANAGER_H
#define FILEMANAGER_H


#include <QString>
#include <QFile>
#include <QTextStream>
#include <QDebug>
#include <QDir>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include "grafo.h"

/*
 * FILE MANAGER
 * Se encarga de administrar los archivos .txt, los sobreescribe, los lee,...
 */
struct FileManager {

public:
    FileManager();

    //LEE CADA LINEA DEL ARCHIVO
    static QString readFile(QString path);

    //LEE UN ARCHIVO .JSON
    static QJsonObject readJsonAux(QString path);

    //LEE Y CREA UN GRAFO SEGUN EL .JSON
    static Grafo* readJson(QString path);

    //VALIDA EL ESTADO DEL .JSON
    static bool isJsonOk(QJsonObject json);

    //DIVIDE CADA LINEA DEL .TXT Y LO TRANSFORMA EN UNA LISTA QSTRING
    static QStringList splitFile(QString text);

    //ESCRIBE DESPUES DE LA ULTIMA LINEA DE UN ARCHIVO
    static void writeFileA(QString string, QString path);

    //SOBRESCRIBE UN ARCHIVO
    static void writeFileN(QString string, QString path);

    //LEE EL DIRECTORIO, Y CREA UNA QStringList con los nombres de los archivos
    static QStringList seeDirectory(QString path);

    //CAMBIA LA UBICACION DE UN ARCHIVO
    static void fileRelocater(QString path,QString newPath, QString fileNamee);
};


#endif // FILEMANAGER_H
