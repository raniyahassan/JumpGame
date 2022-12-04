#include "Screen.h"
#include <SFML/Graphics.hpp>
#include <iostream>

using namespace std;
using namespace sf;

Screen::Screen()
{
    int x; 
}

RectangleShape Screen::square(double width, double height)
{
    RectangleShape blk(Vector2f{width , height}); 
    blk.setFillColor(Color(0,0,0,100)); 

    return blk; 
}