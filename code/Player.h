#pragma once
#include <SFML/Graphics.hpp>
using namespace sf;
class Player
{
private:
   Vector2f m_Position;
   Sprite player;    
   float m_Speed;
   int m_Height;
 
public:
   Player();
   Sprite getPlayer();
   FloatRect getBounds();
   Vector2f getPosition();
   void setPosition(Vector2f newPosition);
   void moveLeft();
   void moveRight();
   void stopLeft();
   void stopRight();
   float getVelocity();
 
   void update(Time dt);
   void setPosition(float X, float Y);
};