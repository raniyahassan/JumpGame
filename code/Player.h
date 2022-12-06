#ifndef PLAYER
#define PLAYER

#include <iostream>
#include <SFML/Graphics.hpp>

using namespace std;
using namespace sf;

class Player 
{
    private:
        float positionX;
        float positionY; 
    public:
        Player(Sprite x); 
        Vector2f getPosition();
        void setPosition(Vector2f newPosition);
        Sprite y; 
};

#endif 