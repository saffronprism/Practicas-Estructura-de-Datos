#ifndef archivo_h
#define archivo_h
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class Archivo {
public:

    void guardar(string nombreArchivo, string contenido) {
        ofstream arch(nombreArchivo.c_str());

        if (arch.is_open()) {
            arch << contenido;
            arch.close();
        }
        else {
            cout << "ERROR: No se pudo abrir el archivo." << endl;
        }
    }

    string leer(string nombreArchivo) {
        ifstream archivo(nombreArchivo.c_str());

        string contenido;
        string linea;

        if (archivo.is_open()) {
            while (getline(archivo, linea)) {
                contenido += linea + "\n";
            }

            archivo.close();
        }
        else {
            cout << "ERROR: No se pudo abrir el archivo en modo lectura." << endl;
        }

        return contenido;
    }
};

#endif
