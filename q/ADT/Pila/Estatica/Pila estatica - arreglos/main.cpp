#include <iostream>
#include "opciones.h"
#include "menu.h"

using namespace std;

int main() {
    introducirDatos rec;
    rec.opcion();
    iniciarPila(rec);
    return 0;
}