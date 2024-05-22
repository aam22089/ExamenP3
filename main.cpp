#include <SFML/Graphics.hpp>
#include <iostream>
#include "game.hpp"
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

                Game game;
                game.Gameloop();
                return 0;
        }


        window.clear();
        //window.draw(fantasma);
        window.display();
    }

    return 0;
}
