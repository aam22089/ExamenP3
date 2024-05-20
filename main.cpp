#include <SFML/Graphics.hpp>
#include <iostream>
#include "bolita.hpp"
using namespace std;
using namespace sf;



int main() {
    RenderWindow window(VideoMode(450, 400), "SFML works!");
    window.setFramerateLimit(60);

    Bolita bolita(200.f, 200.f, 2.f);
    CircleShape shape(10.f);
    shape.setFillColor(Color::Red);

    while (window.isOpen()) {
        Event event;
        while (window.pollEvent(event)) {
            if (event.type == Event::Closed)
                window.close();
        }

        if (Keyboard::isKeyPressed(Keyboard::Left))
            bolita.mover(-1.f, 0.f);
        if (Keyboard::isKeyPressed(Keyboard::Right))
            bolita.mover(1.f, 0.f);
        if (Keyboard::isKeyPressed(Keyboard::Up))
            bolita.mover(0.f, -1.f);
        if (Keyboard::isKeyPressed(Keyboard::Down))
            bolita.mover(0.f, 1.f);

        shape.setPosition(bolita.getX(), bolita.getY());

        window.clear();
        window.draw(shape);
        window.display();
    }

    return 0;
}
