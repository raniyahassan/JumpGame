#include <iostream>
#include <SFML/Graphics.hpp>
#include "Screen.h"

using namespace std;
using namespace sf;

int main()
{
    // double width = VideoMode::getDesktopMode().width;
    // double height = VideoMode::getDesktopMode().height; 

    Texture background; 
    background.loadFromFile("images/background.png"); 
    Sprite back(background); 
    Screen s(); 
    RectangleShape backs = s.rect(686, 966); 

    Event event;
    VideoMode VideoWindow(686, 966);
    RenderWindow window(VideoWindow, "JumpGame" ); 

    while (window.isOpen())
    {
        while (window.pollEvent(event))
        {
            if (Keyboard::isKeyPressed(Keyboard::Escape)) {window.close();}

            if (event.type == Event::Closed) {window.close();}
        }

        window.clear();
        window.draw(back); 
        window.draw(backs); 
        window.display(); 
    }


    return 0;
}