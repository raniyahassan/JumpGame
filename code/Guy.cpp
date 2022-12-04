#include "Guy.h"
#include <iostream>
#include <SFML/Graphics.hpp>

using namespace std;
using namespace sf; 

Guy::Guy()
{
    positionX = 172;
    positionY = 500; 
}; 

Sprite Guy::createGuy()
{
    Texture playerTexture;
    playerTexture.loadFromFile("images/tempGuy.png");
    Sprite player(playerTexture); 

    return player; 
}

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