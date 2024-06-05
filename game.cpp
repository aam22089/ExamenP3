#include "game.hpp"
#include <iostream>

using namespace std;
float distanciaMovimientoFantasma = 2.5f;
float distanciaMovimientoZombie = 3.5f;

int fantasmaHits, zombieHits;


Game::Game()
{
    this->window = new sf::RenderWindow (sf::VideoMode(WIDTH, HEIGHT), "RAY CASTING", sf::Style::Close | sf::Style::Titlebar | sf::Style::Fullscreen);
    this->window->setFramerateLimit(60);
    this->window->setMouseCursorVisible(false); //


    camera.x=window->getSize().x;
    camera.y=window->getSize().y;
    view.setCenter(camera.x/2,camera.y/2);
    view.setViewport(sf::FloatRect(0.f,0.f,0.3f,0.3f));
    view.setViewport(sf::FloatRect(0.f,0.f,1.f,1.f));

Barrier pared1(190,110,0,490);
HitBoxes.push_back(pared1);
Barrier pared2(460,110,470,490);
HitBoxes.push_back(pared2);
Barrier pared3(100,325,930,275);
HitBoxes.push_back(pared3);
Barrier pared4(100,140,930,0);
HitBoxes.push_back(pared4);
Barrier pared5(1080,50,180,870);
HitBoxes.push_back(pared5);
Barrier pared6(55,225,1460,860);
HitBoxes.push_back(pared6);
Barrier pared7(55,430,1460,270);
HitBoxes.push_back(pared7);
Barrier pared8(160,50,1515,270);
HitBoxes.push_back(pared8);
Barrier pared9(130,50,1790,270);
HitBoxes.push_back(pared9);



    for(int i = 0; i < WALL_COUNT; i++)
    {
        Line l;
        walls.push_back(l);
    }
    //pared 1
    walls[0].setPos(0,490,190,490);
    walls[1].setPos(190,490,190,600);
    walls[2].setPos(190,600,0,600);
    //pared 2 y 3
    walls[3].setPos(470,490,930,490);
    walls[4].setPos(930,490,930,275);
    walls[5].setPos(930,275,1030,275);
    walls[6].setPos(1030,275,1030,600);
    walls[7].setPos(1030,600,470,600);
    walls[8].setPos(470,600,470,490);
    //pared 4
    walls[9].setPos(930,0,930,140);
    walls[10].setPos(930,140,1030,140);
    walls[11].setPos(1030,140,1030,0);
    //pared 5
    walls[12].setPos(180,870,1260,870);
    walls[13].setPos(1260,870,1260,920);
    walls[14].setPos(1260,920,180,920);
    walls[15].setPos(180,920,180,870);
    //pared 6
    walls[16].setPos(1460,HEIGHT,1460,860);
    walls[17].setPos(1460,860,1515,860);
    walls[18].setPos(1515,860,1515,HEIGHT);
    //pared 7 y 8
    walls[19].setPos(1460,270,1675,270);
    walls[20].setPos(1675,270,1675,320);
    walls[21].setPos(1675,320,1515,320);
    walls[22].setPos(1515,320,1515,700);
    walls[23].setPos(1515,700,1460,700);
    walls[24].setPos(1460,700,1460,270);
    //pared 9
    walls[25].setPos(WIDTH,270,1790,270);
    walls[26].setPos(1790,270,1790,320);
    walls[27].setPos(1790,320, WIDTH,320);
    //exteriores
    walls[28].setPos(0,HEIGHT,WIDTH,HEIGHT);
    walls[29].setPos(WIDTH,HEIGHT,WIDTH,0);
    walls[30].setPos(0,0,0,HEIGHT);
    walls[31].setPos(WIDTH,0,0,0);

if(!paredesInterioresT.loadFromFile("ParedesInternas.png"))
cout << "Error al cargar la imagen"<< endl;
paredesInterioresS.setTexture(paredesInterioresT);
paredesInterioresS.setTextureRect(IntRect(0,0,1920,1080));
paredesInterioresS.setPosition(0,0);

    if (!fantasmaTexture.loadFromFile("fantasma_1.png"))
    {
        cout << "Error al cargar la imagen" << endl;
    }
    fantasmaSprite.setTexture(fantasmaTexture);
    fantasmaSprite.setTextureRect(IntRect(0, 0, 128, 128));
    fantasmaSprite.setPosition(WIDTH/2, HEIGHT/2);
    
    std::srand(static_cast<unsigned>(std::time(0))); // Numeros aleatorios

    if(!zombieTexture.loadFromFile("Zombie_1.png"))
    {
        cout << "Error al cargar la imagen" << endl;
    }
    zombieSprite.setTexture(zombieTexture);
    zombieSprite.setTextureRect(IntRect(0, 0, 128, 128));
    zombieSprite.setPosition(WIDTH/4, HEIGHT/4);

    if(!paredExteriorTexture.loadFromFile("paredes_externas.png"))
    {
        cout << "Error al cargar la imagen" << endl;
    }
    paredExteriorSprite.setTexture(paredExteriorTexture);
    paredExteriorSprite.setTextureRect(IntRect(0, 0, 1920, 1080));
    //paredExteriorSprite.setPosition(WIDTH/4, HEIGHT/4);
}

Game::~Game()
{
    delete this->window;
}

void Game::EventUpdate()
{
    while(this->window->pollEvent(this->event))
    {
        switch(this->event.type)
        {
            case sf::Event::Closed:
                this->window->close();
                break;
            case sf::Event::KeyPressed:
                if(sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
                    this->window->close();
                break;
                    case sf::Event::MouseButtonPressed:
                    if (this->event.mouseButton.button == sf::Mouse::Left)  
                    shoot();
                break;
            default:
                break;
        }
    }
}

void Game::Draw()
{
    this->window->clear();
    //Draw
    this->window->setView(this->view);
        this->player.show(window);
        for(int j = 0; j<walls.size(); j++)
           { walls[j].show(window);
           walls[j].L[0].color=Color::Black;
           walls[j].L[1].color=Color::Black;}

    drawInteriorWalls();
    drawExteriorWalls();
    
    //Draw
    if(fantasmaHits < 10 && isMonsterVisible(fantasmaSprite))
    {
        cout << "visible"  << endl;
        this->window->draw(fantasmaSprite);
        this->fantasmaSprite.move(.05,.05);
    }
    
    if(zombieHits < 10 && isMonsterVisible(zombieSprite))
    {
        this->window->draw(zombieSprite);
        this->zombieSprite.move(.1,.1);
    }

    for (const auto &bullet : bullets)
    {
        this->window->draw(bullet);
    }

    window->setView(window->getDefaultView());
    this->window->display();
}

void Game::Update()
{
    EventUpdate();


   //UPDATES:
    player.update(window);
    player.move();
    view.setCenter(camera.x/2,camera.y/2);
    view.reset(sf::FloatRect(player.pos.x-camera.x/2,player.pos.y-camera.y/2,camera.x,camera.y));
    Logic();
    moverFantasma();
    moverZombie();
    updateBullets();
    

    //

    Draw();
   // if (getDistance(player.pos.x,player.pos.y,zombieSprite.getPosition().x,zombieSprite.getPosition().y) < 10|| 
//getDistance(player.pos.x,player.pos.y,fantasmaSprite.getPosition().x,fantasmaSprite.getPosition().y)<10)
//{window->draw(gameOver());

//}
    
}



void Game::moverFantasma() //Movimiento aleatorio
{

    sf::Vector2f direccion = player.pos - fantasmaSprite.getPosition(); // Vector que apunta desde el fantasma hacia el jugador

    float magnitud = std::sqrt(direccion.x * direccion.x + direccion.y * direccion.y);
    if (magnitud != 0)
    {
        direccion /= magnitud;
    }

    sf::Vector2f movimiento = direccion * distanciaMovimientoFantasma;

    sf::Vector2f nuevaPosicion = fantasmaSprite.getPosition() + movimiento; // Calcula nueva direccion del fantasma

    if (nuevaPosicion.x > 10 && nuevaPosicion.x + fantasmaSprite.getGlobalBounds().width < WIDTH-10 && // Este if verifica que el fantasma este dentro del mapa
        nuevaPosicion.y > 10 && nuevaPosicion.y + fantasmaSprite.getGlobalBounds().height < HEIGHT-10)
    {
        fantasmaSprite.move(movimiento);
    } else 
    {
        if(nuevaPosicion.y > 10 && nuevaPosicion.y + fantasmaSprite.getLocalBounds().height > HEIGHT-10)
        fantasmaSprite.setPosition(fantasmaSprite.getPosition().x, fantasmaSprite.getPosition().y-12);

        if(nuevaPosicion.x > 10 && nuevaPosicion.x + fantasmaSprite.getLocalBounds().width > WIDTH-10)
        fantasmaSprite.setPosition(fantasmaSprite.getPosition().x-12, fantasmaSprite.getPosition().y);
    }
}

void Game::moverZombie()
{
    sf::Vector2f direccion = player.pos - zombieSprite.getPosition(); // Vector que apunta desde el zombie hacia el jugador

    float magnitud = std::sqrt(direccion.x * direccion.x + direccion.y * direccion.y);
    if (magnitud != 0)
    {
        direccion /= magnitud;
    }

    sf::Vector2f movimiento = direccion * distanciaMovimientoZombie;

    sf::Vector2f nuevaPosicion = zombieSprite.getPosition() + movimiento; // Calcula nueva direccion del zombie
    
    bool isCollide = false;

    for (const auto& hitbox : HitBoxes)
    {
        if (zombieSprite.getGlobalBounds().intersects(hitbox.Hitbox.getGlobalBounds()))
        {
            isCollide = true;
            break;
        }
    }

    if (isCollide)
    {
        // posición central del zombie
        sf::Vector2f centroZombie = zombieSprite.getPosition() + sf::Vector2f(zombieSprite.getLocalBounds().width / 2, zombieSprite.getLocalBounds().height / 2);

        // dirección a la que debe moverse el zombie para rodear la pared
        sf::Vector2f direccionRodear;

        // centro de la pared más cercana
        sf::Vector2f centroPared;
        float distanciaMinima = std::numeric_limits<float>::max();

        for (const auto& hitbox : HitBoxes)
        {
            sf::Vector2f centroActual = hitbox.Hitbox.getPosition() + sf::Vector2f(hitbox.Hitbox.getLocalBounds().width / 2, hitbox.Hitbox.getLocalBounds().height / 2);
            float distancia = getDistance(centroZombie.x, centroZombie.y, centroActual.x, centroActual.y);
            
            if (distancia < distanciaMinima)
            {
                distanciaMinima = distancia;
                centroPared = centroActual;
            }
        }

        // dirección a la que debe moverse el zombie para rodear la pared
        direccionRodear = centroZombie - centroPared;
        direccionRodear /= std::sqrt(direccionRodear.x * direccionRodear.x + direccionRodear.y * direccionRodear.y); // Normalizar

        movimiento = direccionRodear * distanciaMovimientoZombie;
    }

    zombieSprite.move(movimiento);


}

bool Game::isMonsterVisible(sf::Sprite monster)
{
    bool isVisible = false;

    for(int i = 0; i < LINES_COUNT; i++)
    {
        auto p1 = player.lines[i].L[0].position;
        auto p2 = player.lines[i].L[1].position;

        auto M1 = monster.getPosition();
        auto M2 = sf::Vector2f(monster.getPosition().x + monster.getLocalBounds().width, monster.getPosition().y);
        auto M3 = sf::Vector2f(monster.getPosition().x, monster.getPosition().y + monster.getLocalBounds().height);
        auto M4 = sf::Vector2f(monster.getPosition().x + monster.getLocalBounds().width, monster.getPosition().y + monster.getLocalBounds().height);

        bool intersects1, intersects2, intersects3, intersects4;

        sf::Vector2f p;

        p = getIntersectionPoint(p1.x, p1.y, p2.x, p2.y, M1.x, M1.y, M2.x, M2.y, intersects1);
        p = getIntersectionPoint(p1.x, p1.y, p2.x, p2.y, M1.x, M1.y, M3.x, M3.y, intersects2);
        p = getIntersectionPoint(p1.x, p1.y, p2.x, p2.y, M2.x, M2.y, M4.x, M4.y, intersects3);
        p = getIntersectionPoint(p1.x, p1.y, p2.x, p2.y, M3.x, M3.y, M4.x, M4.y, intersects4);

        if(intersects1 || intersects2 || intersects3 || intersects4)
        {
            isVisible = true;
            break;
        }
    }

    return isVisible;
}

void Game::drawExteriorWalls()
{
        paredExteriorSprite.setPosition(0,0);
        this->window->draw(paredExteriorSprite);

}

void Game::drawInteriorWalls()
{
    paredesInterioresS.setPosition(0,0);
    this->window->draw(paredesInterioresS);
}

void Game::shoot()
{
    sf::RectangleShape bullet;
    bullet.setSize(sf::Vector2f(10, 5)); // Tamaño de la bala
    bullet.setFillColor(sf::Color::White); // Color de la bala
    bullet.setPosition(player.pos); // Posición inicial de la bala

    // Obtener la dirección del rayo central
    sf::Vertex centralRayStart = player.lines[LINES_COUNT / 2].L[0];
    sf::Vertex centralRayEnd = player.lines[LINES_COUNT / 2].L[1];

    sf::Vector2f direction = centralRayEnd.position - centralRayStart.position;
    float magnitude = std::sqrt(direction.x * direction.x + direction.y * direction.y);
    if (magnitude != 0)
    {
        direction /= magnitude; // Normalizar la dirección
    }
    bulletDirections.push_back(direction);

    bullets.push_back(bullet);
}

void Game::updateBullets()
{

    
    for (size_t i = 0; i < bullets.size(); ++i)
    {
        Vector2f startPoint = walls[i].getStartPoint();
        Vector2f endPoint = walls[i].getEndPoint();

        bullets[i].move(bulletDirections[i] * 10.0f); // Mover la bala en su dirección

        // Verificar colisión con las paredes delimitantes del mapa
        if (bullets[i].getPosition().x < 0 || bullets[i].getPosition().x > WIDTH ||
            bullets[i].getPosition().y < 0 || bullets[i].getPosition().y > HEIGHT)
        {
            // Eliminar la bala
            bullets.erase(bullets.begin() + i);
            bulletDirections.erase(bulletDirections.begin() + i);
            break; 
        }

        // Eliminar bala si choca con el fantasma
        if (bullets[i].getGlobalBounds().intersects(fantasmaSprite.getGlobalBounds()))
        {
            bullets.erase(bullets.begin() + i);
            bulletDirections.erase(bulletDirections.begin() + i);

            fantasmaHits++;

            if(fantasmaHits >= 10)
            {
                fantasmaHits = 0;
                fantasmaSprite.setPosition(WIDTH/2, HEIGHT/2);
            }
            break;
        }

        // Eliminar bala si choca con el zombie
        if (bullets[i].getGlobalBounds().intersects(zombieSprite.getGlobalBounds()))
        {
            bullets.erase(bullets.begin() + i);
            bulletDirections.erase(bulletDirections.begin() + i);

            zombieHits++;

            if(zombieHits >= 10)
            {
                zombieHits = 0;
                zombieSprite.setPosition(WIDTH/2, HEIGHT/2);
            }
            break;
        }

        // Verificar colisión con las paredes interiores del mapa
        bool bulletErased = false;
        for (const auto& hitbox : HitBoxes)
        {
            if (bullets[i].getGlobalBounds().intersects(hitbox.Hitbox.getGlobalBounds()))
            {
                bullets.erase(bullets.begin() + i);
                bulletDirections.erase(bulletDirections.begin() + i);
                bulletErased = true;
                break;
            }
        }
        
        if (bulletErased) {
            break;
        }
    }
}

Sprite Game::gameOver()
{
    Texture gameovertexture;
    if(!gameovertexture.loadFromFile("gameOver.png.crdownload"))
    cout<<"Error al cargar imager " << endl;
    Sprite gameoversprite;
    gameoversprite.setTexture(gameovertexture);
    gameoversprite.setPosition(0,0);
    gameoversprite.setTextureRect(IntRect(0,0,1920,1080));
 
    window->draw(gameoversprite);
    return gameoversprite;
}

void Game::Logic()
{
    bool in=false;
    for(int j = 0; j<walls.size(); j++)
    {
        for(int i = 0; i<LINES_COUNT; i++)
        {
            auto p1 = player.lines[i].L[0].position;
            auto p2 = player.lines[i].L[1].position;


            auto L1 = walls[j].L[0].position;
            auto L2 = walls[j].L[1].position;

            auto p = getIntersectionPoint(p1.x,p1.y,p2.x,p2.y,L1.x,L1.y,L2.x,L2.y,player.lines[i].isIntersects);
            auto p3= getIntersectionPoint(zombieSprite.getPosition().x, zombieSprite.getPosition().y,zombieSprite.getPosition().x+zombieSprite.getGlobalBounds().width, zombieSprite.getPosition().y,L1.x,L1.y,L2.x,L2.y, in);
            auto p4= getIntersectionPoint(zombieSprite.getPosition().x+zombieSprite.getGlobalBounds().width, zombieSprite.getPosition().y,zombieSprite.getPosition().x+zombieSprite.getGlobalBounds().width, zombieSprite.getPosition().y+zombieSprite.getGlobalBounds().height,L1.x,L1.y,L2.x,L2.y, in);
            auto p5= getIntersectionPoint(zombieSprite.getPosition().x+zombieSprite.getGlobalBounds().width, zombieSprite.getPosition().y+zombieSprite.getGlobalBounds().height,zombieSprite.getPosition().x, zombieSprite.getPosition().y+zombieSprite.getGlobalBounds().height,L1.x,L1.y,L2.x,L2.y, in);
            auto p6= getIntersectionPoint(zombieSprite.getPosition().x, zombieSprite.getPosition().y+zombieSprite.getGlobalBounds().height,zombieSprite.getPosition().x, zombieSprite.getPosition().y,L1.x,L1.y,L2.x,L2.y, in);
            
if(!in)
{
    zombieSprite.move(0,0);
}
            if(this->player.lines[i].isIntersects)
                this->player.lines[i].setPos(this->player.pos.x, this->player.pos.y, p.x, p.y);
            //walls[j].setAlpha(0);

        }
    }
}


float Game::getDistance(float x1,float y1,float x2,float y2)
{
    return sqrt(((x1 - x2)*(x1 - x2)) + ((y1 - y2)*(y1 - y2)));
}

sf::Vector2f Game::getIntersectionPoint(float d1x1, float d1y1, float d1x2, float d1y2, float d2x1, float d2y1, float d2x2, float d2y2, bool& isIntersects)
{
    float m1;
    float m2;
    float X;
    float Y;
    m1 = d1x1 < d1x2 ? (d1y1-d1y2)/(d1x1-d1x2) : (d1y2-d1y1)/(d1x2-d1x1);
    m2 = d2x1 < d2x2 ? (d2y1-d2y2)/(d2x1-d2x2) : (d2y2-d2y1)/(d2x2-d2x1);
    /*
    if(d1x2-d1x1!=0)
        m1 = d1x1 < d1x2 ? (d1y1-d1y2)/(d1x1-d1x2) : (d1y2-d1y1)/(d1x2-d1x1);
    else
        m1=1;

    if(d2x2-d2x1!=0)
        m2 = d2x1 < d2x2 ? (d2y1-d2y2)/(d2x1-d2x2) : (d2y2-d2y1)/(d2x2-d2x1);
    else
        m2=1;

    if(d1y2-d1y1==0)
        m1=0;

    if(d2y2-d2y1==0)
        m2=0;
    */

    if(m1 == std::numeric_limits<float>::infinity() || m1 <=-1.6384e+010)
    {
        X = d1x1;
        Y = m2 * (X - d2x1) + d2y1;
    }
    else if(m2 == std::numeric_limits<float>::infinity() || m2 <=-1.6384e+010)
    {
        X = d2x1;
        Y = m1 * (X - d1x1) + d1y1;
    }
    else
    {
        X = ((m1 * d1x1) - d1y1 - (m2 * d2x1) + d2y1)/(m1-m2);
        Y = m1 * (X - d1x1) + d1y1;
    }






    sf::Vector2f result;
    result.x=X;
    result.y=Y;


    //if(m2==std::numeric_limits<float>::infinity()||m2==std::numeric_limits<double>::quiet_NaN())
      //std::cout<<"Merhaba"<<std::endl;
      //  return result;
    //if(m1==std::numeric_limits<float>::infinity()||m1==std::numeric_limits<double>::quiet_NaN())
      //std::cout<<"Merhaba"<<std::endl;
      //  return result;

    float d1 = getDistance(d1x1, d1y1, d1x2, d1y2);
    float d2 = getDistance(d2x1, d2y1, d2x2, d2y2);

    sf::Vector2f far1;
    sf::Vector2f far2;
///////////////
    if(getDistance(d1x1, d1y1, result.x, result.y) > getDistance(d1x2, d1y2, result.x, result.y))
    {
        far1.x = d1x1;
        far1.y = d1y1;
    }
    else
    {
        far1.x = d1x2;
        far1.y = d1y2;
    }
///.////////////
    if(getDistance(d2x1, d2y1, result.x, result.y) > getDistance(d2x2, d2y2, result.x, result.y))
    {
        far2.x = d2x1;
        far2.y = d2y1;
    }
    else
    {
        far2.x = d2x2;
        far2.y = d2y2;
    }
///////////////
    //std::cout <<"m1: "<<m1<<"   m2: "<<m2<<"   X: "<<X<<"   Y: "<<Y<<"   isIntersection: "<<isIntersects<<" d2: "<<d2<<" bla: "<<getDistance(far2.x, far2.y, result.x, result.y)<<std::endl;
    if(getDistance(far1.x, far1.y, result.x, result.y)<=d1&&getDistance(far2.x, far2.y, result.x, result.y)<=d2)
        isIntersects = true;
    else
        isIntersects = false;

    if(isIntersects)
        return result;
    else
        return sf::Vector2f(0,0);





}
















