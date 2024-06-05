#include "barrier.hpp"

Barrier::Barrier(float b, float h, int x, int y)
{
    this->Hitbox.setSize(Vector2f(b,h));
    this->Hitbox.setPosition(x,y);
}

