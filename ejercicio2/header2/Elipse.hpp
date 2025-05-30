#pragma once

#include "Punto.hpp"

using namespace std;

class Elipse {
    private:
        Punto posicion; // centro
        float semiejeMayor;
        float semiejeMenor;
    public:
        Elipse(Punto& pos, float a, float b) : posicion(pos) , semiejeMayor(a) , semiejeMenor(b) {}
        Punto getPosicion() const;
        float getSemiejeMayor() const;
        float getSemiejeMenor() const;
        void setPosicion(float nuevaX, float nuevaY);
        void setSemiejeMayor(float nuevoSemiejeMayor);
        void setSemiejeMenor(float nuevoSemiejeMenor);

        ~Elipse() = default;
};