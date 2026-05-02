#ifndef PILA_H
#define PILA_H
#include <iostream>
#include <stack>
class Pila {
	private:
		std::stack<int> pilaDinamica;
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
