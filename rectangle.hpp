#ifndef rectangle_h
#define rectangle_h

#include <SFML/Graphics.hpp>
using namespace sf;

class Rectangle{
private:
    Vector2f speed;
    Vector2f objective;
    RectangleShape shape;

public:
    Rectangle(Vector2f size);
    Rectangle(Vector2f size, Vector2i position);

    void update();
    void setObjective(Vector2f objective);
    void drawTo(RenderWindow &window);
    void setPosition(sf::Vector2f pos);
};

#endif

