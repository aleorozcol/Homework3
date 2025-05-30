#pragma once

#include "Posicion.hpp"
#include "Presion.hpp"

using namespace std;

class SaveFlightData {
    public:
        Posicion posicion;
        Presion presion;

        SaveFlightData(const Posicion& p, const Presion& q) : posicion(p) , presion(q) {}

        void serializar(ofstream &out) const;
        void deserializar(ifstream &in);
        void imprimir() const;

        ~SaveFlightData() = default;
};