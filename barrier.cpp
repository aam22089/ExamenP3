#include "barrier.hpp"

Barrier::Barrier(float b, float h, int x, int y, String direct)
{
   if(!this->tpared.loadFromFile(direct))
   cout << "Error" << endl;
   
   this->spared.setTexture(tpared);
    this->Hitbox.setSize(Vector2f(b,h));
    this->Hitbox.setPosition(x,y);
}

