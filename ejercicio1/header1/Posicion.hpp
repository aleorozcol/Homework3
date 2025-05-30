#pragma once

#include "MedicionBase.hpp"

using namespace std;

class Posicion : public MedicionBase {
    public:
        float latitud;
        float longitud;
        float altitud;

        Posicion(float lat, float lon, float alt, float t) 
                : MedicionBase(t) , latitud(lat) , longitud(lon) , altitud(alt) {}
        
        Posicion(const Posicion& other)
                : MedicionBase(other) , latitud(other.latitud) , longitud(other.longitud) , altitud(other.altitud) {}

        void serializar(ofstream &out) const override;
        void deserializar(ifstream &in) override;
        void imprimir() const override;

        ~Posicion() = default;
};