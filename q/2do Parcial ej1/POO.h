#ifndef poo_H
#define poo_H

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
};

class PersonaO{
    public:
    char nombre[30], am[30], ap[30], genero;
    int edad;
    PersonaO* siguiente;
    void pedirDatos() {
        cout << "Ingresa el nombre: ";
        cin >> nombre;
        cout << "Ingresa el apellido paterno: ";
        cin >> ap;
        cout << "Ingresa el apellido materno: ";
        cin >> am;
        cout << "Ingresa el genero (M/F): ";
        cin >> genero;
        cout << "Ingresa la edad: ";
        cin >> edad;
    }

    void presentarse()
    {
        cout << "Mi nombre es: " << nombre << " " << ap << " " << am << endl;
        cout << "Soy " << genero << " y tengo " << edad << " anios." << endl; 
    }
};

#endif