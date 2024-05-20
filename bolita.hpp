#ifndef bolita_hpp
#define bolita_hpp

class Bolita {
private:
    float x, y;
    float velocidad;

public:
    Bolita(float x, float y, float velocidad) : x(x), y(y), velocidad(velocidad) {}

    void mover(float dx, float dy);
    void movimiento();
    
    float getX(); 
    float getY();
    
};

#endif