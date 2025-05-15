#include "header2.hpp"

// Punto

float Punto::getX() const { return x; }
float Punto::getY() const { return y; }

void Punto::setX(float nuevaX) { x = nuevaX; }
void Punto::setY(float nuevaY) { y = nuevaY; }

//Circulo

float Circulo::getRadio() const { return radio; }
Punto Circulo::getPosicion() const { return posicion; }

void Circulo::setRadio(float nuevoRadio) { radio = nuevoRadio; }
void Circulo::setPosicion(float nuevaX, float nuevaY) { posicion.setX(nuevaX); posicion.setY(nuevaY); }

//Elipse

Punto Elipse::getPosicion() const { return posicion; }
float Elipse::getSemiejeMayor() const { return semiejeMayor; }
float Elipse::getSemiejeMenor() const { return semiejeMenor; }

void Elipse::setPosicion(float nuevaX, float nuevaY) { posicion.setX(nuevaX); posicion.setY(nuevaY); }
void Elipse::setSemiejeMayor(float nuevoSemiejeMayor) { semiejeMayor = nuevoSemiejeMayor; }
void Elipse::setSemiejeMenor(float nuevoSemiejeMenor) { semiejeMenor = nuevoSemiejeMenor; }

//Rectangulo

Punto Rectangulo::getPosicion() const { return posicion; }
float Rectangulo::getAncho() const { return ancho; }
float Rectangulo::getLargo() const { return largo; }

void Rectangulo::setPosicion(float nuevaX, float nuevaY) { posicion.setX(nuevaX); posicion.setY(nuevaY); }
void Rectangulo::setAncho(float nuevoAncho) { ancho = nuevoAncho; }
void Rectangulo::setLargo(float nuevoLargo) { largo = nuevoLargo; }
