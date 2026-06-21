#include <iostream>
#include <string>
#include "gestorArchivos.h"
#include "opciones.h"
#include "menu.h"

using namespace std;

void restaurarDatosDesdeJSON(string json, introducirDatos& datos, Archivo& motor) {
    string crit = motor.extraerJSON(json, "criterio_ordenamiento");
    if (crit.find("Error") == string::npos && crit != "") datos.o = stoi(crit);

    string tot = motor.extraerJSON(json, "total_alumnos");
    if (tot.find("Error") == string::npos && tot != "") datos.alumnoN = stoi(tot);

    if (datos.o == 1) {
        string str = motor.extraerJSON(json, "edades");
        size_t pos = 0;
        if(str[0] == '[') str = str.substr(1, str.length() - 2);
        for (int i = 0; i < datos.alumnoN; i++) {
            datos.edades[i] = stoi(str.substr(pos));
            pos = str.find(",", pos);
            if (pos != string::npos) pos += 2;
        }
    } else if (datos.o == 2) {
        string str = motor.extraerJSON(json, "grupos");
        size_t pos = 0;
        if(str[0] == '[') str = str.substr(1, str.length() - 2);
        for (int i = 0; i < datos.alumnoN; i++) {
            size_t start = str.find("\"", pos);
            if (start != string::npos) {
                datos.grupos[i] = str[start + 1];
                pos = str.find(",", start) + 1;
            }
        }
    } else if (datos.o == 3) {
        string str = motor.extraerJSON(json, "calificaciones");
        size_t pos = 0;
        if(str[0] == '[') str = str.substr(1, str.length() - 2);
        for (int i = 0; i < datos.alumnoN; i++) {
            datos.calificacion[i] = stof(str.substr(pos));
            pos = str.find(",", pos);
            if (pos != string::npos) pos += 2;
        }
    }
}

int main() {
    Archivo motorArchivo;

    // Comprobamos primero si el archivo existe antes de lanzar el menu
    if (motorArchivo.leer("datos_alumnos.json") == "") {
        cout << "El archivo esta vacio o no existe. Ejecuta el Escritor primero." << endl;
        return 0;
    }

    int opcion;
    do {
        cout << "\n=== SISTEMA LECTOR JSON ===" << endl;
        cout << "1. Ver archivo JSON en crudo" << endl;
        cout << "2. Cargar JSON y abrir Cola Dinamica" << endl;
        cout << "3. Salir" << endl;
        cout << "Opcion: ";
        
        while (!(cin >> opcion)) {
            cin.clear();
            cin.ignore(10000, '\n');
        }
        cin.ignore(10000, '\n');

        if (opcion == 1) {
            string jsonFresco = motorArchivo.leer("datos_alumnos.json");
            cout << "\n" << jsonFresco << endl;
            
        } else if (opcion == 2) {
            string jsonFresco = motorArchivo.leer("datos_alumnos.json");
            introducirDatos datosRestaurados;
            restaurarDatosDesdeJSON(jsonFresco, datosRestaurados, motorArchivo);
            iniciarCola(datosRestaurados);
        }
    } while (opcion != 3);

    return 0;
}