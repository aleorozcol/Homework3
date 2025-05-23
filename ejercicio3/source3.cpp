#include "header3.hpp"
#include <type_traits>
#include <string> 

// guarda el valor al final del vector datos
template <typename T>
void Procesador<T>::add(const T &valor){
    datos.push_back(valor);
}

// funcion que me ayuda a eliminar los ceros
static string trimManual(string myDouble){
    auto pos = myDouble.find('.');
    // string::npos es la "máxima posicion posible", indica "ninguna posicion válida", esto devuelve .find en caso de no encontrar nada
    if (pos == string::npos) return myDouble; // si no hay punto, no pasa nada 
    myDouble.erase(myDouble.find_last_not_of('0') + 1); // borra ceros al final
    if (!myDouble.empty() && myDouble.back() == '.') myDouble.pop_back(); //si quedo al ultimo un punto, lo borro tambien
    return myDouble;
}

// construye JSON para datos de tipo T
// según el tipo T (double, string o vector de enteros) se procesa de diferente manera
template <typename T>
string Procesador<T>::procesarDatos() const {
    string json = "[";
    for (size_t i = 0; i < datos.size(); ++i){
        if constexpr (is_same_v<T, double>){
            json += trimManual(to_string(datos[i]));
        } else if constexpr (is_same_v<T, string>){
            json += '"'; json += datos[i]; json += '"';
        } else if constexpr (is_same_v<T, vector<int>>){
            json += "[";
            for (size_t j = 0; j < datos[i].size(); ++j) {
                json += to_string(datos[i][j]);
                if (j+1 < datos[i].size()) json += ", ";
            }
            json += "]";
        }
        if (i+1 < datos.size()) json += ", ";
    }
    json += "]";
    return json;
}

// fuerza al compilador a generar código para estas tres instanciaciones
template class Procesador<double>;
template class Procesador<string>;
template class Procesador<vector<int>>;

// guarda un par <key, value> en el vector
void Constructor::addCampo(const string& key, const string& value) {
    campo.emplace_back(key, value);
}

// recorre todos los elementos y los imprime como JSON
void Constructor::construir() const {
    cout << "{\n";
    int cont = 0;
    int n = campo.size();
    for (auto& [k,v] : campo){
        cout << "  \"" << k << "\" : " << v << (++cont < n ? ",\n" : "\n");
    }
    cout << "}\n";
}