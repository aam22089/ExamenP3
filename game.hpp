#ifndef GAME_H
#define GAME_H
#include "player.hpp"
#include "barrier.hpp"
#include <cstdlib>
#include <ctime>
#define WALL_COUNT 10
using namespace std;
using namespace sf;


    
class Game
{
public:
    Game();
    virtual ~Game();
    void Gameloop(){while(this->window->isOpen()){this->Update();}}

private:
    sf::RenderWindow* window;
    sf::Event event;
    Player player;
    std::vector<Line> walls;
    vector <Barrier> HitBoxes;

private:
    void Logic();
    void Update();
    void EventUpdate();
    void Draw();
    void moverFantasma();
    void moverZombie();
    bool isMonsterVisible(sf::Sprite monster);
    void drawExteriorWalls();
    void drawInteriorWalls(vector<Barrier>Hitboxes);
    void shoot();
    void updateBullets();
    bool isBulletIntersectLine(const sf::Vector2f& point, const Line& wall);

private:
    float getDistance(float x1,float y1,float x2,float y2);
    sf::Vector2f getIntersectionPoint(float d1x1, float d1y1, float d1x2, float d1y2, float d2x1, float d2y1, float d2x2, float d2y2, bool& isIntersects);
    sf::View view;
    sf::Vector2f camera;

    Texture fantasmaTexture;
    Sprite fantasmaSprite;

    Texture zombieTexture;
    Sprite zombieSprite;

    Texture paredExteriorTexture;
    Sprite paredExteriorSprite;

    const float MOVE_DISTANCE = 5.0f; // Distancia de movimiento del fantasma

    std::vector<sf::RectangleShape> bullets;
    sf::Vector2f bulletDirection;
    vector<sf::Vector2f> bulletDirections;

};

#endif // GAME_H