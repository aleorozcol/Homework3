#include "header1.hpp"

//Medicion Base

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

// Presion

void Presion::serializar(ofstream& out) const {
    MedicionBase::serializar(out);
    out.write(reinterpret_cast<const char*>(&presionEstatica), sizeof(float));
    out.write(reinterpret_cast<const char*>(&presionDinamica), sizeof(float));
}

void Presion::deserializar(ifstream& in) {
    MedicionBase::deserializar(in);
    in.read(reinterpret_cast<char*>(&presionEstatica), sizeof(float));
    in.read(reinterpret_cast<char*>(&presionDinamica), sizeof(float));
}

void Presion::imprimir() const{
    cout << "Presion estática: " << presionEstatica << endl;
    cout << "Presion dinámica: " << presionDinamica << endl;
    cout << "Tiempo de medición: " << getTiempo() << endl;
}

// Posicion

void Posicion::serializar(ofstream& out) const {
    MedicionBase::serializar(out);
    out.write(reinterpret_cast<const char*>(&latitud), sizeof(float));
    out.write(reinterpret_cast<const char*>(&longitud), sizeof(float));
    out.write(reinterpret_cast<const char *>(&altitud), sizeof(float));
}

void Posicion::deserializar(ifstream& in) {
    MedicionBase::deserializar(in);
    in.read(reinterpret_cast<char*>(&latitud), sizeof(float));
    in.read(reinterpret_cast<char*>(&longitud), sizeof(float));
    in.read(reinterpret_cast<char *>(&altitud), sizeof(float));
}

void Posicion::imprimir() const{
    cout << "Latitud: " << latitud << endl;
    cout << "Longitud: " << longitud << endl;
    cout << "Altitud: " << altitud << endl;
    cout << "Tiempo de medición: " << getTiempo() << endl;
}

// Save Flight Data

void SaveFlightData::serializar(ofstream& out) const {
    posicion.serializar(out);
    presion.serializar(out);
}

void SaveFlightData::deserializar(ifstream& in) {
    posicion.deserializar(in);
    presion.deserializar(in);
}

void SaveFlightData::imprimir() const{
    cout << "Datos del vuelo: " << endl;
    cout << "-Posición: " << endl;
    posicion.imprimir();
    cout << "-Presión: " << endl;
    presion.imprimir();
}