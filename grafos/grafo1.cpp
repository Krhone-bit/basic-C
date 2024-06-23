#include "grafo1.h"

int main(){
    // NodoG *ini;
    // ini =new NodoG(1);
    // ini->a = new NodoG(2);
    // ini->pa=26;
    // ini->b = new NodoG(3);
    // ini->pb=2;
    // ini->b -> e = new NodoG(4);
    // ini->b->pe=9;

    // // ini-> a->d= new NodoG(4); // incorrecto
    // ini->a->d = ini->b->e; //correcta
    // // ini-> a->pd=3;

    Grafo* g = new Grafo();
    g->crearGrafo();
    g->mostrar();
    return 0;
}
