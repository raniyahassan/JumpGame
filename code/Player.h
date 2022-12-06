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
        Sprite player; 
    public:
        Player(); 
        Sprite getPlayer(); 
        FloatRect getBounds(); 
        Vector2f getPosition();
        void setPosition(Vector2f newPosition);
};

#endif 