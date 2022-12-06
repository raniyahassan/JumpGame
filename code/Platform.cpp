#include "Platform.h"
#include <SFML/Graphics.hpp>
#include <iostream>

using namespace std;
using namespace sf;

Sprite Platform::PlatformMaking()
{
    Texture normalPlat; 
    normalPlat.loadFromFile("images/bar.png"); 
    Sprite x; 
    x.setTexture(normalPlat); 

    return x; 
}

vector<Sprite>* Platform::Platforms()
{
    vector<Sprite> *source; 
    for (int i = 0; i < 20; i++)
    {
        source->push_back(PlatformMaking()); 
    }

    return source; 
}

void Platform::Positioner(vector<Sprite> &x)
{
    for (int i = 0; i < x.size(); i++)
    {
        Vector2f currentPosition = x[i].getPosition(); 
        currentPosition.x= 50 + (i*3); //rand()%600;
        currentPosition.y= 100 + (i*4); //rand()%600;
        x[i].setPosition(currentPosition); 
    }
}

vector<Sprite>* Platform::NormalPlatforms()
{
    vector<Sprite> *x = Platforms(); 
    Positioner(*x); 

    return x; 
}