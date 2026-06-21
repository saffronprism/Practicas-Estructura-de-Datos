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

    string extraerJSON(string texto, string llave){
        string patron = "\"" + llave + "\": ";
        size_t posInicio = texto.find(patron);

        if (posInicio != string::npos){
            posInicio = posInicio + patron.length(); 

            if (texto[posInicio] == '[') {
                size_t posFin = texto.find("]", posInicio); 
                
                if (posFin != string::npos){
                    return texto.substr(posInicio, posFin - posInicio + 1); 
                }
            } 
            else {
                size_t posFin = texto.find(",", posInicio);
                if (posFin == string::npos){
                    posFin = texto.find("\n", posInicio);
                }
                if (posFin != string::npos){
                    return texto.substr(posInicio, posFin - posInicio);
                }
            }
        }

        return "Error: Clave no encontrada";
    }
};

#endif