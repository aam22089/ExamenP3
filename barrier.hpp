#ifndef BARRIER_H
#define BARRIER_H
#include "line.hpp"
using namespace std;
using namespace sf;

struct hitBox
{
    Line top,down,left,right;
};

class Barrier
{
    public:
    vector<Line>paredes;
    Sprite pinternas;

};

#endif