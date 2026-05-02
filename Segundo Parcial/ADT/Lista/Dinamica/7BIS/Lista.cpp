#include <iostream>
#include "Lista.h"
#include "NuevoDato.h"
using namespace std;

Lista::Lista(){
	inicio = nullptr;
}


void Lista::insertar(int dato, int pos){

    // calcular tamaño
    int tam = 0;
    NuevoDato* aux = inicio;

    while (aux != nullptr) {
        tam++;
        aux = aux->siguiente;
    }

    //validar posición (NO puede ser mayor al tamaño)
    if (pos < 0 || pos > tam) {
        cout << "Posicion invalida\n";
        return;
    }

    // crear NuevoDato
    NuevoDato* nuevo = new NuevoDato(dato);
    nuevo->dato = dato;

    // insertar al inicio
    if (pos == 0) {
        nuevo->siguiente = inicio;
        inicio = nuevo;
        return;
    }

    //recorrer hasta pos - 1
    aux = inicio;
    for (int i = 0; i < pos - 1; i++) {
        aux = aux->siguiente;
    }

    nuevo->siguiente = aux->siguiente;
    aux->siguiente = nuevo;
}



void Lista::remover(int pos){
	if (inicio == nullptr) {
        cout << "Lista vacia\n";
        return;
    }

    NuevoDato* actual = inicio;
    NuevoDato* anterior = nullptr;

    if (pos == 0) {
        inicio = actual->siguiente;
        delete actual;
        cout << "Elemento eliminado en posicion 0\n";
        return;
    }

    // recorrer hasta la posición
    for (int i = 0; actual != nullptr && i < pos; i++) {
        anterior = actual;
        actual = actual->siguiente;
    }

    if (actual == nullptr) {
        cout << "Posicion invalida\n";
        return;
    }

    // desconectar del ultimo
    anterior->siguiente = actual->siguiente;

    delete actual;

    cout << "Elemento eliminado en posicion " << pos << endl;
    
}

void Lista::mostrar(){
	NuevoDato* aux = inicio;
	int contador = 0;
    while (aux != nullptr) {
        cout<<"El elemento "<<contador<<" : " << aux->dato << endl;
        aux = aux->siguiente;
        contador++;
    }
}

void Lista::verifVacia() {
	if (inicio == nullptr){
		cout<<"La lista esta vacia";
	}else{
		cout<<"La lista no esta vacia";
	}
}

void Lista::mostrarTamano() {
	int contador = 0;

    NuevoDato* aux = inicio;

    while (aux != nullptr) {
        contador++;
        aux = aux->siguiente;
    }

    cout<<"El tamaño de la lista es de "<<contador<<" elementos";
}

Lista::~Lista(){
	
}
