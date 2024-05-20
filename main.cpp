#include <SFML/Graphics.hpp>
#include <iostream>
using namespace std;
using namespace sf;
int main()
{
    RenderWindow window(VideoMode(450, 400), "SFML works!");
    window.setFramerateLimit(60);
    Texture yoshitexture;
    if(!yoshitexture.loadFromFile("Yoshi.png"))
    {
cout << "Error al cargar imagen" << endl;
    }
    yoshitexture.setRepeated(true);

    Sprite yoshi;
    yoshi.setTexture(yoshitexture);
    yoshi.setTextureRect(IntRect(0,0,700,700));
    int opacidad=0;

    while (window.isOpen())
    {
        Event event;
        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed)
                window.close();
        }

        window.clear();
        yoshi.rotate(5);
        window.draw(yoshi);
        yoshi.setColor(Color(rand()%256,rand()%256,rand()%256,255));
        window.display();
        opacidad++;
    }

    return 0;
}