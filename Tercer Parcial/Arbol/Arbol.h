#ifndef arbol_h
#define arbol_h

#include <iostream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

class ConexionArbol {
private:
    string padre;
    string hijo;
    string arista;
    int tiempo;
    float costo;

public:
    ConexionArbol(string p, string h, string a, int t, float c) {
        padre = p;
        hijo = h;
        arista = a;
        tiempo = t;
        costo = c;
    }

    string getPadre() { return padre; }
    string getHijo() { return hijo; }
    string getArista() { return arista; }
    int getTiempo() { return tiempo; }
    float getCosto() { return costo; }
};

class Arbol {
private:
    vector<ConexionArbol> relaciones;

    // conversores compatibles con C++ antiguo
    string convertirInt(int valor) {
        stringstream ss;
        ss << valor;
        return ss.str();
    }

    string convertirFloat(float valor) {
        stringstream ss;
        ss << valor;
        return ss.str();
    }

public:

    void agregarHijo(string padre,
                     string hijo,
                     string arista,
                     int tiempo,
                     float costo) {

        ConexionArbol nuevaRelacion(
            padre,
            hijo,
            arista,
            tiempo,
            costo
        );

        relaciones.push_back(nuevaRelacion);
    }

    string generarJSON() {

        string json = "{\n";
        json += "\t\"arbol\": [\n";

        for (size_t i = 0; i < relaciones.size(); i++) {

            json += "\t\t{\n";

            json += "\t\t\t\"padre\": \"" +
                    relaciones[i].getPadre() +
                    "\",\n";

            json += "\t\t\t\"hijo\": \"" +
                    relaciones[i].getHijo() +
                    "\",\n";

            json += "\t\t\t\"aristaConexion\": \"" +
                    relaciones[i].getArista() +
                    "\",\n";

            json += "\t\t\t\"tiempo\": " +
                    convertirInt(relaciones[i].getTiempo()) +
                    ",\n";

            json += "\t\t\t\"costo\": " +
                    convertirFloat(relaciones[i].getCosto()) +
                    "\n";

            json += "\t\t}";

            if (i < relaciones.size() - 1)
                json += ",";

            json += "\n";
        }

        json += "\t]\n";
        json += "}";

        return json;
    }
};

#endif


