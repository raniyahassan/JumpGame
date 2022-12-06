#include "Platform.h"
#include "time.h"
#include <iostream>
#include <SFML/Graphics.hpp>

using namespace std;
using namespace sf;

Platform::Platform()
{

}

Sprite Platform::returnPlat()
{
    return platform; 
}

FloatRect Platform::getBounds()
{
    return platform.getGlobalBounds();
}

Vector2f Platform::getPosition()
{
    return platform.getPosition(); 
}

vector<Sprite> Platform::generator()
{
    srand(time(0));
    Texture texture;
    texture.loadFromFile("images/bar.png");
    vector<Sprite> x(20); 
    for (int i = 0; i < x.size(); i++)
    {
        x[i].setTexture(texture);
        x[i].setPosition(70 + (rand() % 510), 70 + (rand() % 650));
    }

    return x; 
}
