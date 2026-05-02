#ifndef ADT_H
#define ADT_H
#include <iostream>
using namespace std;

template<class T>
struct NodoL{
    T d;
    NodoL<T>* s;
};

template<class T>
class ListaD {
    NodoL<T>* h;
public:
    ListaD() {
        h = NULL;
    }
    ~ListaD() { vaciar(); }
    void insertar(T v) {
        NodoL<T>* n = new NodoL<T>();
        n->d=v;
        n->s=NULL;
        if(!h){
            h=n;
        }
        else{
            NodoL<T>* a=h;
            while(a->s){
                a=a->s;
               
            }
            a->s=n;
        }
        cout<<"Elemento insertado correctamente"<<endl; 
    }
    void remover() { 
        if(!h){
            cout<<"La lista esta vacia, considea añadir algo para empezar" <<endl; 
            return;
        }
        if(!h->s){
            delete h;
            h=NULL;
        }
        else{
            NodoL<T>* a=h;
            while(a->s->s){
                a=a->s;
               
            }
            delete a->s;
            a->s=NULL;
        }
        cout<<"Elemento removido correctamente" << endl; 
    }
    void vaciar() { 
        while(h){
            NodoL<T>* x=h;
            h=h->s;
            delete x;
        }
        cout<<"la lista ha sido vaciada por completo" <<endl; 
    }
    void mostrar() { 
        cout<<"Lista actual" << endl; 
        NodoL<T>* a=h;
        while(a){
            cout<<a->d<<" ";
            a=a->s;
        }
    }
};
#endif