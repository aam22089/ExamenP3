#include "barrier.hpp"

Barrier::Barrier(float b, float h, int x, int y, String direct)
{
   this->tpared.loadFromFile(direct);
   this->spared.setTexture(tpared);
    this->Hitbox.setSize(Vector2f(b,h));
    this->Hitbox.setPosition(x,y);
}

