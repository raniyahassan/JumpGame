#ifndef PLAYER
#define PLAYER

#include <iostream>
#include <SFML/Graphics.hpp>

using namespace std;
using namespace sf;

class Player 
{
    private:
        Vector2f m_Position; 
        Sprite player; 
        bool m_LeftPressed;
        bool m_RightPressed;
        float m_Speed;
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
        void getVelocity();
        void bouncePlat();
        void update(Time dt);
        
};

#endif
/*
private:
    Texture m_Texture;
    

public:
    Player(float startX, float startY);
    FloatRect getPosition();
    Vector2f getCenter();
    Sprite getSprite();
    


};*/
