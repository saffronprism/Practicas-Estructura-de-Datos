#ifndef ADT_H
#define ADT_H
#include <iostream>
#include <queue>
using namespace std;

template<class T>
class ColaL {
    queue<T> c;
public:
    void insertar(T v){ 
        c.push(v); 
        cout<<"Elemento insertado correctamente"<<endl; 
    }
    void remover() { 
        if(!c.empty()){
            c.pop();
            cout<<"Elemento removido correctamente"<<endl;
        } 
        else cout<<"La cola esta vacia, considea añadir algo para empezar"<<endl; 
    }
    void vaciar() { 
        while(!c.empty()){
            c.pop(); 
        }
        cout<<"la cola ha sido vaciada por completo"<<endl; 
    }
    void mostrar() {
        cout<<"Cola actual (de frente a final)"<<endl;
        queue<T> temp = c; 
        while(!temp.empty()){
            cout<<temp.front()<<" ";
            temp.pop();
        }
    }
};
#endif