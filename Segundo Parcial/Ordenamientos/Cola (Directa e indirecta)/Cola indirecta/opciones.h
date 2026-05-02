#ifndef opciones_h
#define opciones_h
#include "ord.h"
#include "introduccion.h"
#include <iostream>
#include <sstream>
#include <string>

using namespace std;


class introducirDatos{
    static const int Max_Alumnos=15;
    public:
    int edades[Max_Alumnos];
    char grupos[Max_Alumnos];
    float calificacion[Max_Alumnos];
    int alumnoN=0;
    int o;
    int a;
    void opcion(){
        
        cout << "ingresa como vas a ordenar los datos" << endl;
        cout << "1.-Por Edad" << endl;
        cout << "2.-Por Grupo" << endl; 
        cout <<"3.- Por Calificacion"<< endl;
        cin >> o;
        cin.ignore();

        introduccionDeDatos(o);
    };

    void introduccionDeDatos (int o)
    {
        string ingreso;
        char comas;

        cout << "ingresa los datos que requieras" << endl;
        getline(cin,ingreso);
        stringstream datos(ingreso);

        if (o == 1)
        {
        int temp;
        while (datos >> temp && alumnoN < Max_Alumnos)
            {
                edades[alumnoN] = temp;
                alumnoN++;
                datos >> comas;
            }          
        }
        else if (o==2)
        {
            char temp;
            while  (datos >> temp && alumnoN < Max_Alumnos)
            {
                grupos[alumnoN]=temp;
                alumnoN++;
                datos >> comas;
            }
        }
        else if (o == 3)
        {
            float temp;
            while (datos >> temp && alumnoN < Max_Alumnos)
            {
                calificacion[alumnoN]=temp;
                alumnoN++;
                datos >> comas;
            }
        }
    }

};
#endif