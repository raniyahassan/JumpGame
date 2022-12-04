#include <iostream>
#include <SFML/Graphics.hpp>
#include "Screen.h"
#include "Guy.h"

using namespace std;
using namespace sf;

int main()
{
    //double width = VideoMode::getDesktopMode().width;
    //double height = VideoMode::getDesktopMode().height; 

    Texture background; 
    background.loadFromFile("images/background.png"); 
    Sprite back(background); 

    Texture playerTexture;
    playerTexture.loadFromFile("images/tempGuy.png");
    Sprite player(playerTexture); 
    player.setPosition(172, 650); 
    player.setScale(0.1,0.1); 

    Guy Steve(player); 

    Screen s; 
    RectangleShape backs = s.square(); 

    Event event;
    //VideoMode VideoWindow(width, height); 
    VideoMode VideoWindow(686, 966);
    RenderWindow window(VideoWindow, "JumpGame" ); 

    enum State {START, PLAYING, END}; 
    State current = START; 

    while (window.isOpen())
    {
        while (window.pollEvent(event))
        {
            window.clear(); 
            Vector2f posi = Steve.getPosition(); 
            posi.y += 8;
            Steve.setPosition(posi);
            player.setPosition(posi);
            window.draw(player); 

            if (Keyboard::isKeyPressed(Keyboard::Escape)) {window.close();}

            if (event.type == Event::Closed) {window.close();}

            if (current == START)
            {
                if (Keyboard::isKeyPressed(Keyboard::Space)) //actually if, char interacts with platform
                {
                    int jumpHeight = 50; 
                    int i = 0; 
                    while (i < jumpHeight)
                    {
                        window.clear();
                        Vector2f pos = Steve.getPosition(); 
                        pos.y -=1; 
                        Steve.setPosition(pos); 
                        player.setPosition(pos); 
                        window.draw(player); 
                        i++; 
                    }
                }    
                
                
            }
             
        }

        window.clear();
        window.draw(back);
        window.draw(backs); 
        window.draw(player); 
        window.display(); 
    }


    return 0;
}