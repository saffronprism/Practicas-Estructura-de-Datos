#ifndef grafos_h
#define grafos_h
#include <vector>
#include <string>
#include <iostream>
#include <queue>
#include <map>
#include <limits>
#include <algorithm>
#include "introduccion.h"

using namespace std;

class Grafos {
private:
    vector<Conexion> rutas;

public:
    void agregarRuta(string inicio, string fin, string arista, int t, float c) {
        Conexion nuevaRuta(inicio, fin, arista, t, c);
        rutas.push_back(nuevaRuta);
    }

    string generarJSON() {
        string json = "{\n\t\"rutas\": [\n";
        for (size_t i = 0; i < rutas.size(); i++) {
            json += "\t\t{\n";
            json += "\t\t\t\"nodoInicial\": \"" + rutas[i].getInicio() + "\",\n";
            json += "\t\t\t\"nodoFinal\": \"" + rutas[i].getFin() + "\",\n";
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

    void calcularDijkstra(string origen, string destino) {
        map<string, vector<pair<string, float>>> adj;
        map<string, float> distancias;
        map<string, string> rutaPrevia;

        for (size_t i = 0; i < rutas.size(); i++) {
            string u = rutas[i].getInicio();
            string v = rutas[i].getFin();
            float w = rutas[i].getCosto();
            adj[u].push_back({v, w});
            distancias[u] = numeric_limits<float>::max();
            distancias[v] = numeric_limits<float>::max();
        }

        if (distancias.find(origen) == distancias.end() || distancias.find(destino) == distancias.end()) {
            cout << "Origen o destino no validos.\n";
            return;
        }

        distancias[origen] = 0;
        priority_queue<pair<float, string>, vector<pair<float, string>>, greater<pair<float, string>>> pq;
        pq.push({0, origen});

        while (!pq.empty()) {
            string actual = pq.top().second;
            float costoActual = pq.top().first;
            pq.pop();

            if (actual == destino) break;
            if (costoActual > distancias[actual]) continue;

            for (auto const& conexion : adj[actual]) {
                string vecino = conexion.first;
                float peso = conexion.second;
                float nuevoCosto = costoActual + peso;

                if (nuevoCosto < distancias[vecino]) {
                    distancias[vecino] = nuevoCosto;
                    rutaPrevia[vecino] = actual;
                    pq.push({nuevoCosto, vecino});
                }
            }
        }

        if (distancias[destino] == numeric_limits<float>::max()) {
            cout << "No hay ruta posible.\n";
            return;
        }

        vector<string> caminoFinal;
        for (string at = destino; at != ""; at = rutaPrevia[at]) {
            caminoFinal.push_back(at);
        }
        reverse(caminoFinal.begin(), caminoFinal.end());

        cout << "\nRuta: ";
        for (size_t i = 0; i < caminoFinal.size(); i++) {
            cout << caminoFinal[i] << (i < caminoFinal.size() - 1 ? " -> " : "");
        }
        cout << "\nCosto total: " << distancias[destino] << "\n";
    }
};

#endif