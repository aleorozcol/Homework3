#pragma once

#include <iostream>

using namespace std;

class Punto {
    private:
        float x;
        float y;
    public:
        Punto(float x, float y) : x(x) , y(y) {}

        float getX() const;
        float getY() const;
        void setX(float nuevaX);
        void setY(float nuevaY);

        ~Punto() = default;
};
