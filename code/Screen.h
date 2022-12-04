#ifndef SCREEN
#define SCREEN

#include <iostream>
#include <SFML/Graphics.hpp>

using namespace std;
using namespace sf;

class Screen 
{
    private:
        int x;
    public:
        Screen(); 
        RectangleShape square(); 
};

#endif 