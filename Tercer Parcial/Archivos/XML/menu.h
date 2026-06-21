#ifndef MENU_H
#define MENU_H
#include <iostream>
#include <string>
#include "adt.h"
#include "opciones.h"
#include "gestorArchivos.h"

using namespace std;

// Funcion puente para reconstruir el XML y guardarlo en el disco duro
void guardarCambiosXML(introducirDatos& rec) {
    Archivo motor;
    string xml = "<Alumnos>\n";
    xml += "\t<CriterioOrdenamiento>" + to_string(rec.o) + "</CriterioOrdenamiento>\n";
    xml += "\t<TotalAlumnos>" + to_string(rec.alumnoN) + "</TotalAlumnos>\n";
    
    if (rec.o == 1) {
        xml += "\t<Edades>";
        for(int i = 0; i < rec.alumnoN; i++) {
            xml += to_string(rec.edades[i]);
            if(i < rec.alumnoN - 1) xml += ", ";
        }
        xml += "</Edades>\n";
    } else if (rec.o == 2) {
        xml += "\t<Grupos>";
        for(int i = 0; i < rec.alumnoN; i++) {
            xml += rec.grupos[i]; // Es char, se agrega directo
            if(i < rec.alumnoN - 1) xml += ", ";
        }
        xml += "</Grupos>\n";
    } else if (rec.o == 3) {
        xml += "\t<Calificaciones>";
        for(int i = 0; i < rec.alumnoN; i++) {
            xml += to_string(rec.calificacion[i]);
            if(i < rec.alumnoN - 1) xml += ", ";
        }
        xml += "</Calificaciones>\n";
    }
    xml += "</Alumnos>";
    
    motor.guardar("datos_alumnos.xml", xml);
}

template <typename T>
void correrMenu(ColaL<T>& est, introducirDatos& rec) {
    int opc; T val;
    cout << "\nDatos recibidos, la nueva cola es:\n";
    est.mostrar();
    do {
        cout << "\n-Menu de interaccion-cola\n";
        cout << "1.- Insertar  2.- Remover  3.- Vaciar  4.- Mostrar  5.- Salir\nElige: ";
        
        while (!(cin >> opc)) {
            cin.clear();
            cin.ignore(10000, '\n');
        }
        
        bool modificado = false;

        switch(opc) {
            case 1: 
                cout << "Valor a insertar? "; cin >> val; 
                est.insertar(val); 
                
                // Actualizamos el espejo
                if (rec.o == 1) rec.edades[rec.alumnoN] = val;
                else if (rec.o == 2) rec.grupos[rec.alumnoN] = val;
                else if (rec.o == 3) rec.calificacion[rec.alumnoN] = val;
                rec.alumnoN++;
                modificado = true;
                break;
                
            case 2: 
                est.remover(); 
                
                // Desplazamos el espejo simulando el dequeue
                if (rec.alumnoN > 0) {
                    for(int i = 0; i < rec.alumnoN - 1; i++) {
                        if (rec.o == 1) rec.edades[i] = rec.edades[i+1];
                        else if (rec.o == 2) rec.grupos[i] = rec.grupos[i+1];
                        else if (rec.o == 3) rec.calificacion[i] = rec.calificacion[i+1];
                    }
                    rec.alumnoN--;
                    modificado = true;
                }
                break;
                
            case 3: 
                est.vaciar(); 
                rec.alumnoN = 0;
                modificado = true;
                break;
                
            case 4: 
                est.mostrar(); 
                break;
                
            case 5: 
                break;
                
            default: 
                cout << "Opcion invalida\n";
        }

        if (modificado) {
            guardarCambiosXML(rec);
            cout << "\n[!] Cambios guardados exitosamente en datos_alumnos.xml" << endl;
        }

    } while(opc != 5);
}

void iniciarCola(introducirDatos& rec) {
    if(rec.o == 1) {
        ColaL<int> est; 
        for(int i=0; i<rec.alumnoN; i++) est.insertar(rec.edades[i]);
        correrMenu(est, rec);
    } else if(rec.o == 2) {
        ColaL<char> est; 
        for(int i=0; i<rec.alumnoN; i++) est.insertar(rec.grupos[i]);
        correrMenu(est, rec);
    } else if(rec.o == 3) {
        ColaL<float> est; 
        for(int i=0; i<rec.alumnoN; i++) est.insertar(rec.calificacion[i]);
        correrMenu(est, rec);
    }
}
#endif