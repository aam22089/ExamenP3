#include "bolita.hpp"

void Bolita::mover(float dx, float dy)
{
    this->x += dx * this->velocidad;
    this->y += dy * this->velocidad;
}

float Bolita::getX()
{
    return this->x;
}

float Bolita::getY()
{
    return this->y;
}


