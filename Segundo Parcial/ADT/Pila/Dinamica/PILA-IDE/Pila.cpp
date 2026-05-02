#include <iostream>
#include "Pila.h"
#include <stack>
using namespace std;

Pila::Pila(){
	
}
void Pila::push(int dato){
	pilaDinamica.push(dato);
}

void Pila::pop(){
	if (!pilaDinamica.empty()) {
        pilaDinamica.pop();
        cout<<"Se elimino el elemento "<<pilaDinamica.size()<<" de la pila";
    }else{
    	cout<<"La pila esta vacia, no se pueden eliminar elementos";
	}
    
}

void Pila::mostrar(){
	cout<<"Elementos de la pila : ";
	
	stack<int> copia = pilaDinamica;
	if (pilaDinamica.empty() == false) {
		int n = copia.size();
		for (int i=0; i<n; i++) {
			cout<<"Elemento "<<copia.size()-1<<" : "<<copia.top()<<"\n";
			copia.pop();
			
		}
	}else{
		cout<<"La pila no tiene elementos";
	}
}

void Pila::verifVacia() {
	if (pilaDinamica.empty()) {
		cout<<"La pila esta vacia";
	}else{
		cout<<"La pila no esta vacia";
	}
}

void Pila::mostrarTamano() {
	cout<<"El tamano de la pila es : "<<pilaDinamica.size();
}

Pila::~Pila(){
	
}
