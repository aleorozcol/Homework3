#pragma once

#include "Punto.hpp"

class Rectangulo {
    private:
        Punto posicion; //vertice izquierdo inferior
        float ancho;
        float largo;
    public:
        Rectangulo(Punto& pos, float a, float l) : posicion(pos) , ancho(a) , largo(l) {}
        Punto getPosicion() const;
        float getAncho() const;
        float getLargo() const;
        void setPosicion(float nuevaX, float nuevaY);
        void setAncho(float nuevoAncho);
        void setLargo(float nuevoLargo);
        ~Rectangulo() = default;
};
