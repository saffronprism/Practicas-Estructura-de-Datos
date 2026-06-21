#ifndef PILA_H
#define PILA_H
#include <iostream>
#include <fstream>
#include <direct.h>
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
		void guardar();
		void leer();
		~Pila();
};

#endif
