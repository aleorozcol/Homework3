#include "header3.hpp"

int main() {
    Procesador<double> vecDoubles;
    vecDoubles.add(1.3);
    vecDoubles.add(2.1);
    vecDoubles.add(3.2);

    Procesador<string> vecStrings;
    vecStrings.add("Hola");
    vecStrings.add("Mundo");

    Procesador<vector<int>> vecListas;
    vecListas.add({1,2});
    vecListas.add({3,4});

    Constructor constructor;
    constructor.addCampo("vec_doubles", vecDoubles.procesarDatos());
    constructor.addCampo("palabras", vecStrings.procesarDatos());
    constructor.addCampo("listas", vecListas.procesarDatos());
    constructor.construir();

    return 0;
}