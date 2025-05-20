#pragma once

#include <iostream>
#include <fstream>
#include <memory>

using namespace std;

class IMediciones {
    public:
        virtual void serializar(ofstream& out) const = 0;
        virtual void deserializar(ifstream& in) = 0;
        virtual ~IMediciones() = default;
};

class MedicionBase : public IMediciones {
    protected:
        unique_ptr<float> tiempoMedicion;
    public:
        MedicionBase(float t) : tiempoMedicion(make_unique<float>(t)) {}
        // como no se puede usar move, hacemos deep copy
        MedicionBase(const MedicionBase& other){ // constructor de copia
            if (other.tiempoMedicion) {
                tiempoMedicion = make_unique<float>(*other.tiempoMedicion);
            }
        } 
        // creamos un nuevo unique_ptr, copiamos el valor del tiempo y así hacemos deep copy de los objetos sin usar move
        virtual void serializar(ofstream& out) const override;
        virtual void deserializar(ifstream& in) override;
        float getTiempo() const;
        virtual void imprimir() const = 0;
        virtual ~MedicionBase() = default;
};

class Presion : public MedicionBase {
    public:
        float presionEstatica;
        float presionDinamica;

        Presion(float p, float q, float t)
                : MedicionBase(t) , presionEstatica(p), presionDinamica(q) {}

        Presion(const Presion &other)
                : MedicionBase(other) , presionEstatica(other.presionEstatica) , presionDinamica(other.presionDinamica) {} 

        void serializar(ofstream &out) const override;
        void deserializar(ifstream &in) override;
        void imprimir() const override;

        ~Presion() = default;
};

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