
#include "main.h"
#include <iostream>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <cstddef>

class Lista{
    private:
        Nodo* ini;
    public:
        Lista(){
            ini = NULL;
        }
        void insertar(int dato){
            if(ini == NULL){
                ini = new Nodo(dato);
            }
            else{
                Nodo* tmp = new Nodo(dato);
                tmp->next = ini;
                ini = tmp;
            }
        }
        void Mostrar(){
            Nodo* tmp;
            for(tmp = ini; tmp != NULL; tmp = tmp->next){
                std::cout << tmp << std::endl;
                std::cout << tmp->dato << std::endl;
                std::cout << tmp->next << std::endl;
            }
        }
        int eliminar(){
            if(ini!=NULL){
                Nodo* tmp = ini;
                ini = ini->next;
                int d = tmp->dato;
                delete tmp;
                return d;
            }
        }
};
