#ifndef gestorArchivos_h
#define gestorArchivos_h

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

    //recortar datos en XML
    string extraerXML(string texto, string etiqueta) {
        string tagInicio = "<" + etiqueta + ">";
        string tagFin = "</" + etiqueta + ">";
        size_t posInicio = texto.find(tagInicio);

        if (posInicio != string::npos) {
            posInicio = posInicio + tagInicio.length(); 
            size_t posFin = texto.find(tagFin, posInicio); 
            if (posFin != string::npos) {
                // Tijeretazo limpio
                return texto.substr(posInicio, posFin - posInicio); 
            }
        }
        return "Error: Etiqueta XML no encontrada";
    }
};

#endif