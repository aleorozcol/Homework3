#pragma once

#include <cmath>
#include "Circulo.hpp"
#include "Elipse.hpp"
#include "Rectangulo.hpp"

using namespace std;

//Template generico
template <typename T>
class ProcesadorFigura{
    public:
        static float calcularArea(const T& figura){
            cerr << "No se puede calcular el area de esta figura. " << endl;
            return 0.0f;
        }
};

//Template especializado para círculo
template<>
class ProcesadorFigura<Circulo> {
    public:
        static float calcularArea(const Circulo& circulo){
            return M_PI * circulo.getRadio() * circulo.getRadio();
        }
};

//Template especializado para elipse
template<>
class ProcesadorFigura<Elipse> {
    public:
        static float calcularArea(const Elipse& elipse){
            return M_PI * elipse.getSemiejeMayor() * elipse.getSemiejeMenor();
        }
};

//Template especializado para rectangulo
template<>
class ProcesadorFigura<Rectangulo> {
    public:
        static float calcularArea(const Rectangulo& rectangulo){
            return rectangulo.getAncho() * rectangulo.getLargo();
        }
};
