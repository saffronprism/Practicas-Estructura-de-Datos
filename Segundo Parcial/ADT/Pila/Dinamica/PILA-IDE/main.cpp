#include <iostream>
#include "Pila.h"
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	
	int opcion = 0;
	Pila NuevaPila;
	int dato = 0;
		//Proceso que controla la ejecución del programa 
	for (int repeticion = 0; repeticion == 0; ) {
		system ("cls");
		
		
		cout<<"\nMENU";
		cout<<"\n1 - Agregar elemento";
		cout<<"\n2 - Quitar elemento";
		cout<<"\n3 - Verificar si la pila esta vacia";
		cout<<"\n4 - Mostrar pila";
		cout<<"\n5 - Mostrar tamaño de la pila";
		cout<<"\n6 - Salir";
		cout<<"\nTeclee la opcion deseada : ";
		cin>>opcion;
		
		switch (opcion){
			
			case (1):
				//push	
				cout<<"Ingresar Dato: ";
				cin>>dato;
				NuevaPila.push(dato);
				cout<<"\n";
				system ("pause");
				break;
			case (2):
				//pop
				NuevaPila.pop();
				cout<<"\n";
				system ("pause");
				break;

			case (3):
				//vacia?
				NuevaPila.verifVacia();
				cout<<"\n";
				system ("pause");
				break;
			case (4):
				//Mostrar
				NuevaPila.mostrar();
				cout<<"\n";
				system ("pause");
				break;
			case (5):
				//tamano
				NuevaPila.mostrarTamano();
				cout<<"\n";
				system ("pause");
				break;
			case(6):
				cout<<"\nGracias por trabajar con  el programa\n";
				repeticion++;
				break;
			default:
				cout<<"\nOpcion no valida ";
		}	
	}
    system ("pause");
	return 0;
}
