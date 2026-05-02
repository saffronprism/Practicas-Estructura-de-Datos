#ifndef triangulo_h
#define triengulo_h
#include <iostream>
using namespace std;

//sierpunski
struct punto
{
    int x;
    int y;
};
class triangulo {
    int medida;
    double lado_medio;
    punto punto1, punto2, punto3;

    public:
    triangulo (punto vertice1, punto vertice2, punto vertice3)
    {
        punto1=vertice1;
        punto2=vertice2;
        punto3=vertice3;
    };


   punto getV1 () { return punto1; }
   punto getV2 () { return punto2; }
   punto getV3 () { return punto3; }

};

#endif