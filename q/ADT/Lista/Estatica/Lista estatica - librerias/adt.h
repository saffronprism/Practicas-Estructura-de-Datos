#ifndef ADT_H
#define ADT_H
#include <iostream>
#include <list>
using namespace std;

template<class T>
class ListaL {
    list<T> l;
public:
    void insertar(T v){ 
        l.push_back(v); 
        cout<<"Elemento insertado correctamente"<<endl; 
    }
    void remover(){ 
        if(!l.empty()){
            l.pop_back();
            cout<<"Elemento removido correctamente"<<endl; } 
        else {
            cout<<"La lista esta vacia, considea añadir algo para empezar"<<endl; 
        }
    }
    void vaciar() { 
        l.clear(); 
        cout<<"la lista ha sido vaciada por completo"<<endl; 
    }
    void mostrar() {
        cout<<"Lista actual"<<endl;
        for(auto const& val : l){
            cout<<val<<" ";
        }
    }
};
#endif