#include <iostream>
#include <string>
#include "gestorArchivos.h"
#include "buscarGrafo.h"

using namespace std;

int main() {
    Archivo motorArchivo;
    BuscadorGrafo buscador;
    
    // 1. Extraemos todo el texto de golpe
    string archivoCompleto = motorArchivo.leer("practica_digrafo.json");

    if (archivoCompleto != "") {
        int opcion;
        do {
            cout << "\n--- MENU DIGRAFO ---" << endl;
            cout << "1. Mostrar todo el archivo JSON" << endl;
            cout << "2. Buscar conexiones directas de un nodo" << endl;
            cout << "3. Calcular ruta mas corta (Dijkstra)" << endl;
            cout << "4. Salir" << endl;
            cout << "Opcion: ";

            while (!(cin >> opcion)) {
                cout << "Error: Elige una opcion con numero (1-4): ";
                cin.clear();
                cin.ignore(10000, '\n');
            }
            cin.ignore();

            if (opcion == 1) {
                buscador.imprimirCompleto(archivoCompleto); // se muestra todo el digrafo
                
            } else if (opcion == 2) {
                string nodo;
                cout << "Ingresa el nombre del nodo: ";
                getline(cin, nodo);
                buscador.buscarNodo(archivoCompleto, nodo);
                
            } else if (opcion == 3) {
                string origen, destino;
                cout << "Ingresa el nodo de ORIGEN: ";
                getline(cin, origen);
                cout << "Ingresa el nodo de DESTINO: ";
                getline(cin, destino);
                
                // Ejecuta Dijkstra
                buscador.calcularDijkstraJSON(archivoCompleto, origen, destino);
            }
            
        } while (opcion != 4);
        
    } else {
        cout << "El archivo no existe o esta vacio. Checa que no este abierto o que exista" << endl;
    }

    return 0;
}