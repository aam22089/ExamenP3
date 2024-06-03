#ifndef BARRIER_H
#define BARRIER_H
#include "line.hpp"
using namespace std;
using namespace sf;

class Barrier
{
    public:
    
    RectangleShape Hitbox;
    Sprite spared;
    Texture tpared;

    Barrier(float b, float h, int x, int y, String direct);
    
    void addTexture(Texture pared);


};

#endif