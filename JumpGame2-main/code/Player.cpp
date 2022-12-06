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
 
/*   FloatRect Player::getPosition()
       {
           return m_Sprite.getGlobalBounds();
       }
         
*/
      
 
   float Player::getVelocity()
   {
       return m_Speed;
   }
 
 
 
   void Player::setPosition(float X, float Y)
   {
       m_Position.x = X;
       m_Position.y = Y;
   }
 
 
   //dt = clock.restart (after each gamestate changes), float dtAsSec = dt.AsSeconds
   void Player::update(Time dtAsSec)
   {
       if (Keyboard::isKeyPressed(Keyboard::Left))
       {
           m_Position.x -= 4;
       }
 
       if (Keyboard::isKeyPressed(Keyboard::Right))
       {
           m_Position.x += 4;
       }
 
 
       m_Speed += .2;
       m_Height += m_Speed;
       if (m_Height > 500) { m_Speed = -10; }
       setPosition(m_Position.x, m_Height);
   }
 
 
Sprite Player::getPlayer()
{
   return player;
}
 
Vector2f Player::getPosition()
{
   Vector2f currPosition = {m_Position.x , m_Position.y};
   return currPosition;
}
 
FloatRect Player::getBounds()
{
   return player.getLocalBounds();
}
 
void Player::setPosition(Vector2f newPosition)
{
   m_Position.x = newPosition.x;
   m_Position.y = newPosition.y;
}