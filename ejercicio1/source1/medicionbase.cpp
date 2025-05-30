#include "../header1/MedicionBase.hpp"

float MedicionBase::getTiempo() const {
    if (tiempoMedicion){
        return *tiempoMedicion; // devuelve float
    }
    return 0.0f; // en caso de que sea nullptr
}

void MedicionBase::serializar(ofstream& out) const {
    float tiempo = tiempoMedicion ? *tiempoMedicion : 0.0f; 
    out.write(reinterpret_cast<char*>(&tiempo), sizeof(float));
} //guardamos el tiempo de medicion en un archivo

void MedicionBase::deserializar(ifstream& in) {
    float tiempo; // para almacenar el tiempo
    in.read(reinterpret_cast<char*>(&tiempo), sizeof(float));
    tiempoMedicion = make_unique<float>(tiempo);
} //recuperamos el tiempo de medicion desde un archivo