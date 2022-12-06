#include "Screen.h"
#include <SFML/Graphics.hpp>
#include <iostream>

using namespace std;
using namespace sf;

Screen::Screen(float winWidth, float winHeight)
{
    width = winWidth;
    height = winHeight; 
    m_view.setSize(winWidth, winHeight);
    m_view.setCenter(0.0, 0.0);
}

RectangleShape Screen::square()
{ 
    RectangleShape blk(Vector2f{686 , 966}); 
    blk.setFillColor(Color(0,0,0,100)); 
    return blk; 
}

View Screen::getView()
{
    return m_view; 
}

void Screen::moveViewup()
{
    double x = width; 
    double y = height + 300;
    m_view.setSize(x, y); 
}

/*void Screen::startView()
{

}*/