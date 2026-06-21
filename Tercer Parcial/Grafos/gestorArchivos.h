#include <iostream>
#include <string>
#include <fstream>

using namespace std;

class Archivo
{
    public:
    void guardar(string nombreArchivo, string contenido)
    {
        ofstream Archivo(nombreArchivo);

        if (Archivo.is_open()){
            Archivo << contenido;
            Archivo.close();
        }
        else {cout << "ERROR: Archivo no encontrado" << endl;}
    }

    string leer (string nombreArchivo)
    {
        ifstream Archivo(nombreArchivo);
        string contenido = "";
        string saltoLinea;

        if (Archivo.is_open()){
            while(getline(Archivo,saltoLinea))
            {
                contenido+= saltoLinea + "\n";
            }
            Archivo.close();
        }
        else{cout<< "ERROR: no se pudo abiri el archivo en modo lectura" <<endl;}

        return contenido;
    }
};