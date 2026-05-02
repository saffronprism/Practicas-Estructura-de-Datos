#include <iostream>
#include <cstring>
#include "poo.h"

using namespace std;

int main() {
    PersonaO p1;
    PersonaO p2;

    strcpy(p1.nombre, "Edwin");
    strcpy(p1.ap, "Perez");
    strcpy(p1.am, "Lopez");
    p1.genero = 'M';
    p1.edad = 20;

    strcpy(p2.nombre, "Ana");
    strcpy(p2.ap, "Gomez");
    strcpy(p2.am, "Ruiz");
    p2.genero = 'F';
    p2.edad = 19;

  
    p1.siguiente = &p2; 
    p2.siguiente = NULL; 
    cout << "Datos de P1:" << endl;
    p1.presentarse();

    cout << "P2:" <<endl;
    p1.siguiente->presentarse(); 

    return 0;
}