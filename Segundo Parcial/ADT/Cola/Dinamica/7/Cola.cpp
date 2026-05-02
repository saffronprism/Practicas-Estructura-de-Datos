#include <iostream>
#include "Cola.h"
#include "NuevoDato.h"
using namespace std;

Cola::Cola(){
	tope = nullptr;
}
void Cola::push(int dato){
	NuevoDato* nuevo = new NuevoDato(dato);
    nuevo->siguienteDato = nullptr;

    if (tope == nullptr) {
        tope = nuevo;
    } else {
        NuevoDato* aux = tope;

        while (aux->siguienteDato != nullptr) {
            aux = aux->siguienteDato;
        }

        aux->siguienteDato = nuevo;
    }

    cout << "Elemento " << dato << " agregado a la cola\n";
}

void Cola::pop(){
	if (tope == nullptr) {
        cout << "Cola vacia\n";
        return;
    }

    NuevoDato* temp = tope;
    int valor = temp->dato;

    tope = tope->siguienteDato;

    delete temp;

    cout << "Elemento de valor " << valor << " eliminado\n";
    
}

void Cola::mostrar(){
	if (tope == nullptr) {
        cout << "La cola esta vacia\n";
        return;
    }

    cout << "Elementos de la cola : \n";

    NuevoDato* aux = tope;

    int i = 0;

    while (aux != nullptr) {
        cout << "Elemento " << i << " : " << aux->dato << endl;
        aux = aux->siguienteDato;
        i++;
    }
}

void Cola::verifVacia() {
	if (tope == nullptr){
		cout<<"La cola esta vacia";
	}else{
		cout<<"La cola no esta vacia";
	}
}

void Cola::mostrarTamano() {
	int contador = 0;

    NuevoDato* aux = tope;

    while (aux != nullptr) {
        contador++;
        aux = aux->siguienteDato;
    }

    cout<<"El tamaño de la cola es de "<<contador<<" elementos";
}

Cola::~Cola(){
	
}
