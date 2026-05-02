#ifndef ADT_H
#define ADT_H
#include <iostream>
using namespace std;

template<class T>
class ColaE {
    T* a; int m; int f; int fin;
public:
    ColaE(int tam) {
        m=tam;
        a=new T[m];
        f=0;
        fin=-1;
    }
    ~ColaE() { delete[] a; }
    
    void insertar(T v){
        if(fin<m-1){ 
            fin++; a[fin]=v; 
            cout<<"Elemento encolado correctamente\n"; 
        } else { 
            cout<<"La cola esta llena\n"; 
        }
    }
    
    void remover() {
        if(f<=fin){ 
            f++;
            cout<<"Elemento desencolado correctamente\n"; 
        } else { 
            cout<<"La cola esta vacia\n"; 
        } 
    }
    
    void vaciar() {
        f=0; fin=-1;
        cout<<"La cola ha sido vaciada\n";
    }
    
    void mostrar() {
        cout<<"Cola actual (Frente -> Final): " << endl;
        for(int i=f; i<=fin; i++){
            cout<<a[i]<<" ";
        }
    }
};
#endif