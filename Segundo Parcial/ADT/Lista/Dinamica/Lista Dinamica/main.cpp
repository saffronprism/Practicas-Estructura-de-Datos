#include <iostream>
#include "Lista.h"
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	
	int opcion = 0;
	Lista NuevaLista;
	int dato = 0;
	int pos = 0;
		//Proceso que controla la ejecución del programa 
	for (int repeticion = 0; repeticion == 0; ) {
		system ("cls");
		
		
		cout<<"\nMENU";
		cout<<"\n1 - Agregar elemento";
		cout<<"\n2 - Quitar elemento";
		cout<<"\n3 - Verificar si la Lista esta vacia";
		cout<<"\n4 - Mostrar Lista";
		cout<<"\n5 - Mostrar tamaño de la Lista";
		cout<<"\n6 - Salir";
		cout<<"\nTeclee la opcion deseada : ";
		cin>>opcion;
		
		switch (opcion){
			
			case (1):
				//push	
				cout<<"Ingresar Dato  ";
				cin>>dato;
				cout<<"Ingresar posicion para agregar el dato (debe estar entre 0 y el maximo de elementos) : ";
				cin>>pos;
				NuevaLista.insertar(dato, pos);
				cout<<"\n";
				system ("pause");
				break;
			case (2):
				//pop
				cout<<"Ingresar posicion del elemento a remover : ";
				cin>>pos;
				NuevaLista.remover(pos);
				cout<<"\n";
				system ("pause");
				break;

			case (3):
				//vacia?
				NuevaLista.verifVacia();
				cout<<"\n";
				system ("pause");
				break;
			case (4):
				//Mostrar
				NuevaLista.mostrar();
				cout<<"\n";
				system ("pause");
				break;
			case (5):
				//tamano
				NuevaLista.mostrarTamano();
				cout<<"\n";
				system ("pause");
				break;
			case(6):
				cout<<"\nGracias por trabajar con  el programa\n";
				repeticion++;
				system ("pause");
				break;
			default:
				cout<<"\nOpcion no valida ";
		}	
	}
    system ("pause");
	return 0;
}
