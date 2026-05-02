#ifndef INTERFAZ_H
#define INTERFAZ_H

template <class T>
class InterfazBase {
public:
    virtual void insertar(T val) {} 
    virtual void remover() {}
    virtual void mostrar() {}
};

#endif