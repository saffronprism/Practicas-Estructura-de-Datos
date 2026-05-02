#include <iostream>
#include "Lista.h"
#include <list>
using namespace std;

Lista::Lista(){
	tope=-1; //indica que esta vacia
}
void Lista::insertar(int dato, int pos){
	if (tope > 98) {
        cout << "La lista ya esta llena\n";
        return;
    }

    if (pos < 0 || pos > tope+1) {
        cout << "Posicion invalida\n";
        return;
    }

    for (int i = tope; i > pos; i--) {
        lista[i] = lista[i - 1];  
    }

    lista[pos] = dato;
    tope++;
}

void Lista::remover(int pos){
	if (tope<0) {
        cout << "La lista esta vacia\n";
        return;
    }

    if (pos < 0 || pos > tope) {
        cout << "Posicion invalida\n";
        return;
    }
	
	int basura = lista [pos];
	
    for (int i=tope; i>pos; i--) {
    	lista[i] = lista[i+1];
	}

    cout << "Se elimino el elemento: " << basura << endl;
    tope--;
    
}

void Lista::mostrar(){
	if (tope < 0) {
        cout << "La lista no tiene elementos\n";
        return;
    }

    cout << "Elementos de la lista : \n";

    for (int i=0; i<=tope; i++) {
    	cout<<"Elemento "<<i<<" : "<<lista[i]<<"\n";
	}
	
}

void Lista::verifVacia() {
	if (tope<0) {
		cout<<"La lista esta vacia";
	}else{
		cout<<"La lista no esta vacia";
	}
}

void Lista::mostrarTamano() {
	cout<<"El tamano de la lista es : "<<tope+1;
}

Lista::~Lista(){
	
}
