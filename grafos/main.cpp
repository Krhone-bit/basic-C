#include <iostream>
#include <vector>

using namespace std;

class NodoG{
    public:
        int v;
        NodoG*a; int pa;
        NodoG*b; int pb;
        NodoG*c; int pc;
        NodoG*d; int pd;
        NodoG*e; int pe;
        NodoG*f; int pf;
        NodoG(int V){
            v=V;
            a=b=c=d=NULL;
            pa=pb=pc=pd=0;
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
            ini->a = new NodoG(5);
            ini->b = new NodoG(2);
            ini->a->a = new NodoG(3);
            ini->a->b = new NodoG(6);
            ini->a->a->e = new NodoG(4);

            ini->b->d = ini->b;
            ini->a->b->f = ini->a->a;

            NodoG*tmp;

            tmp=ini;
            tmp->pa = 17;
            tmp->pb = 15;

            tmp=ini->b;
            tmp->pd = 22;

            tmp=ini->a->a;
            tmp->pe = 11;

            tmp=ini->a;
            tmp->pa = 11;
            tmp->pb = 17;

            tmp=ini->a->b;
            tmp->pf = 19;

        }
        int getPeso(NodoG*n1,NodoG*n2){
            if(n1->a==n2) return n1->pa;
            if(n1->b==n2) return n1->pb;
            if(n1->c==n2) return n1->pc;
            if(n1->d==n2) return n1->pd;
            if(n1->e==n2) return n1->pe;
            if(n1->f==n2) return n1->pf;
            return -1;
        }
        void mostrarTabla(){
            //Configurar aqui su lista de vertices, segun sus uniones
            vector<NodoG*> vertices = {
                ini,
                ini->b,
                ini->a->a,
                ini->a->a->e,
                ini->a,
                ini->a->b
            };
            for (size_t i = 0; i < vertices.size(); i++){
                cout<<"\t"<<vertices[i]->v;
            }
            cout<<endl;
            for (size_t i = 0; i < vertices.size(); i++){
                cout<<vertices[i]->v<<"\t";
                for (size_t j = 0; j < vertices.size(); j++) {
                    int peso = getPeso(vertices[i],vertices[j]);
                    if(peso == -1)
                        cout<<"-"<<"\t";
                    else
                        cout<<peso<<"\t";
                }
                cout<<endl;
            }
        }
};

int main()
{
    Grafo*g=new Grafo();
    g->crearGrafo();
    g->mostrarTabla();
    return 0;
}
