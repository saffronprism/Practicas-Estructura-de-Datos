#ifndef opciones_h
#define opciones_h

#include <iostream>
#include <string>
#include "arbol.h"

using namespace std;

class EntradaDatos {

public:

    void iniciarCaptura(Arbol& miArbol) {

        char continuar;
        int contador = 1;

        cout << "------- Captura de Arbol -------" << endl;

        do {

            string padre, hijo, arista;
            int tiempo;
            float costo;

            cout << "\n--- CONEXION " << contador << " ---" << endl;

            cin.ignore(); // limpia buffer antes de getline

            cout << "Padre: ";
            getline(cin, padre);

            cout << "Hijo [nuevo nodo]: ";
            getline(cin, hijo);

            cout << "Nombre arista: ";
            getline(cin, arista);

            cout << "Tiempo (0 si no aplica): ";
            cin >> tiempo;

            while (cin.fail()) {
                cout << "Dato invalido. Ingresa solo numeros: ";
                cin.clear();
                cin.ignore(10000, '\n');
                cin >> tiempo;
            }

            cout << "Costo (0 si no aplica): ";
            cin >> costo;

            while (cin.fail()) {
                cout << "Dato invalido. Ingresa solo numeros: ";
                cin.clear();
                cin.ignore(10000, '\n');
                cin >> costo;
            }

            cin.ignore(10000, '\n');

            miArbol.agregarHijo(
                padre,
                hijo,
                arista,
                tiempo,
                costo
            );

            contador++;

            cout << "\n¿Deseas registrar otra conexion? (s/n): ";
            cin >> continuar;

        } while (continuar == 's' || continuar == 'S');
    }
};

#endif
