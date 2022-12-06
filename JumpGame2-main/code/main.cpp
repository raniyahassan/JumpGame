#include <iostream>
#include <SFML/Graphics.hpp>
#include <time.h>
#include <vector> 
#include "Screen.h"
#include "Player.h"
#include "Platform.h"

using namespace std;
using namespace sf;

int main()
{
    double width = 686; // VideoMode::getDesktopMode().width;
    double height = 966; // VideoMode::getDesktopMode().height; 

    Texture backgroundTexture; 
    backgroundTexture.loadFromFile("images/background.png"); 
    Sprite background(backgroundTexture); 

    Texture barTexture;
    barTexture.loadFromFile("images/bar.png");
    Sprite barOne(barTexture); 
    barOne.setPosition(300, 800); 

    Platform p;
    vector<Sprite> platforms = p.generator(); 


    Player player;     
    Event event;
    VideoMode VideoWindow(width, height); 
    RenderWindow window(VideoWindow, "JumpGame" ); 
    Screen screen(window); 

    enum State {START, PLAYING, END}; 
    State current = START; 

    while (window.isOpen())
    {
        
        while (window.pollEvent(event))
        {
            if (Keyboard::isKeyPressed(Keyboard::Escape)) {window.close();}
            if (event.type == Event::Closed) {window.close();}
            if (current == START)
            {                  
   
                /*window.clear(); 
                Vector2f posi = Steve.getPosition(); 
                posi.y += 2;
                Steve.setPosition(posi);
                player.setPosition(posi);
                window.draw(Steve);  */
                
          }
        }
        window.clear();
        window.draw(background);
        window.draw(barOne); 
        for (int i = 0; i < platforms.size(); i++) { window.draw(platforms[i]); }  
        window.display();  
    }
    
    return 0;
}
