#include <SFML/Graphics.hpp>
#include <iostream>
#include "game.hpp"
using namespace std;
using namespace sf;

void menu(Text &Play, Text &Exit, Font font)
{

    Play.setFont(font);
    Exit.setFont(font);
    Play.setString("Play");
    Exit.setString("Exit");
    Play.setFillColor(Color::White);
    Exit.setFillColor(Color::White);
}
int main()
{
   /* Font font;
    if (!font.loadFromFile("alagard.ttf"))
        cout << "Error";
    Text Play;
    Text Exit;*/
    RenderWindow window(VideoMode(450, 400), "SFML works!");
    window.setFramerateLimit(60);

    while (window.isOpen())
    {
        Event event;
        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed)
                window.close();

            Game game;
            game.Gameloop();

          /**  menu(Play, Exit, font);
            if (event.type == Event::KeyPressed)
            {
                if (Event::KeyPressed == Keyboard::W)
                {
                    Play.setOutlineColor(Color::Green);
                    Exit.setOutlineColor(Color::Black);
                    if (Event::KeyPressed == Keyboard::Enter)
                        game.Gameloop();
                }

                if (Event::KeyPressed == Keyboard::S)
                {
                    Play.setOutlineColor(Color::Black);
                    Exit.setOutlineColor(Color::Green);
                    if (Event::KeyPressed == Keyboard::Enter)
                        window.close();
                }
            } */

            return 0;
        }

        window.clear();
        // window.draw(fantasma);
        window.display();
    }

    return 0;
}
