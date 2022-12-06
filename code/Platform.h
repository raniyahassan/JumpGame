#ifndef PLATFORM
#define PLATFORM

#include <iostream>
#include <SFML/Graphics.hpp>

using namespace std;
using namespace sf;

class Platform 
{
    private:
        int y; 
    public:
        Platform(); 
        Sprite PlatformMaking(); 
        vector<Sprite>* Platforms(); 
        void Positioner(vector<Sprite>& x); 
        vector <Sprite>* NormalPlatforms(); 
};

#endif