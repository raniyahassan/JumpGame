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
        Guy(Sprite x); 
        Vector2f getPosition();
        void setPosition(Vector2f newPosition);
        Sprite y; 
};

#endif 