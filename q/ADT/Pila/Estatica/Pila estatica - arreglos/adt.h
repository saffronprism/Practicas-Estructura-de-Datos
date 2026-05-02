#ifndef adt_H
#define adt_H
#include <iostream>
using namespace std;

template<class T>
class PilaE {
    T* a; int m; int t;
public:
    PilaE(int tam) {
        m=tam;
        a=new T[m];
        t=-1;
    }

    ~PilaE() { delete[] a; }
    void insertar(T v){
        if(t<m-1){
            t++;
            a[t]=v;
            cout<<"Elemento insertado correctamente";
        }
        else{
            cout<<"La pila esta llena, considera remover algun elemento";
        }
    }
    void remover() {
        if(t>=0){
            t--;
            cout<<"Elemento removido correctamente";
        }else{
            cout<<"La pila esta vacia, considea añadir algo para empezar";
        }
    }
    void vaciar() {
        t=-1;
        cout<<"la pila ha sido vaciada por completo";
    }
    void mostrar() {
        cout<<"Pila actual (de tope a base)";
        for(int i=t; i>=0; i--){
            cout<<a[i]<<" ";
            cout<<" "; }
        }
};
#endif