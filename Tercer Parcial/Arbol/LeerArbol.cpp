#include <iostream>
#include <string>
#include "buscarArbol.h"
#include "Archivo.h"

using namespace std;

int main() {

    Archivo motorArchivo;
    BuscadorArbol buscador;

    string archivoCompleto =
        motorArchivo.leer("arbol.json");

    if (archivoCompleto != "") {

        int opcion;

        do {

            cout << "\nMENU" << endl;
            cout << "1- Mostrar todo el arbol" << endl;
            cout << "2. Buscar hijos de un nodo" << endl;
            cout << "3. Salir" << endl;
            cout << "Opcion: ";

            while (!(cin >> opcion)) {
                cout << "Error. Ingresa una opcion valida: ";
                cin.clear();
                cin.ignore(10000, '\n');
            }

            cin.ignore();

            switch (opcion) {

                case 1:
                    buscador.imprimirCompleto(
                        archivoCompleto
                    );
                    break;

                case 2: {
                    string padre;

                    cout << "Ingresa el nombre del nodo padre: ";
                    getline(cin, padre);

                    buscador.buscarPadre(
                        archivoCompleto,
                        padre
                    );

                    break;
                }

                case 3:
                    cout << "Saliendo..." << endl;
                    break;

                default:
                    cout << "Opcion invalida." << endl;
            }

        } while (opcion != 3);

    }
    else {
        cout << "No se pudo leer el archivo."
             << endl;
    }

    return 0;
}
