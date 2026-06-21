#include <iostream>
#include "gestorArchivos.h"         
#include "grafos.h"   
#include "opciones.h"    

using namespace std;

int main() {
    Archivo motor;
    Grafos miRed;
    EntradaDatos interfazUI;

    // 1. Fase de captura de datos
    interfazUI.iniciarCaptura(miRed);

    // 2. Serializacion a formato JSON
    string textoJSON = miRed.generarJSON();

    // 3. Persistencia en el disco duro
    motor.guardar("practica_grafo.json", textoJSON);

    cout << "\nEl proyecto fue guardado exitosamente como practica_grafo.json" << endl;

    return 0;
}