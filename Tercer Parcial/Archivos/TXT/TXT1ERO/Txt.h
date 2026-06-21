#ifndef TXT_H
#define TXT_H
#include <fstream>
#include <iostream>
using namespace std;

class AutoO{
    public:
    float precio;
    short anio;

    void mostrarDetalles()
    {
        cout<< "Precio: $" << precio << ". Año: "<< anio<< endl;
    }

    void pedirDatos() {
        cout << "Datos del Auto" << endl;
        cout << "Ingrese el precio: ";
        cin >> precio;
        cout << "Ingrese el año: ";
        cin >> anio;
    }
    
    void guardarAuto(AutoO &coche) {
	    ofstream archivo("auto.txt");
	
	    archivo << coche.precio << endl;
	    archivo << coche.anio << endl;
	
	    archivo.close();
	}
	
	void leerAuto(AutoO &coche) {
	    ifstream archivo("auto.txt");
	
	    archivo >> coche.precio;
	    archivo >> coche.anio;
	
	    archivo.close();
	}
};

class PersonaO{
    public:
    char nombre[30], am[30], ap[30], genero;
    int edad;

    void presentarse()
    {
        cout << "Mi nombre es:" << nombre << " " << am << " " << ap << " " << endl;
        cout << "Soy " << genero << " " << edad << endl; 
    }
    void pedirDatos ()
    {
        cout << "Datos de la persona" << endl;
        cout << "Ingrese el nombre completo (primero nombre, despues apellido por apellido): ";
        cin >> nombre;
        cin >> am;
        cin >> ap;
        cout << "Ingrese su genero (M/F): ";
        cin >> genero;
        cout << "Ingrese su Edad: ";
        cin >> edad;
    }
    
    void guardarPersona(PersonaO &p) {
    ofstream archivo("persona.txt");

	    archivo << p.nombre << endl;
	    archivo << p.am << endl;
	    archivo << p.ap << endl;
	    archivo << p.genero << endl;
	    archivo << p.edad << endl;
	
	    archivo.close();
	}	
	
	void leerPersona(PersonaO &p) {
	    ifstream archivo("persona.txt");
	
	    archivo >> p.nombre;
	    archivo >> p.am;
	    archivo >> p.ap;
	    archivo >> p.genero;
	    archivo >> p.edad;
	
	    archivo.close();
	}
    //constructor por default
    
    

};

#endif
