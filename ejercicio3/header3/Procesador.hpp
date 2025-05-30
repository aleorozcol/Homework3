#pragma once

#include <iostream>
#include <sstream>
#include <type_traits>
#include <vector>

using namespace std;

// esta clase almacena datos de cualquier tipo T y despues los convierte en un string formato JSON
template <typename T>
class Procesador {
    private:
        vector<T> datos; 
    public:
        // guarda el valor al final del vector datos
        void add(const T& valor) {
            datos.push_back(valor);
        }
        // construye JSON para datos de tipo T
        // según el tipo T (double, string o vector de enteros) se procesa de diferente manera
        string procesarDatos() const {
            ostringstream oss;
            oss << "[";
            for (size_t i = 0; i < datos.size(); ++i) {
                if constexpr (is_same_v<T, double>) {
                    oss << datos[i];
                    if (i + 1 < datos.size()) oss << ", ";
                } else if constexpr (is_same_v<T, string>) {
                    oss << '"' << datos[i] << '"';
                    if (i + 1 < datos.size()) oss << ", ";
                } else if constexpr (is_same_v<T, vector<int>>) {
                    oss << "\n\t[";
                    for (size_t j = 0; j < datos[i].size(); ++j) {
                        oss << datos[i][j];
                        if (j + 1 < datos[i].size()) oss << ", ";
                    }
                    oss << "]";
                    if (i + 1 < datos.size()){
                        oss << ", ";
                    } else {
                        oss << "\n\t";
                    }
                }
            }
            oss << "]";
            return oss.str();
        } // recorre los datos y construye la representacion JSON
};