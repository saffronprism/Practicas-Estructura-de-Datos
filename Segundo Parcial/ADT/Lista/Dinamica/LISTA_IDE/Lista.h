#ifndef LISTA_H
#define LISTA_H
#include <iostream>
#include <list>
class Lista {	
	private:
		std::list<int> listaDinamica;
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
