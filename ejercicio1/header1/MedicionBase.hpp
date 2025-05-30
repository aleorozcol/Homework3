#pragma once

#include <memory>
#include "IMediciones.hpp"

using namespace std;

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