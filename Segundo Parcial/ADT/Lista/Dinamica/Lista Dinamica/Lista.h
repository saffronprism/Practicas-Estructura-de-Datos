#ifndef LISTA_H
#define LISTA_H
#include <iostream>
#include <list>
class Lista {	
	private:
		int lista [50];
		const int MAX = 50;
		int tope;
	public:
		Lista();
		void remover(int pos);
		void insertar(int dato, int pos);
		void mostrar();
		void verifVacia();
		void mostrarTamano();
		~Lista();
};

#endif
