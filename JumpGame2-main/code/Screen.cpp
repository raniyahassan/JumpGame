#include "Screen.h"
#include <SFML/Graphics.hpp>
#include <iostream>

using namespace std;
using namespace sf;

Screen::Screen(RenderWindow& win)
{
    m_view = win.getDefaultView();  
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

void Screen::moveViewUp()
{
    Vector2f curr = m_view.getCenter(); 
    curr.y +=200; 
    m_view.setCenter(curr);
}
