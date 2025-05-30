#pragma once

#include "Punto.hpp"

using namespace std;

class Circulo {
    private:
        Punto posicion; //centro
        float radio;
    public:
        Circulo(Punto& pos, float r) : posicion(pos) , radio(r) {}

        float getRadio() const;
        Punto getPosicion() const;
        void setRadio(float nuevoRadio);
        void setPosicion(float nuevaX, float nuevaY);

        ~Circulo() = default;
};