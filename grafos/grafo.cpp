#include "grafo.h"

int main(){
    NodoG *ini;
    ini =new NodoG(1);
    ini->b = new NodoG(2);
    ini->pb=12;
    ini->a = new NodoG(3);
    ini->pa=16;
    ini->b -> b = new NodoG(4);
    ini->b->pb=8;
    return 0;
}
