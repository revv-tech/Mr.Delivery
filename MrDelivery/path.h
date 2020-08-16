#ifndef PATH_H
#define PATH_H


struct Path{
    int vertices[100]; //Camino : ejm -> {0, 3, 2, 1} = A -> D -> C -> B
    int idx; //size() del array
    int total; //cantidad de {minutos | km | costo} del camino

    Path();
};

#endif // PATH_H
