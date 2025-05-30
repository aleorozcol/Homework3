#include "../header1/IMediciones.hpp"
#include "../header1/MedicionBase.hpp"
#include "../header1/Posicion.hpp"
#include "../header1/Presion.hpp"
#include "../header1/SaveFlightData.hpp"

int main() {
    Posicion posicion(-34.6f, -58.4f, 950.0f, 5.3f);
    Presion presion(101.3f, 5.8f, 6.1f);

    cout << "Datos dados: " << endl;
    cout << "-Posición: " << endl;
    posicion.imprimir();
    cout << "-Presión: " << endl;
    presion.imprimir();
    cout << endl;

    SaveFlightData datosVuelo(posicion, presion);

    cout << "Serializando datos en el archivo. " << endl;
    ofstream outFile("datosVuelo.bin", ios::binary);
    if (outFile.is_open()) {
        datosVuelo.serializar(outFile);
        outFile.close();
        cout << "Datos guardados correctamente. " << endl;
    } else {
        cerr << "Error: no se pudo abrir el archivo. " << endl;
        return 1;
    }

    Posicion nuevaPos(0.0f, 0.0f, 0.0f, 0.0f);
    Presion nuevaPres(0.0f, 0.0f, 0.0f);
    SaveFlightData nuevosDatos(nuevaPos, nuevaPres);
    
    cout << "Deserializando datos desde el archivo. " << endl;
    ifstream inFile("datosVuelo.bin", ios::binary);
    if (inFile.is_open()) {
        nuevosDatos.deserializar(inFile);
        inFile.close();
        cout << "Datos cargados correctamente." << endl;
    } else {
        cerr << "Error: no se pudo abrir el archivo. " << endl;
        return 1;
    }

    cout << endl;
    cout << "Datos recuperados: " << endl;
    nuevosDatos.imprimir();

    return 0;
}