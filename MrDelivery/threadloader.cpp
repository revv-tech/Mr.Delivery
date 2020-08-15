#include "threadloader.h"
#include "filemanager.h"
#include "grafo.h"
void ThreadLoader::__init__(Cola *cola, QString path){
    pause = true;
    runner = true;
    this->path = path;
    this->cola = cola;
}

void ThreadLoader::pauser(){
    pause = false;
}

void ThreadLoader::unpause(){
    pause = true;
}

ThreadLoader::ThreadLoader(){}

void ThreadLoader::run(){

    int i = 0;
    while(runner){
        while (pause) {

            QStringList files = FileManager::seeDirectory(path+"/DirectoryJson");
            qDebug() << files;
            if(files.length()>0){
                qDebug() << files;
                Grafo *nuevo = FileManager::readJson(path+"/DirectoryJson/"+files[i]);
                if (nuevo != nullptr){
                    cola->m->lock();
                    cola->encolar(nuevo);
                    cola->m->unlock();
                    FileManager::fileRelocater(path+"/DirectoryJson",path+"/Procesados/",files[i]);

                }
                else if (nuevo==nullptr) {
                    FileManager::fileRelocater(path+"/DirectoryJson",path+"/Invalidos/",files[i]);

                }


            }
            sleep(1);
        }
    }
}
