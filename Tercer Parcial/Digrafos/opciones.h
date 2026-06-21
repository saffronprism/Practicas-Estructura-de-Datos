#ifndef opciones_h
#define opciones_h
#include "introduccion.h"
#include <iostream>
#include <string>
#include "grafos.h"

using namespace std;

class EntradaDatos {
public:
    void iniciarCaptura(Grafos& miRed) {
        char continuar;
        int contador = 1;
        
        cout << "------- Captura de Grafos -------" << endl;

        do {
            string origen, destino, arista;
            int tiempo; float costo;

            cout << "\n--- RUTA " << contador << " ---" << endl;
            cout << "Origen: "; getline(cin >> ws, origen);
            cout << "Destino: "; getline(cin >> ws, destino);
            cout << "Nombre arista: "; getline(cin >> ws, arista);
            
            cout << "Tiempo (0 si no aplica): ";
            while (!(cin >> tiempo)) {
                cout << "Dato invalido. Ingresa solo numeros: ";
                cin.clear();             
                cin.ignore(10000, '\n'); 
            }
            cin.clear();
            cin.ignore(10000, '\n');
            
            cout << "Costo (0 si no aplica): ";
            while (!(cin >> costo)) {
                cout << "Dato invalido. Ingresa solo numeros: ";
                cin.clear();             
                cin.ignore(10000, '\n');
            }
            cin.clear();
            cin.ignore(10000, '\n'); 

            miRed.agregarRuta(origen, destino, arista, tiempo, costo);
            contador++;

            cout << "\n¿Deseas registrar otra ruta? (s/n): ";
            cin >> continuar;
            cin.clear();
            cin.ignore(10000, '\n');

        } while (continuar == 's' || continuar == 'S');
    }
};

#endif