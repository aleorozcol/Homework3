#include "header3.hpp"
#include <type_traits>
#include <sstream>

template <typename T>
void Procesador<T>::add(const T &valor){
    datos.push_back(valor);
}

template <typename T>
string Procesador<T>::procesarDatos() const {
    ostringstream oss;
    oss << "[";
    for (size_t i = 0; i < datos.size(); ++i){
        if constexpr (is_same_v<T, double>){
            oss << datos[i];
        } else if constexpr (is_same_v<T, string>){
            oss << '"' << datos[i] << '"';
        } else if constexpr (is_same_v<T, vector<int>>){
            oss << "[";
            for (size_t j = 0; j < datos[i].size(); ++j) {
                oss << datos[i][j];
                if (j+1 < datos[i].size()) oss << ",";
            }
            oss << "]";
        }
        if (i+1 < datos.size()) oss << ",";
    }
    oss << "]";
    return oss.str();
}

template class Procesador<double>;
template class Procesador<string>;
template class Procesador<vector<int>>;

void Constructor::addCampo(const string& key, const string& value) {
    campo.emplace_back(key, value);
}

void Constructor::construir() const {
    cout << "{\n";
    int cont = 0;
    int n = campo.size();
    for (auto& [k,v] : campo){
        cout << "  \"" << k << "\" : " << v << (++cont < n ? ",\n" : "\n");
    }
    cout << "}\n";
}