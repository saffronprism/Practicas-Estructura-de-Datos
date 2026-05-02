#include <iostream>
#include "Cola.h"
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	
	int opcion = 0;
	Cola NuevaCola;
	int dato = 0;
		//Proceso que controla la ejecución del programa 
	for (int repeticion = 0; repeticion == 0; ) {
		system ("cls");
		
		
		cout<<"\nMENU";
		cout<<"\n1 - Agregar elemento";
		cout<<"\n2 - Quitar elemento";
		cout<<"\n3 - Verificar si la cola esta vacia";
		cout<<"\n4 - Mostrar cola";
		cout<<"\n5 - Mostrar tamaño de la cola";
		cout<<"\n6 - Salir";
		cout<<"\nTeclee la opcion deseada : ";
		cin>>opcion;
		
		switch (opcion){
			
			case (1):
				//push	
				cout<<"Ingresar Dato: ";
				cin>>dato;
				NuevaCola.push(dato);
				cout<<"\n";
				system ("pause");
				break;
			case (2):
				//pop
				NuevaCola.pop();
				cout<<"\n";
				system ("pause");
				break;

			case (3):
				//vacia?
				NuevaCola.verifVacia();
				cout<<"\n";
				system ("pause");
				break;
			case (4):
				//Mostrar
				NuevaCola.mostrar();
				cout<<"\n";
				system ("pause");
				break;
			case (5):
				//tamano
				NuevaCola.mostrarTamano();
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
