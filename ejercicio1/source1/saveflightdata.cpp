#include "../header1/SaveFlightData.hpp"

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