#ifndef ADT_H
#define ADT_H
#include <iostream>
using namespace std;

template<class T> struct NodoC { T d; NodoC<T>* s; };

template<class T>
class ColaD {
    NodoC<T>* f; NodoC<T>* fin;
public:
    ColaD() {
        f = NULL; 
        fin = NULL;
    }
    ~ColaD() {vaciar();}

    void insertar(T v) {
    NodoC<T>* n = new NodoC<T>();
    n->d=v;
    n->s=NULL;
    if(!f){
        f=n;  
        fin=n;
    }else{
        fin->s=n;
        fin=n;
    }
    cout<<"Elemento insertado correctamente" <<endl; 
    }
    void remover() {
        if(f){ 
            NodoC<T>* x=f;
            f=f->s;
            if(!f){
                fin=NULL; delete x; 
                cout<<"Elemento removido correctamente\n"; 
            }
        } 
        else cout<<"La cola esta vacia, considea añadir algo para empezar\n"; 
    }
    void vaciar() { 
        while(f){
            NodoC<T>* x=f;
            f=f->s;
            delete x;
        }
        fin = NULL;
        cout<<"la cola ha sido vaciada por completo\n"; 
    }
    void mostrar() {

        cout<<"Cola actual (de frente a final):" << endl; 
        NodoC<T>* a=f;
        while(a){
            cout<<a->d<<" ";
            a=a->s;
        } 
    }
};
#endif