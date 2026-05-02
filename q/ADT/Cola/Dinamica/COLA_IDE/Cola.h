#ifndef COLA_H
#define COLA_H
#include <iostream>
#include <queue>
class Cola {	
	private:
		std::queue<int> colaDinamica;
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
