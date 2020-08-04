#ifndef GRAPHTEMPLATE_H
#define GRAPHTEMPLATE_H

template<class T>
struct Vertice{
    T *data;
    bool visitado;

    Vertice(T *data){
        this->data = data;
        this->visitado = false;
    }
};

template<class T>
struct GraphTemplate
{

    GraphTemplate();
};

#endif // GRAPHTEMPLATE_H
