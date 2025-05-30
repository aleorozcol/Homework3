#include "../header3/Constructor.hpp"

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