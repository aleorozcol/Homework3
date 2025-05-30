#include "../header2/Circulo.hpp"
#include "../header2/Elipse.hpp"
#include "../header2/ProcesadorFigura.hpp"
#include "../header2/Punto.hpp"
#include "../header2/Rectangulo.hpp"

int main() {
    Punto centro1(0.0f, 0.0f);
    Punto centro2(1.0f, 1.0f);
    Punto esquina(2.0f, 2.0f);

    Circulo circulo(centro1, 5.0f);
    Elipse elipse(centro2, 4.0f, 2.0f);
    Rectangulo rectangulo(esquina, 3.0f, 6.0f);

    float areaCirculo = ProcesadorFigura<Circulo>::calcularArea(circulo);
    float areaElipse = ProcesadorFigura<Elipse>::calcularArea(elipse);
    float areaRectangulo = ProcesadorFigura<Rectangulo>::calcularArea(rectangulo);

    cout << "Cálculo de Áreas: " << endl;
    cout << "Círculo (radio = " << circulo.getRadio() << ")" << endl;
    cout << "Área: " << areaCirculo << endl;

    cout << "Elipse (a = " << elipse.getSemiejeMayor() << ", b = " << elipse.getSemiejeMenor() << ")" << endl;
    cout << "Área: " << areaElipse << endl;

    cout << "Rectángulo (ancho = " << rectangulo.getAncho() << ", largo = " << rectangulo.getLargo() << ")" << endl;
    cout << "Área: " << areaRectangulo << endl;

    Punto puntoRandom(5.0f, 5.0f);
    cout << "Punto (x = " << puntoRandom.getX() << ", y = " << puntoRandom.getY() << ")" << endl;
    float areaPunto = ProcesadorFigura<Punto>::calcularArea(puntoRandom);
    cout << "Área: " << areaPunto << endl;

    return 0;
}