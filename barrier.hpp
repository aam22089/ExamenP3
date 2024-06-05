#ifndef BARRIER_H
#define BARRIER_H
#include "line.hpp"
using namespace std;
using namespace sf;

class Barrier
{
    public:
    
    RectangleShape Hitbox;
    bool isIntersect(Sprite s, Vector2f);

    Barrier(float b, float h, int x, int y);


};

#endif