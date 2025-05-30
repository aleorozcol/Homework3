#pragma once

#include <iostream>
#include <vector>

using namespace std;
// esta clase asocia una clave con su string ya formateado e imprime el JSON completo
class Constructor {
    private:
        vector<pair<string, string>> campo;
    public:
        void addCampo(const string& key, const string& value);
        void construir() const; 
};