#ifndef buscarGrafo_h
#define buscarGrafo_h
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <queue>
#include <limits>
#include <algorithm>

using namespace std;
//Estructura temporal para el algoritmo de Dijkstra
struct AristaTemp {
    string destino;
    float costo;
    float tiempo;
};

class BuscadorGrafo {
public:
    // Metodo 1: Imprimir todo el bloque
    void imprimirCompleto(string json) {
        cout << "\n" << json << endl;
    }

    // Metodo 2: Buscar conexiones directas
    void buscarNodo(string json, string nodo) {
        string patron = "\"nodoInicial\": \"" + nodo + "\"";
        size_t pos = json.find(patron);
        bool encontrado = false;

        cout << "\nRuta(s) desde: " << nodo << "\n";

        while (pos != string::npos) {
            encontrado = true;
            size_t posLlaveCierre = json.find("}", pos);
            string bloque = json.substr(pos, posLlaveCierre - pos);

            size_t posFin = bloque.find("\"nodoFinal\": \"") + 14;
            string destino = bloque.substr(posFin, bloque.find("\"", posFin) - posFin);

            cout << " -> Conecta con: " << destino;

            size_t posArista = bloque.find("\"aristaConexion\": \"");
            if (posArista != string::npos) {
                posArista += 19;
                cout << " | Arista: " << bloque.substr(posArista, bloque.find("\"", posArista) - posArista);
            }

            size_t posCosto = bloque.find("\"costo\": ");
            if (posCosto != string::npos) {
                posCosto += 9;
                size_t finCosto = bloque.find_first_of(",\n\r}", posCosto);
                cout << " | Costo: $" << bloque.substr(posCosto, finCosto - posCosto);
            }

            size_t posTiempo = bloque.find("\"tiempo\": ");
            if (posTiempo != string::npos) {
                posTiempo += 10;
                size_t finTiempo = bloque.find_first_of(",\n\r}", posTiempo);
                cout << " | Tiempo: " << bloque.substr(posTiempo, finTiempo - posTiempo);
            }

            cout << endl;
            pos = json.find(patron, posLlaveCierre);
        }

        if (!encontrado) cout << "No hay rutas registradas para este nodo :(." << endl;
    }

    // Calcular Dijkstra(Costo o Tiempo)
    void calcularDijkstraJSON(string json, string origen, string destino) {
        int criterio;
        cout << "\n¿Que variable deseas optimizar para llegar mas rapido/barato?\n";
        cout << "1. Costo (Dinero)\n2. Tiempo (Minutos)\nElige una opcion (1 o 2): ";
        
        while (!(cin >> criterio) || (criterio != 1 && criterio != 2)) {
            cout << "Opcion invalida. Ingresa 1 para Costo o 2 para Tiempo: ";
            cin.clear();
            cin.ignore(10000, '\n');
        }
        cin.ignore(10000, '\n');

        map<string, vector<AristaTemp>> adj;
        map<string, float> distancias;
        map<string, string> rutaPrevia;

        size_t p = json.find("\"nodoInicial\": \"");
        while (p != string::npos) {
            p += 16;
            string u = json.substr(p, json.find("\"", p) - p);

            size_t pFin = json.find("\"nodoFinal\": \"", p) + 14;
            string v = json.substr(pFin, json.find("\"", pFin) - pFin);

            float wCosto = 0, wTiempo = 0;
            size_t llaveCierre = json.find("}", p);
            string bloque = json.substr(p, llaveCierre - p);
            
            size_t pCosto = bloque.find("\"costo\": ");
            if (pCosto != string::npos) {
                pCosto += 9;
                size_t fin = bloque.find_first_of(",\n\r}", pCosto);
                wCosto = stof(bloque.substr(pCosto, fin - pCosto));
            }

            size_t pTiempo = bloque.find("\"tiempo\": ");
            if (pTiempo != string::npos) {
                pTiempo += 10;
                size_t fin = bloque.find_first_of(",\n\r}", pTiempo);
                wTiempo = stof(bloque.substr(pTiempo, fin - pTiempo));
            }

            adj[u].push_back({v, wCosto, wTiempo});
            distancias[u] = numeric_limits<float>::max();
            distancias[v] = numeric_limits<float>::max();

            p = json.find("\"nodoInicial\": \"", llaveCierre);
        }

        if (distancias.find(origen) == distancias.end() || distancias.find(destino) == distancias.end()) {
            cout << "\nUno de los nodos no existe en el archivo. Verifica los nombres.\n";
            return;
        }

        distancias[origen] = 0;
        priority_queue<pair<float, string>, vector<pair<float, string>>, greater<pair<float, string>>> pq;
        pq.push({0, origen});

        while (!pq.empty()) {
            string actual = pq.top().second;
            float pesoAcumulado = pq.top().first;
            pq.pop();

            if (actual == destino) break;
            if (pesoAcumulado > distancias[actual]) continue;

            for (auto const& conexion : adj[actual]) {
                string vecino = conexion.destino;
                float pesoArista = (criterio == 1) ? conexion.costo : conexion.tiempo;
                float nuevoPeso = pesoAcumulado + pesoArista;

                if (nuevoPeso < distancias[vecino]) {
                    distancias[vecino] = nuevoPeso;
                    rutaPrevia[vecino] = actual;
                    pq.push({nuevoPeso, vecino});
                }
            }
        }

        cout << "\n=== RUTA MAS OPTIMA (DIJKSTRA por " << (criterio == 1 ? "Costo" : "Tiempo") << ") ===\n";
        if (distancias[destino] == numeric_limits<float>::max()) {
            cout << "No hay ruta posible para llegar de " << origen << " a " << destino << "\n";
            return;
        }

        vector<string> caminoFinal;
        for (string at = destino; at != ""; at = rutaPrevia[at]) {
            caminoFinal.push_back(at);
        }
        reverse(caminoFinal.begin(), caminoFinal.end());

        cout << "Camino: ";
        for (size_t i = 0; i < caminoFinal.size(); i++) {
            cout << caminoFinal[i] << (i < caminoFinal.size() - 1 ? " -> " : "");
        }
        
        if (criterio == 1) {
            cout << "\nCosto total acumulado: $" << distancias[destino] << "\n";
        } else {
            cout << "\nTiempo total acumulado: " << distancias[destino] << " minutos\n";
        }
    }
};

#endif