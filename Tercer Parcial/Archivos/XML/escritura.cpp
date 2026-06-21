#include <iostream>
#include <string>
#include "gestorArchivos.h"     
#include "opciones.h"

using namespace std;

int main() {
    Archivo motorArchivo;
    introducirDatos misDatos;

    cout << "///// Sistema de Escritura en XML /////" << endl;
    misDatos.opcion();
    string textoXML = misDatos.generarXML();
    motorArchivo.guardar("datos_alumnos.xml", textoXML);
    cout << "El archivo datos_alumnos.xml ha sido generado." << endl;

    return 0;
}