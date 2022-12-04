#include "Guy.h"
#include <iostream>
#include <SFML/Graphics.hpp>

using namespace std;
using namespace sf; 

Guy::Guy(Sprite x)
{
    Sprite y = x; 
    positionX = 172;
    positionY = 650; 
}; 

Vector2f Guy::getPosition()
{
    Vector2f currPosition = {positionX , positionY};

    return currPosition;
}

void Guy::setPosition(Vector2f newPosition)
{
    positionX = newPosition.x;
    positionY = newPosition.y;
}
