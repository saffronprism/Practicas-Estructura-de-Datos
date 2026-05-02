#include <iostream>
#include "Pila.h"
#include "NuevoDato.h"
using namespace std;

Pila::Pila(){
	tope = nullptr;
}
void Pila::push(int dato){
	NuevoDato* nuevo = new NuevoDato(dato);

    nuevo->siguienteDato = tope;  // apunta al anterior
    tope = nuevo;                 // ahora nuevo es el tope

    cout << "Elemento " << dato << " agregado a la pila\n";
}

void Pila::pop(){
	if (tope == nullptr) {
        cout << "Pila vacia\n";
    }

    NuevoDato* temp = tope;      // guardar nodo a eliminar
    int valor = temp->dato;      // guardar su dato

    tope = tope->siguienteDato;  // mover tope

    delete temp;                 // liberar memoria

    cout << "Elemento de valor " << valor << " eliminado\n";
    
}

void Pila::mostrar(){
	if (tope == nullptr) {
        cout << "La pila esta vacia\n";
        return;
    }

    cout << "Elementos de la pila : \n";

    NuevoDato* aux = tope;

    int i = 0;

    while (aux != nullptr) {
        cout << "Elemento " << i << " : " << aux->dato << endl;
        aux = aux->siguienteDato;
        i++;
    }
}

void Pila::verifVacia() {
	if (tope == nullptr){
		cout<<"La pila esta vacia";
	}else{
		cout<<"La pila no esta vacia";
	}
}

void Pila::mostrarTamano() {
	int contador = 0;

    NuevoDato* aux = tope;

    while (aux != nullptr) {
        contador++;
        aux = aux->siguienteDato;
    }

    cout<<"El tamaño de la pila es de "<<contador<<" elementos";
}

Pila::~Pila(){
	
}
