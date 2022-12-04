#ifndef GUY
#define GUY

#include <iostream>
#include <SFML/Graphics.hpp>

using namespace std;
using namespace sf;

class Guy 
{
    private:
        float positionX;
        float positionY; 
    public:
        Guy(); 
        Sprite createGuy(); 
        Vector2f getPosition();
        void setPosition(Vector2f newPosition);
};

#endif GUY