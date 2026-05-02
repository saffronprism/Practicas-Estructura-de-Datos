#ifndef MENU_H
#define MENU_H
#include <iostream>
#include "adt.h"
#include "opciones.h"
using namespace std;

template <typename T>
void correrMenu(PilaL<T>& est) {
    int opc; T val;
    cout << "\nDatos recibidos, la nueva pila es:\n";
    est.mostrar();
    do {
        cout << "\n-Menu de interaccion con la pila\n";
        cout << "1.- Insertar  2.- Remover  3.- Vaciar  4.- Mostrar  5.- Salir\nElige: ";
        cin >> opc;
        switch(opc) {
            case 1: cout<<"Valor a insertar? "; cin>>val; est.insertar(val); break;
            case 2: est.remover(); break;
            case 3: est.vaciar(); break;
            case 4: est.mostrar(); break;
            case 5: break;
            default: cout<<"Opcion invalida\n";
            cin.clear();
        }
    } while(opc != 5);
}

void iniciarPila(introducirDatos& rec) {
    if(rec.o == 1) {
        PilaL<int> est; 
        for(int i=0; i<rec.alumnoN; i++) est.insertar(rec.edades[i]);
        correrMenu(est);
    } else if(rec.o == 2) {
        PilaL<char> est; 
        for(int i=0; i<rec.alumnoN; i++) est.insertar(rec.grupos[i]);
        correrMenu(est);
    } else if(rec.o == 3) {
        PilaL<float> est; 
        for(int i=0; i<rec.alumnoN; i++) est.insertar(rec.calificacion[i]);
        correrMenu(est);
    }
}
#endif