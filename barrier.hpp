#ifndef BARRIER_H
#define BARRIER_H
#include "line.hpp"
using namespace std;
using namespace sf;

class Barrier
{
    public:
    RectangleShape Hitbox;

    Barrier(int b, int h);
    
    void addHitBox(RectangleShape hb);


};

#endif