#ifndef ADT_H
#define ADT_H
#include <iostream>
using namespace std;

template<class T>
struct NodoP{
    T d;
    NodoP<T>* s;
};
template<class T>
class PilaD {
    NodoP<T>* t;
public:
    PilaD(){t = NULL;}
    ~PilaD(){vaciar();}

    void insertar(T v) { 
        NodoP<T>* n = new NodoP<T>();
        n->d=v;
        n->s=t;
        t=n; 
        cout<<"Elemento insertado correctamente"<<endl; 
    }
    void remover() { 
        if(t){
            NodoP<T>* x=t;
            t=t->s;
            delete x;
            cout<<"Elemento removido correctamente" <<endl;
        } 
        else{
            cout<<"La pila esta vacia, considea añadir algo para empezar"<<endl; 
        }
    }
    void vaciar() { 
        while(t){
            NodoP<T>* x=t;
            t=t->s;
            delete x;
        } 
        cout<<"la pila ha sido vaciada por completo" <<endl; 
    }
    void mostrar(){ 
        cout<<"Pila actual (de tope a base)"<<endl; 
        NodoP<T>* a=t;
        while(a){
            cout<<a->d<<" ";
            a=a->s;
            cout << " ";
        }
    }
};
#endif