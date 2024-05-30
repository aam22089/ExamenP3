#ifndef BARRIER_H
#define BARRIER_H
#include "line.hpp"
using namespace std;
using namespace sf;

class Barrier
{
    public:
    vector <RectangleShape> HitBoxes;
    RectangleShape Hitbox;

    Barrier(float b, float h, int x, int y);
    
    void addHitBox(RectangleShape hb);


};

#endif