#ifndef polvo_h
#define polvo_h
#include <iostream>
using namespace std;
class Segmento {
private:
    float xInicial;
    float longitud;
public:
    Segmento(float x, float l) {
        xInicial = x;
        longitud = l;
    }

    // Getters para que tu función recursiva pueda leer los datos
    float getXInicial() { return xInicial; }
    float getLongitud() { return longitud; }

    Segmento () {};
};

#endif