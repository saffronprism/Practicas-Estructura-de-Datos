#ifndef grafos_h
#define grafos_h
#include <vector>
#include <string>
#include "introduccion.h"

using namespace std;

class Grafos {
private:
    vector<Conexion> rutas;

public:
    // los grafos van a 2 direcciones, se hace la ruta invertida
    void agregarRuta(string inicio, string fin, string arista, int t, float c) {
        
        Conexion rutaIda(inicio, fin, arista, t, c);
        rutas.push_back(rutaIda);

        Conexion rutaRegreso(fin, inicio, arista, t, c);
        rutas.push_back(rutaRegreso);
    }

    string generarJSON() {
        string json = "{\n\t\"rutas\": [\n";
        for (size_t i = 0; i < rutas.size(); i++) {
            json += "\t\t{\n";
            json += "\t\t\t\"nodoInicial\": \"" + rutas[i].getInicio() + "\",\n";
            json += "\t\t\t\"nodoFinal\": \"" + rutas[i].getFin() + "\",\n";
            // NOTA: Aqui ya no le ponemos coma al final por si es el ultimo dato
            json += "\t\t\t\"aristaConexion\": \"" + rutas[i].getArista() + "\""; 
            
            if (rutas[i].getTiempo() > 0) {
                json += ",\n\t\t\t\"tiempo\": " + to_string(rutas[i].getTiempo());
            }
            if (rutas[i].getCosto() > 0) {
                json += ",\n\t\t\t\"costo\": " + to_string(rutas[i].getCosto());
            }
            
            json += "\n\t\t}";
            if (i < rutas.size() - 1) json += ","; 
            json += "\n";
        }
        json += "\t]\n}";
        return json;
    }
};

#endif