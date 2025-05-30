#include "../header2/Rectangulo.hpp"

Punto Rectangulo::getPosicion() const { return posicion; }
float Rectangulo::getAncho() const { return ancho; }
float Rectangulo::getLargo() const { return largo; }

void Rectangulo::setPosicion(float nuevaX, float nuevaY) { posicion.setX(nuevaX); posicion.setY(nuevaY); }
void Rectangulo::setAncho(float nuevoAncho) { ancho = nuevoAncho; }
void Rectangulo::setLargo(float nuevoLargo) { largo = nuevoLargo; }