#ifndef PILA_H
#define PILA_H
#include <iostream>
#include "NuevoDato.h"
class Lista {
	private:
		NuevoDato* inicio;
	public:
		Lista();
		void insertar(int dato, int pos);
		void remover(int dato);
		void mostrar();
		void verifVacia();
		void mostrarTamano();
		~Lista();
};

#endif
