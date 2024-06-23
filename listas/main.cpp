#include "main.h"
#include <iostream>
#include <stdlib.h>
#include <conio.h>
#include <string.h>


void Mostrar(Nodo* ini){
    Nodo* tmp;
    for(tmp = ini; tmp != NULL; tmp = tmp->next){
        std::cout << tmp << std::endl;
        std::cout << tmp->dato << std::endl;
        std::cout << tmp->next << std::endl;
    }
}

int main(){
    Nodo* a = new Nodo(9);
    Nodo* b = new Nodo(8);
    Nodo* c = new Nodo(7);
    Nodo* d = new Nodo(6); // segmento 0==null
    a->next = b;
    b->next = c;
    c->next = d;
    // d->next = a; // ciclo interminable
    Mostrar(b);
    return 0;
}


