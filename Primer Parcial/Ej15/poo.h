#ifndef poo_h
#define poo_h
#include "triangulo.h"
#include "polvo.h"
#include <iostream>
#include <cmath>
using namespace std;
class trianguloAccion{
    char coma;
    punto puntomedio;
    int triangulosGenerados, triangulosTotales;
    public:
    punto p1, p2, p3;
    int profundidad;
    
    triangulo ingresarDatos()
    {
        cout << "ingresa las 3 coordenadas de tu triangulo" << endl;
        cin >> p1.x >> coma >> p1.y;
        cin >> p2.x >> coma >> p2.y;
        cin >> p3.x >> coma >> p3.y;
        cout << "ingresa el nivel al que quieres llegar" << endl;
        cin >> profundidad;
        return triangulo(p1, p2, p3);
    }

      punto sacarPuntoMedio (punto a, punto b)
    {
        punto medio;
        medio.x = (a.x + b.x)/2;
        medio.y = (a.y + b.y)/2;
        return medio;
    };
    void realizarOperaciones(triangulo t, int profundidad)
    {
        
    if (profundidad == 0) {
       cout << "Nivel " << profundidad << " del triangulo: " <<endl;
        cout << "P1(" << t.getV1().x << "," << t.getV1().y << ") ";
        cout << "P2(" << t.getV2().x << "," << t.getV2().y << ") ";
        cout << "P3(" << t.getV3().x << "," << t.getV3().y << ")" << endl;
        return;
    }

    
    punto m12 = sacarPuntoMedio(t.getV1(), t.getV2());
    punto m23 = sacarPuntoMedio(t.getV2(), t.getV3());
    punto m31 = sacarPuntoMedio(t.getV3(), t.getV1());

    // 2. Armas los 3 triángulos
    triangulo tArriba(t.getV1(), m12, m31);
    triangulo tIzquierda(t.getV2(), m12, m23);
    triangulo tDerecha(t.getV3(), m23, m31);

    // 3. Llamas a la recursividad
    realizarOperaciones(tArriba, profundidad - 1);
    realizarOperaciones(tIzquierda, profundidad - 1);
    realizarOperaciones(tDerecha, profundidad - 1);

    triangulosGenerados= pow(3,profundidad);
    triangulosTotales= ((pow(3, profundidad+1))-1)/2;
    }

    void desplegarResultados(){

        cout << "se generaron un total de " << triangulosGenerados << " triangulos."<< endl;
        cout << "esto dio un total de " << triangulosTotales << " triangulos en " << profundidad << "niveles." << endl;
    }
};

class polvoAccion {
public:
    int profundidad;
    int lineasGeneradas, lineasTotales;

    Segmento ingresarDatos() {
        float x, tlong; 

        cout << "ingresa la coordenada X donde inicia la linea: ";
        cin >> x;
        cout << "ingresa la longitud de la linea: ";
        cin >> tlong;
        cout << "ingresa la profundidad a la que quieres llegar: ";
        cin >> profundidad;

        return Segmento(x, tlong);
    }

    void realizarOperaciones(Segmento seg, int prof) {
        if (prof == 0) {
            cout << "segmento final:" << seg.getXInicial() << ", con longitud: " << seg.getLongitud() << endl;
            return;
        }

        float nuevaLongitud = seg.getLongitud() / 3.0;
        
        Segmento izq(seg.getXInicial(), nuevaLongitud);
        Segmento der(seg.getXInicial() + (nuevaLongitud * 2.0), nuevaLongitud);

        realizarOperaciones(izq, prof - 1);
        realizarOperaciones(der, prof - 1);

        lineasGeneradas = pow(2, profundidad); 
        lineasTotales = pow(2, profundidad + 1) - 1;
    }

    void desplegarResultados() {
        cout << "Se generaron un total de " << lineasGeneradas << " segmentos chiquitos." << endl;
        cout << "Esto dio un total de " << lineasTotales << " segmentos en " << profundidad << " niveles." << endl;
    }
};
struct opciones
{
    private:
    int seleccion;
    public:
    void eleccion()
    {
        cout << "selecciona una opcion para escoger:" << endl;
        cout << "1.- triangulo de sierpinski" << endl;
        cout << "2.- polvo de cantor" << endl;
        cin >> seleccion;

        switch (seleccion)
        {
        case 1:{
            trianguloAccion accionT;
            triangulo trianguloBase = accionT.ingresarDatos();
            accionT.realizarOperaciones(trianguloBase, accionT.profundidad);
            accionT.desplegarResultados();
            break;
        }
        case 2:{
            polvoAccion accionP;
            Segmento segmentoBase = accionP.ingresarDatos();
            accionP.realizarOperaciones(segmentoBase, accionP.profundidad);
            accionP.desplegarResultados();
            break;
        }
        default:
        cout << "esa accion no es posible, intentalo de nuevo" << endl;
            break;
        }
    }
};


#endif