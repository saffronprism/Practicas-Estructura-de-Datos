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

    void pedirDatos() {
        cout << "Datos del Auto" << endl;
        cout << "Ingrese el precio: ";
        cin >> precio;
        cout << "Ingrese el año: ";
        cin >> anio;
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
    //constructor por default

};

#endif