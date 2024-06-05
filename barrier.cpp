#include "barrier.hpp"

bool Barrier::isIntersect(Sprite s, Vector2f nuevaPosicion)
{
    bool downright=true, upleft=true;
if( nuevaPosicion.x>this->Hitbox.getPosition().x+this->Hitbox.getGlobalBounds().width && nuevaPosicion.y>this->Hitbox.getPosition().y + this->Hitbox.getGlobalBounds().height )
{
downright=false;
}
if( nuevaPosicion.y + s.getGlobalBounds().height<this->Hitbox.getPosition().y  && nuevaPosicion.x + s.getGlobalBounds().width<this->Hitbox.getPosition().x)
{
upleft=false;
}
if (upleft && downright)
{return true;}
else{return false;}

} 

Barrier::Barrier(float b, float h, int x, int y)
{
    this->Hitbox.setSize(Vector2f(b,h));
    this->Hitbox.setPosition(x,y);
}

