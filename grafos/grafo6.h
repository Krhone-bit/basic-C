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
        NodoG* f; int pf;
        NodoG* g; int pg;
        NodoG* h; int ph;
        NodoG* i; int pi;

        NodoG(int v){
            this->v = v;
            a=b=c=d=e=f=g=h=i=NULL;
            pa=pb=pc=pd=pe=pf=pg=ph=pi=0;
        }
};


class Grafo{
    private:
        NodoG*init;
    public:
        Grafo(){
            init=NULL;
        }
        void crearGrafo(){
            init = new NodoG(1);
            init->a = new NodoG(3);
            init->f = new NodoG(4);
            init->g = new NodoG(6);
            init->a->f = new NodoG(5);
            init->f->c = new NodoG(2);

            init->f->c->b = init; // : grafo1
            init->a->f->c = init; // : grafo1
            init->a->f->e = init->g; // : grafo6
            init->g->d = init->f; // : grafo4
            init->a->d = init->f->c; // : grafo2
            init->a->b = init->g; // : grafo6
            init->a->b->i = init; // : grafo1
            init->a->f->a = init->f->c; // : grafo2
            init->f->i = init->a; // : grafo3
            init->a->d->h = init->g; // : grafo6

            NodoG*tmp;

            // grafo1
            tmp=init;
            tmp->pa = 3;
            tmp->pf = 16;
            tmp->pg = 14;

            // grafo2
            tmp=init->f->c;
            tmp->pb = 4;
            tmp->ph = 24;

            // grafo3
            tmp=init->a;
            tmp->pd = 11;
            tmp->pf = 7;
            tmp->pb = 19;

            // grafo4
            tmp=init->f;
            tmp->pc = 6;
            tmp->pi = 90;

            // grafo5
            tmp=init->a->f;
            tmp->pc = 12;
            tmp->pa = 56;
            tmp->pe = 9;

            // grafo6
            tmp=init->g;
            tmp->pi = 10;
            tmp->pd = 8;
        }

        int getPeso(NodoG*n1,NodoG*n2){
            if(n1->a==n2) return n1->pa;
            if(n1->b==n2) return n1->pb;
            if(n1->c==n2) return n1->pc;
            if(n1->d==n2) return n1->pd;
            if(n1->e==n2) return n1->pe;
            if(n1->f==n2) return n1->pf;
            if(n1->g==n2) return n1->pg;
            if(n1->h==n2) return n1->ph;
            if(n1->i==n2) return n1->pi;
            return -1;
        }

        void mostrar(){
            vector<NodoG*> vertices={
                init,
                init->f->c,
                init->a,
                init->f,
                init->a->f,
                init->g,
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
