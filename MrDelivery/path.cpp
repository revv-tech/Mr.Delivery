#include "path.h"

Path::Path(){
    for (int i = 0; i < 100; i++)
        this->vertices[i] = 0;
    this->total = 0;
    this->idx = 0;
}
