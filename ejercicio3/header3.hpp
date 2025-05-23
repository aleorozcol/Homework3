#pragma once

#include <iostream>
#include <vector>

using namespace std;

// esta clase almacena datos de cualquier tipo T y despues los convierte en un string formato JSON
template <typename T>
class Procesador {
    private:
        vector<T> datos; 
    public:
        void add(const T& valor);
        string procesarDatos() const; // recorre los datos y construye la representacion JSON
};

// esta clase asocia una clave con su string ya formateado e imprime el JSON completo
class Constructor {
    private:
        vector<pair<string, string>> campo;
    public:
        void addCampo(const string& key, const string& value);
        void construir() const; 
};