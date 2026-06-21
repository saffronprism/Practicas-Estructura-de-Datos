#include <iostream>
#include "Archivo.h"
#include "arbol.h"
#include "opciones.h"

using namespace std;

int main() {

    Archivo motor;
    Arbol miArbol;
    EntradaDatos interfazUI;

    // Captura a json
    interfazUI.iniciarCaptura(miArbol);

    string textoJSON = miArbol.generarJSON();

    // guardado
    motor.guardar("arbol.json", textoJSON);

    cout << "\n[EXITO] Arbol guardado en arbol.json"
         << endl;

    return 0;
}
