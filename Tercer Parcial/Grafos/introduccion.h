#ifndef introduccion_h
#define introduccion_h

#include <string>

using namespace std;

class Conexion {
private:
    string nodoInicial;
    string nodoFinal;
    string aristaConexion;
    int tiempo;
    float costo;

public:
    Conexion(string inicio, string fin, string arista, int t, float c) {
        nodoInicial = inicio;
        nodoFinal = fin;
        aristaConexion = arista;
        tiempo = t;
        costo = c;
    }

    string getInicio() { return nodoInicial; }
    string getFin() { return nodoFinal; }
    string getArista() { return aristaConexion; }
    int getTiempo() { return tiempo; }
    float getCosto() { return costo; }
};



#endif