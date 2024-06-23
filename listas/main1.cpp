#include "main1.h"
#include <iostream>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <cstddef>


int main(){
    Lista* l;
    l = new Lista();
    l->insertar(9);
    l->insertar(8);
    l->insertar(7);
    l->Mostrar();
    return 0;
}


