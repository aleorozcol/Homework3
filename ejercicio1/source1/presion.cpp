#include "../header1/Presion.hpp"

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