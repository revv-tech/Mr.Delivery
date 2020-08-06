#include "threadloader.h"
#include "filemanager.h"
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
            QStringList files = FileManager::seeDirectory(path);
            if(files.length()>0){
                qDebug() << files;
                FileManager::fileRelocater(path+"/DirectoryJson",path+"/Procesados",files[i]);
            }
            sleep(1);
        }
    }
}
