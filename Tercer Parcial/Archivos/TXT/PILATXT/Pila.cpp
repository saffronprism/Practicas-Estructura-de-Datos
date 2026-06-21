#include <iostream>
#include <fstream>
#include <direct.h>
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
        return;
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

void Pila::guardar() {
	
	std::ofstream archivo("pila.txt");
	
	if (tope == nullptr) {
        cout << "La pila esta vacia\n";
        return;
    }

    cout << "Elementos de la pila : \n";

    NuevoDato* aux = tope;

    int i = 0;

    while (aux != nullptr) {
        cout << "Elemento " << i << " : " << aux->dato << endl;
        
        archivo <<i<<" "<< aux->dato << "\n";
        aux = aux->siguienteDato;
        i++;
    }
    
    archivo.close();
    
}


void Pila::leer() {
	cout<<"Quieres vaciar la pila y cargar una nueva (0 para no, 1 para sí)";
	int respuesta = 0;
	cin>>respuesta;
	if (respuesta == 1) {
		cout<<"El archivo debe tener el nombre 'pila.txt'";
		
		while (tope != nullptr) {
    		pop();
		}
		
		std::ifstream archivo("pila.txt");

		
   		if (!archivo) {
        std::cout << "No se pudo abrir el archivo\n";
        return;
    	}
    	
    	int posicion;
    	int dato;

	    while (archivo >> posicion >> dato) {
	        NuevoDato* nuevo = new NuevoDato(dato);
    		nuevo->siguienteDato = nullptr;

		    if (tope == nullptr) {
		        tope = nuevo;
		        continue;
		    }
		
		    NuevoDato* aux = tope;
		
		    while (aux->siguienteDato != nullptr) {
		        aux = aux->siguienteDato;
		    }
		
		    aux->siguienteDato = nuevo;
	    }
    	
    	
    	
	}
 
}

Pila::~Pila(){
	
}
