#include "filemanager.h"

FileManager::FileManager(){}

QString FileManager::readFile(QString path){
    QString content = "";
    QFile inputFile(path);
    if (inputFile.open(QIODevice::ReadOnly | QIODevice::Text)){
        QTextStream in(&inputFile);
        while(!in.atEnd()){
            QString line = in.readLine();
            int word = 0;
            while(word < line.size()){
                if (line.data()[word] != '\t')
                    content.append(line.data()[word]);
                else
                    content.append(" ");
                word++;
            }
            content.append("");
        }
        inputFile.close();
    }
    else
        content = "ERROR - READ FILE ("+path+")";
    return content;
}

QStringList FileManager::splitFile(QString text){
    return text.split("");
}

void FileManager::writeFileA(QString string, QString path){
    QFile file(path);
    if (file.open(QIODevice::WriteOnly | QIODevice::Text | QIODevice::Append)){
        QTextStream stream(&file);
        stream << string << Qt::endl;
    } else
        qDebug() << "ERROR - WRITE FILE ("+path+")";
    file.close();
}

void FileManager::writeFileN(QString string, QString path){
    QFile file(path);
    if (file.open(QIODevice::WriteOnly | QIODevice::Text)){
        QTextStream stream(&file);
        stream << string << Qt::endl;

    } else
        qDebug() << "ERROR - WRITE FILE ("+path+")";
    file.close();
}

//LIST CREATOR DIRECTORY READER
/*
 * E: Un QString
 * S: QStringList
 * D: Recibe el path de un directorio, y crea una lista de strings con los nombres
 */
QStringList FileManager::seeDirectory(QString path){
    QStringList files;
    QDir directory(path);
    files = directory.entryList(QStringList() << "*.json" << "*.JSON",QDir::Files);
    return files;
}

// DIRECTORY RELOCATER
/*
 * E: Un QString
 * S: Void
 * D: Cambia un archivo de directorio
 */

void FileManager::fileRelocater(QString path,QString newPath, QString fileName){
    QDir directory(path);
    QDir newDirectory(fileName);
    if (directory.exists(fileName)){
        QFile::copy(path+"/"+fileName,newPath+"/"+fileName);
        directory.remove(fileName);
    }else
        qDebug() << "NO EXISTE EL ARCHIVO";

}

QJsonObject FileManager::readJsonAux(QString path){
    QString text;
    QFile file;
    file.setFileName(path);
    file.open(QIODevice::ReadOnly | QIODevice::Text);
    text = file.readAll();
    file.close();
    QJsonDocument document = QJsonDocument::fromJson(text.toUtf8());
    QJsonObject obj = document.object();

    return obj;
}

Grafo* FileManager::readJson(QString path){
    QJsonObject json = readJsonAux(path);
    Grafo* grafo = new Grafo();
    if(isJsonOk(json)){
        QJsonArray array = json["vertices"].toArray();
        for (int i = 0; i < array.size(); i++)
            grafo->agregarVertice(array[i].toString());
        array = json["aristas"].toArray();
        for (int i = 0; i < array.size(); i++){
            QJsonValue obj = array[i];
            grafo->agregarArista(obj["origen"].toString(), obj["destino"].toString(), obj["activo"].toBool(),obj["costo"].toInt(), obj["km"].toDouble(), obj["minutos"].toDouble());
        }
    }
    return grafo;
}

bool FileManager::isJsonOk(QJsonObject json){
    if (json.isEmpty()){
        qDebug() << "JSON - NO HAY INFORMACION EN EL ARCHIVO JSON";
        return false;
    }
    QJsonArray vertices = json["vertices"].toArray();
    if (vertices.isEmpty()){
        qDebug() << "JSON - NO HAY VERTICES PARA CREAR EL GRAFO";
        return false;
    }
    for (int i = 0; i < vertices.size(); i++){
        if (!vertices[i].isString()){
            qDebug() << "JSON - LOS VERTICES NO SIGUEN EL FORMATO INDICADO";
            return false;
        }
    }
    QJsonArray aristas = json["aristas"].toArray();
    if (aristas.isEmpty()){
        qDebug() << "JSON - NO HAY ARISTAS PARA CREAR EL GRAFO";
        return false;
    }
    for (int i = 0; i < aristas.size(); i++){
        QJsonValue obj = aristas[i];
        if (!obj["origen"].isString() || !vertices.contains(obj["origen"].toString()) || !obj["destino"].isString() || !vertices.contains(obj["destino"].toString()) || !obj["activo"].isBool() || !obj["costo"].isDouble() || !obj["km"].isDouble() || !obj["minutos"].isDouble()){
            qDebug() << "JSON - LAS ARISTAS NO SIGUEN EL FORMATO DE INDICADO O HAY ARISTAS QUE CONECTAN EN VERTICES INEXISTENTES";
            return false;
        }
    }
    qDebug() << "JSON - VALIDACION COMPLETADA : JSON EN PERFECTO ESTADO - CREANDO EL GRAFO";
    return true;
}














