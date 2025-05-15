#pragma once

#include <iostream>
#include <cmath>

using namespace std;

class Punto {
    private:
        float x;
        float y;
    public:
        Punto(float x, float y) : x(x) , y(y) {}

        float getX() const;
        float getY() const;
        void setX(float nuevaX);
        void setY(float nuevaY);

        ~Punto() = default;
};

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
