#include "../header2/Circulo.hpp"

float Circulo::getRadio() const { return radio; }
Punto Circulo::getPosicion() const { return posicion; }

void Circulo::setRadio(float nuevoRadio) { radio = nuevoRadio; }
void Circulo::setPosicion(float nuevaX, float nuevaY) { posicion.setX(nuevaX); posicion.setY(nuevaY); }
