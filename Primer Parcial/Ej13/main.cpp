#include <iostream>
#include "poo.H"

using namespace std;

int main() {
   
    const int totalPersonas = 3; 
    PersonaO listaPersonas[totalPersonas]; 
    
    PersonaO *ptrPersonas;
    ptrPersonas = listaPersonas; 

    cout << "Registro" << endl;
    
    for (int i = 0; i < totalPersonas; i++) {
        cout << "\nIngresando datos de la persona " << (i + 1) << ":" << endl;
        (ptrPersonas + i)->pedirDatos();
    }

    cout << "Personas en el registro:" << endl;
    
    for (int i = 0; i < totalPersonas; i++) {
        cout << "\nPerfil " << (i + 1) << ":" << endl;
        (ptrPersonas + i)->presentarse();
    }

    return 0;
}