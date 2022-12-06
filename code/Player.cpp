#include "Player.h"
#include <iostream>
#include <SFML/Graphics.hpp>

using namespace std;
using namespace sf; 

Player::Player()
{
    Texture texture;
    texture.loadFromFile("images/tempGuy.png");
    Sprite p(texture); 
    p.setScale(0.1, 0.1); 
    p.setPosition(270, 650); 
    player = p; 
}; 

Sprite Player::getPlayer()
{
    return player;
}

Vector2f Player::getPosition()
{
    return m_Position;
}

FloatRect Player::getBounds()
{
    return player.getLocalBounds(); 
}

void Player::setPosition(Vector2f newPosition)
{
    m_Position = newPosition;
}
