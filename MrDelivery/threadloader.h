#ifndef THREADLOADER_H
#define THREADLOADER_H

#include <QThread>
#include "cola.h"
class ThreadLoader : public QThread {


public:
    Cola *cola;
    QString path;
    bool runner;
    bool pause;

    ThreadLoader();

    void __init__(Cola *cola, QString path);
    void run();
    void pauser();
    void unpause();

};
#endif // THREADLOADER_H
