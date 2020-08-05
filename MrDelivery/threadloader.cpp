#include "threadloader.h"

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

void ThreadLoader::run(){}
