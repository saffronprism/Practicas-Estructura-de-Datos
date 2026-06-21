#include <iostream>
#include "Txt.h"
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	int respuesta=0;
	for (int repeticion = 0; repeticion == 0; ) {
		system ("cls");
		int opcion =0;
		
		cout<<"\nMENU";
		cout<<"\n1 - Generar persona";
		cout<<"\n2 - Guardar Persona";
		cout<<"\n3 - Abrir archivo de Persona";
		cout<<"\n4 - Generar auto";
		cout<<"\n5 - Guardar auto";
		cout<<"\n6 - Abrir archivo de auto";
		cout<<"\n7 - Salir";
		cout<<"\nTeclee la opcion deseada : ";
		cin>>opcion;
		
		AutoO coche;
		PersonaO persona;
		
		switch (opcion){
			
			case (1):
				persona.pedirDatos();
				persona.presentarse();
				cout<<"\n";
				
				system ("pause");
				break;

			case (2):
				persona.guardarPersona(persona);
				cout<<"\n";
				cout<<"Se guardo exitosamente a la persona:";
				persona.presentarse();
				system ("pause");
				break;
			case (3):
				persona.leerPersona(persona);
				cout<<"\n";
				persona.presentarse();
				system ("pause");
				
				break;
			case (4):
				coche.pedirDatos();
				coche.mostrarDetalles();
				cout<<"\n";
				system ("pause");
				break;
			case (5):
				coche.guardarAuto(coche);
				cout<<"\nSe guardo exitosamente el coche";
				coche.mostrarDetalles();
				system ("pause");
				break;
			case (6):
				coche.leerAuto(coche);
				coche.mostrarDetalles();
				cout<<"\n";
				system ("pause");
				break;
			case (7):
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
