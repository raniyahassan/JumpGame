#ifndef SCREEN
#define SCREEN

#include <iostream>
#include <SFML/Graphics.hpp>

using namespace std;
using namespace sf;

class Screen 
{
    private:
        View m_view;
        float width, height; 
    public:
        Screen(float, float); 
        RectangleShape square(); 
        View getView(); 
        void moveViewUp(); 

};

#endif 