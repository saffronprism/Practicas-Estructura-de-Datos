#include <iostream>
#include "Cola.h"
#include <queue>
using namespace std;

Cola::Cola(){
	
}
void Cola::push(int dato){
	colaDinamica.push(dato);
}

void Cola::pop(){
	if (!colaDinamica.empty()) {
        colaDinamica.pop();
        cout<<"Se elimino el elemento "<<0<<" de la cola\nsiguente elemento : "<<colaDinamica.front();
    }else{
    	cout<<"La cola esta vacia, no se pueden eliminar elementos";
	}
    
}

void Cola::mostrar(){
	cout<<"Elementos de la cola : ";
	
	queue<int> copia = colaDinamica;
	if (colaDinamica.empty() == false) {
		int n = copia.size();
		for (int i=0; i<n; i++) {
			cout<<"elemento "<<i<<" : "<<copia.front()<<"\n";
			copia.pop();
			
		}
	}else{
		cout<<"La cola no tiene elementos";
	}
}

void Cola::verifVacia() {
	if (colaDinamica.empty()) {
		cout<<"La cola esta vacia";
	}else{
		cout<<"La cola no esta vacia";
	}
}

void Cola::mostrarTamano() {
	cout<<"El tamano de la cola es : "<<colaDinamica.size();
}

Cola::~Cola(){
	
}
