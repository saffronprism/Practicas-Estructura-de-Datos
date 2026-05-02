#ifndef PILA_H
#define PILA_H
#include <iostream>
#include "NuevoDato.h"
class Pila {
	private:
		NuevoDato* tope;
	public:
		Pila();
		void pop();
		void push(int dato);
		void mostrar();
		void verifVacia();
		void mostrarTamano();
		~Pila();
};

#endif
