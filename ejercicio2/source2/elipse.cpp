#include "../header2/Elipse.hpp"

Punto Elipse::getPosicion() const { return posicion; }
float Elipse::getSemiejeMayor() const { return semiejeMayor; }
float Elipse::getSemiejeMenor() const { return semiejeMenor; }

void Elipse::setPosicion(float nuevaX, float nuevaY) { posicion.setX(nuevaX); posicion.setY(nuevaY); }
void Elipse::setSemiejeMayor(float nuevoSemiejeMayor) { semiejeMayor = nuevoSemiejeMayor; }
void Elipse::setSemiejeMenor(float nuevoSemiejeMenor) { semiejeMenor = nuevoSemiejeMenor; }