#include <iostream>
#include "opciones.h"
#include "ord.h"

using namespace std;

int main() {
    introducirDatos rec;
    rec.opcion();
    quickEst ord;
    int f;

    cout << "1.-Arreglos 3.-Librerias\n";
    cin >> f;

    if(f==1) {
        if(rec.o==1){
            ord.ordArreglo(rec.edades, rec.alumnoN);
            ord.mostrar(rec.edades, rec.alumnoN);
        }
        else if(rec.o==2){
            ord.ordArreglo(rec.grupos, rec.alumnoN);
            ord.mostrar(rec.grupos, rec.alumnoN);
        }
        else if(rec.o==3){
            ord.ordArreglo(rec.calificacion, rec.alumnoN);
            ord.mostrar(rec.calificacion, rec.alumnoN);
        }
    }
    else if(f==3) {
        if(rec.o==1){
            ord.ordLibreria(rec.edades, rec.alumnoN);
            ord.mostrar(rec.edades, rec.alumnoN);
        }
        else if(rec.o==2){
            ord.ordLibreria(rec.grupos, rec.alumnoN);
            ord.mostrar(rec.grupos, rec.alumnoN);
        }
        else if(rec.o==3){
            ord.ordLibreria(rec.calificacion, rec.alumnoN);
            ord.mostrar(rec.calificacion, rec.alumnoN);
        }
    }
    
    return 0;
}