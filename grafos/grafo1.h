#include <iostream>
#include <vector>

using namespace std;

class NodoG{
    public:
        int v;
        NodoG* a; int pa;
        NodoG* b; int pb;
        NodoG* c; int pc;
        NodoG* d; int pd;
        NodoG* e; int pe;

        NodoG(int v){
            this->v = v;
            a=b=c=d=e=NULL;
            pa=pb=pc=pd=pe=0;
        }
};


class Grafo{
    private:
        NodoG*ini;
    public:
        Grafo(){
            ini=NULL;
        }
        void crearGrafo(){
            ini = new NodoG(1);
            ini->a = new NodoG(2);
            ini->b = new NodoG(3);
            ini->b->e = new NodoG(4);

            ini->b->d = ini; // : grafo1
            ini->a->c = ini->b; // : grafo3
            ini->a->d = ini->b->e; // : grafo4

            NodoG*tmp;

            // grafo1
            tmp=ini;
            tmp->pa = 26;
            tmp->pb = 2;

            // grafo2
            tmp=ini->a;
            tmp->pc = 8;
            tmp->pd = 3;

            // grafo3
            tmp=ini->b;
            tmp->pd = 5;
            tmp->pe = 9;
        }

        int getPeso(NodoG*n1,NodoG*n2){
            if(n1->a==n2) return n1->pa;
            if(n1->b==n2) return n1->pb;
            if(n1->c==n2) return n1->pc;
            if(n1->d==n2) return n1->pd;
            if(n1->e==n2) return n1->pe;
            return -1;
        }

        void mostrar(){
            vector<NodoG*> vertices={
                ini,
                ini->a,
                ini->b,
                ini->b->e,
            };

            for (int i = 0; i < vertices.size(); i++) {
                cout << "\t" << vertices[i]->v;
            }
            cout << endl;

            for (int i = 0; i < vertices.size(); i++) {
                cout << vertices[i]->v << "\t";
                for (int j = 0; j < vertices.size(); j++) {
                    int peso = getPeso(vertices[i], vertices[j]);
                    if(peso == -1) cout<< "-" << "\t";
                    else cout << peso << "\t";
                }
                cout << endl;
            }
        };
};
