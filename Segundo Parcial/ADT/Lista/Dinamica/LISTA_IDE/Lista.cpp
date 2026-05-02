#include <iostream>
#include "Lista.h"
#include <list>
using namespace std;

Lista::Lista(){
	
}
void Lista::insertar(int dato, int pos){
	if (pos < 0 || pos > listaDinamica.size()) {
        cout << "Posicion invalida\n";
        return;
    }

    auto it = listaDinamica.begin();
    advance(it, pos);
    listaDinamica.insert(it, dato);
}

void Lista::remover(int pos){
	if (listaDinamica.empty()) {
        cout << "La lista esta vacia\n";
        return;
    }

    if (pos < 0 || pos >= listaDinamica.size()) {
        cout << "Posicion invalida\n";
        return;
    }

    auto it = listaDinamica.begin();
    advance(it, pos);

    cout << "Se elimino el elemento: " << *it << endl;
    listaDinamica.erase(it);
    
}

void Lista::mostrar(){
	if (listaDinamica.empty()) {
        cout << "La lista no tiene elementos\n";
        return;
    }

    cout << "Elementos de la lista:\n";

    int i = 0;
    for (auto it = listaDinamica.begin(); it != listaDinamica.end(); ++it) {
        cout << "Elemento " << i << ": " << *it << endl;
        i++;
    }
}

void Lista::verifVacia() {
	if (listaDinamica.empty()) {
		cout<<"La lista esta vacia";
	}else{
		cout<<"La lista no esta vacia";
	}
}

void Lista::mostrarTamano() {
	cout<<"El tamano de la lista es : "<<listaDinamica.size();
}

Lista::~Lista(){
	
}
