#include <cstddef>
class Nodo{
    public:
        int dato;
        Nodo* next;
        Nodo(int d){
            dato = d;
            next = NULL;
        }
};
