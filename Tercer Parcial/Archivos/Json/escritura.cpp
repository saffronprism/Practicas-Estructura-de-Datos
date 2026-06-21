#include <iostream>
#include <string>
#include "gestorArchivos.h"     
#include "opciones.h"

using namespace std;

int main() {
    Archivo motorArchivo;
    introducirDatos misDatos;

    cout << "///// Sistema de Escritura en JSON /////" << endl;
    misDatos.opcion();
    string textoJSON = misDatos.generarJSON();
    motorArchivo.guardar("datos_alumnos.json", textoJSON);
    cout << "El archivo datos_alumnos.json ha sido generado." << endl;

    return 0;
}