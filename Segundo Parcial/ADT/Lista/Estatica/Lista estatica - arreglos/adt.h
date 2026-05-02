#ifndef ADT_H
#define ADT_H
#include <iostream>
using namespace std;

template<class T>
class ListaE {
    T* a; int m; int n;
public:
    ListaE(int tam) {
        m=tam;
        a=new T[m]; 
        =0;
    }
    ~ListaE() { delete[] a; }
    
    void insertar(T v){
        if(n<m){ 
            a[n]=v;
            n++; 
            cout<<"Elemento agregado a la lista"<<endl; 
        } else { 
            cout<<"La lista esta llena"<<endl; 
        }
    }
    
    void remover() {
        if(n>0){ 
            n--;
            cout<<"Ultimo elemento removido de la lista" << endl; 
        } else { 
            cout<<"La lista esta vacia" <<endl; 
        } 
    }
    
    void vaciar() {
        n=0;
        cout<<"La lista ha sido limpiada"<<endl;
    }
    
    void mostrar() {
        cout<<"Lista actual: " << endl;
        for(int i=0; i<n; i++){
            cout<<a[i]<<" ";}
    }
};
#endif