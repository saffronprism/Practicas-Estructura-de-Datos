#ifndef buscarArbol_h
#define buscarArbol_h
#include <iostream>
#include <string>

using namespace std;

class BuscadorArbol {
public:

    void imprimirCompleto(string json) {
        cout << "\n" << json << endl;
    }

    void buscarPadre(string json, string padre) {

        string patron = "\"padre\": \"" + padre + "\"";
        size_t pos = json.find(patron);

        bool encontrado = false;

        cout << "\nHijos de: " << padre << "\n";

        while (pos != string::npos) {

            encontrado = true;

            size_t posLlaveCierre = json.find("}", pos);

            string bloque =
                json.substr(pos,
                            posLlaveCierre - pos);

            size_t posHijo =
                bloque.find("\"hijo\": \"") + 9;

            string hijo =
                bloque.substr(
                    posHijo,
                    bloque.find("\"", posHijo) - posHijo
                );

            cout << " -> Hijo: " << hijo;

            size_t posArista =
                bloque.find("\"aristaConexion\": \"");

            if (posArista != string::npos) {

                posArista += 20;

                cout << " | Arista: "
                     << bloque.substr(
                            posArista,
                            bloque.find("\"", posArista) - posArista
                        );
            }

            size_t posTiempo =
                bloque.find("\"tiempo\": ");

            if (posTiempo != string::npos) {

                posTiempo += 10;

                cout << " | Tiempo: "
                     << bloque.substr(
                            posTiempo,
                            bloque.find(",", posTiempo) - posTiempo
                        );
            }

            size_t posCosto =
                bloque.find("\"costo\": ");

            if (posCosto != string::npos) {

                posCosto += 9;

                size_t finCosto =
                    bloque.find("\n", posCosto);

                cout << " | Costo: $"
                     << bloque.substr(
                            posCosto,
                            finCosto - posCosto
                        );
            }

            cout << endl;

            pos = json.find(
                    patron,
                    posLlaveCierre
                  );
        }

        if (!encontrado) {
            cout << "No tiene hijos registrados."<< endl;
        }
    }
};

#endif
