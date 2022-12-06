#include "Player.h"
#include <iostream>
#include <SFML/Graphics.hpp>

using namespace std;
using namespace sf; 

Player::Player(Sprite x)
{
    Sprite y = x; 
    positionX = 270;
    positionY = 650; 
}; 

Vector2f Player::getPosition()
{
    Vector2f currPosition = {positionX , positionY};

    return currPosition;
}

void Player::setPosition(Vector2f newPosition)
{
    positionX = newPosition.x;
    positionY = newPosition.y;
}
