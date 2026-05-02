#ifndef COLA_H
#define COLA_H
#include <iostream>
#include "NuevoDato.h"
class Cola {
	private:
		NuevoDato* tope;
	public:
		Cola();
		void pop();
		void push(int dato);
		void mostrar();
		void verifVacia();
		void mostrarTamano();
		~Cola();
};

#endif
