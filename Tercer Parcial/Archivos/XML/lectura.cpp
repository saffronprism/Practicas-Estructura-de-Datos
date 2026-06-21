#include <iostream>
#include <string>
#include "gestorArchivos.h"
#include "opciones.h"
#include "menu.h"

using namespace std;

void restaurarDatosDesdeXML(string xml, introducirDatos& datos, Archivo& motor) {
    string crit = motor.extraerXML(xml, "CriterioOrdenamiento");
    if (crit.find("Error") == string::npos) datos.o = stoi(crit);

    string tot = motor.extraerXML(xml, "TotalAlumnos");
    if (tot.find("Error") == string::npos) datos.alumnoN = stoi(tot);

    if (datos.o == 1) {
        string str = motor.extraerXML(xml, "Edades");
        size_t pos = 0;
        for (int i = 0; i < datos.alumnoN; i++) {
            datos.edades[i] = stoi(str.substr(pos));
            pos = str.find(",", pos);
            if (pos != string::npos) pos += 2;
        }
    } else if (datos.o == 2) {
        string str = motor.extraerXML(xml, "Grupos");
        size_t pos = 0;
        for (int i = 0; i < datos.alumnoN; i++) {
            datos.grupos[i] = str[pos];
            pos = str.find(",", pos);
            if (pos != string::npos) pos += 2;
        }
    } else if (datos.o == 3) {
        string str = motor.extraerXML(xml, "Calificaciones");
        size_t pos = 0;
        for (int i = 0; i < datos.alumnoN; i++) {
            datos.calificacion[i] = stof(str.substr(pos));
            pos = str.find(",", pos);
            if (pos != string::npos) pos += 2;
        }
    }
}

int main() {
    Archivo motorArchivo;

    if (motorArchivo.leer("datos_alumnos.xml") == "") {
        cout << "El archivo esta vacio o no existe. Ejecuta el Escritor primero." << endl;
        return 0;
    }

    int opcion;
    do {
        cout << "\n=== SISTEMA LECTOR XML ===" << endl;
        cout << "1. Ver archivo XML en crudo" << endl;
        cout << "2. Cargar XML y abrir Cola Dinamica" << endl;
        cout << "3. Salir" << endl;
        cout << "Opcion: ";
        
        while (!(cin >> opcion)) {
            cin.clear();
            cin.ignore(10000, '\n');
        }
        cin.ignore(10000, '\n'); 

        if (opcion == 1) {
            string xmlFresco = motorArchivo.leer("datos_alumnos.xml");
            cout << "\n" << xmlFresco << endl;
            
        } else if (opcion == 2) {
            string xmlFresco = motorArchivo.leer("datos_alumnos.xml");
            introducirDatos datosRestaurados;
            restaurarDatosDesdeXML(xmlFresco, datosRestaurados, motorArchivo);
            iniciarCola(datosRestaurados);
        }
    } while (opcion != 3);

    return 0;
}