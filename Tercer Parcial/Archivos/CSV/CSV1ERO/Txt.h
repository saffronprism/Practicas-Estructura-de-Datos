#ifndef TXT_H
#define TXT_H
#include <fstream>
#include <string>
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
    
    void guardarAuto(AutoO &a) {
	    ofstream archivo("auto.csv");
	
	    if (!archivo) {
	        cout << "No se pudo crear el archivo\n";
	        return;
	    }
	
	    archivo << a.precio << "," << a.anio << endl;
	
	    archivo.close();
	}
	
	void leerAuto(AutoO &coche) {
	    ifstream archivo("auto.csv");
	
	    if (!archivo) {
	        cout << "No se pudo abrir el archivo\n";
	        return;
	    }
	
	    string linea;
	    getline(archivo, linea);
	
	    stringstream ss(linea);
	
	    string precioStr;
	    string anioStr;
	
	    getline(ss, precioStr, ',');
	    getline(ss, anioStr, ',');
	
	    a.precio = stof(precioStr);
	    a.anio = stoi(anioStr);
	
	    archivo.close();
		}
	};

class PersonaO{
    public:
    string nombre, am, ap, genero;
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
	    ofstream archivo("persona.csv");
	
	    if (!archivo) {
	        cout << "No se pudo crear el archivo\n";
	        return;
	    }
	
	    archivo << p.nombre << endl;
	    archivo << p.am << endl;
	    archivo << p.ap << endl;
	    archivo << p.genero << endl;
	    archivo << p.edad << endl;
	
	    archivo.close();
	}	
	
	void leerPersona(PersonaO &p) {
	    ifstream archivo("persona.txt");
	
	    if (!archivo) {
	        cout << "No se pudo abrir el archivo\n";
	        return;
	    }
	
	    getline(archivo, p.nombre);
	    getline(archivo, p.am);
	    getline(archivo, p.ap);
	
	    archivo >> p.genero;
	    archivo >> p.edad;
	
	    archivo.close();
	}
    //constructor por default
    
    

};

#endif
