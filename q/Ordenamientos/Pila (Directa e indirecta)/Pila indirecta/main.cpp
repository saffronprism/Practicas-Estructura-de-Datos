#include <iostream>
#include "opciones.h"
#include "ord.h"

using namespace std;

int main() {
    introducirDatos rec;
    rec.opcion();
    burbDinamica ord;
    int f;

    cout << "2.-Punteros 3.-Librerias\n";
    cin >> f;

    if(f==2) {
        if(rec.o==1) {
            int* ptrs[15];
            for(int i=0; i<rec.alumnoN; i++) ptrs[i] = &rec.edades[i];
            ord.ordPunter(ptrs, rec.alumnoN);
            ord.mostrar(ptrs, rec.alumnoN);
        }
        else if(rec.o==2) {
            char* ptrs[15];
            for(int i=0; i<rec.alumnoN; i++) ptrs[i] = &rec.grupos[i];
            ord.ordPunter(ptrs, rec.alumnoN);
            ord.mostrar(ptrs, rec.alumnoN);
        }
        else if(rec.o==3) {
            float* ptrs[15];
            for(int i=0; i<rec.alumnoN; i++) ptrs[i] = &rec.calificacion[i];
            ord.ordPunter(ptrs, rec.alumnoN);
            ord.mostrar(ptrs, rec.alumnoN);
        }
    }
    else if(f==3) {
        if(rec.o==1) {
            int* ptrs[15];
            for(int i=0; i<rec.alumnoN; i++) ptrs[i] = &rec.edades[i];
            ord.ordLibreria(ptrs, rec.alumnoN);
            ord.mostrar(ptrs, rec.alumnoN);
        }
        else if(rec.o==2) {
            char* ptrs[15];
            for(int i=0; i<rec.alumnoN; i++) ptrs[i] = &rec.grupos[i];
            ord.ordLibreria(ptrs, rec.alumnoN);
            ord.mostrar(ptrs, rec.alumnoN);
        }
        else if(rec.o==3) {
            float* ptrs[15];
            for(int i=0; i<rec.alumnoN; i++) ptrs[i] = &rec.calificacion[i];
            ord.ordLibreria(ptrs, rec.alumnoN);
            ord.mostrar(ptrs, rec.alumnoN);
        }
    }
    
    return 0;
}