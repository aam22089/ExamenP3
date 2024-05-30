#include "barrier.hpp"

Barrier::Barrier(float b, float h, int x, int y)
{
   
    this->Hitbox.setSize(Vector2f(b,h));
    this->addHitBox(Hitbox);
    this->Hitbox.setPosition(x,y);
}

void Barrier::addHitBox(RectangleShape hb)
{
    this->HitBoxes.push_back(hb);
}
