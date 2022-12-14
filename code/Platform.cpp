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
    
    vector<Sprite> x(20); 
    for (int i = 0; i < x.size(); i++)
    {
        Texture texture;
        texture.loadFromFile("images/bar.png");
        x[i].setTexture(texture);
        x[i].setPosition(70 + (rand() % 510), 70 + (rand() % 650));
    }

    return x; 
}

