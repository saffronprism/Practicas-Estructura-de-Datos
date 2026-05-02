#ifndef operaciones_h
#define operaciones_h
#include <iostream>
using namespace std;

class declaracion {
    float numeros[5];
    float *ptr; // puntero
    
public:
    declaracion() {
        ptr = numeros; 
    }

    void introducirDatos() {
        for (int i = 0; i < 5; i++) {
            cout << "Introduce el dato " << (i + 1) << ":" << endl;
            cin >> *(ptr + i); 
        }
    }
    
    float getNumero(int index) {
        return *(ptr + index);
    }
};

class operaciones {
public:
    void calcularTodo(declaracion datos) {
        float suma = datos.getNumero(0);
        float maximo = datos.getNumero(0);
        float minimo = datos.getNumero(0);

        for (int i = 1; i < 5; i++) {
            float numeroActual = datos.getNumero(i);

            suma += numeroActual;
            
            if (numeroActual > maximo) {
                maximo = numeroActual;
            }
            if (numeroActual < minimo) {
                minimo = numeroActual;
            }
        }

        float media = suma / 5.0;
        
        cout << "\n--- Resultados de las Operaciones ---" << endl;
        cout << "Suma: " << suma << endl;
        cout << "Media: " << media << endl;
        cout << "Maximo: " << maximo << endl;
        cout << "Minimo: " << minimo << endl;
    }
};

#endif