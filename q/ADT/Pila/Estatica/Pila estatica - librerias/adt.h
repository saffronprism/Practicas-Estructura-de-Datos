#ifndef ADT_H
#define ADT_H
#include <iostream>
#include <stack>
using namespace std;

template<class T>
class PilaL {
    stack<T> p;
public:
    void insertar(T v){ 
        p.push(v); 
        cout<<"Elemento insertado correctamente\n"; 
    }
    void remover() { 
        if(!p.empty()){
            p.pop();
            cout<<"Elemento removido correctamente"<<endl;
        } 
        else{
            cout<<"La pila esta vacia, considea añadir algo para empezar" << endl;
        }
    }
    void vaciar() { 
        while(!p.empty()){
            p.pop(); 
        }
        cout<<"la pila ha sido vaciada por completo" <<endl ; 
    }
    void mostrar() {
        cout<<"Pila actual (de tope a base)"<<endl;
        stack<T> temp = p; 
        while(!temp.empty()){
            cout<<temp.top()<<" ";
            temp.pop();
        }
    }
};
#endif