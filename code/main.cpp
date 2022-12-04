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

    Texture playerTexture;
    playerTexture.loadFromFile("images/tempGuy.png");
    Sprite player(playerTexture); 
    player.setPosition(Vector2f{172 , 500}); 

    Screen s; 
    RectangleShape backs = s.square(); 

    Event event;
    VideoMode VideoWindow(686, 966);
    RenderWindow window(VideoWindow, "JumpGame" ); 

    enum State {START, PLAYING, END}; 
    State current = START; 

    while (window.isOpen())
    {
        while (window.pollEvent(event))
        {

            window.draw(back); 

            if (Keyboard::isKeyPressed(Keyboard::Escape)) {window.close();}

            if (event.type == Event::Closed) {window.close();}

            if (current == START)
            {
                window.clear();
                window.draw(backs);

                // window.draw(text); 
                // if (start button pressed) {current == PLAYING}
                
            }

        }

        window.clear();
        window.draw(player); 
        window.display(); 
    }


    return 0;
}