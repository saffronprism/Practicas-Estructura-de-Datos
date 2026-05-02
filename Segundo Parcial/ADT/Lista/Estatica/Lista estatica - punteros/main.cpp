#include <iostream>
#include "opciones.h"
#include "menu.h"

using namespace std;

int main() {
    introducirDatos rec;
    rec.opcion();
    iniciarLista(rec);
    return 0;
}