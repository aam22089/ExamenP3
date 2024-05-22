#include <SFML/Graphics.hpp>
#include <iostream>
#include "bolita.hpp"
using namespace std;
using namespace sf;



int main() {
    RenderWindow window(VideoMode(450, 400), "SFML works!");
    window.setFramerateLimit(60);


    while (window.isOpen()) {
        Event event;
        while (window.pollEvent(event)) {
            if (event.type == Event::Closed)
                window.close();
        }


        window.clear();
        window.display();
    }

    return 0;
}
