#include <iostream>
#include <SFML/Graphics.hpp>
#include <vector> 
#include "Screen.h"
#include "Guy.h"

using namespace std;
using namespace sf;

void generator(vector<Sprite>&, Texture&); 
void position(vector<Sprite>&);



int main()
{
    //double width = VideoMode::getDesktopMode().width;
    //double height = VideoMode::getDesktopMode().height; 

    Texture backgroundTexture; 
    backgroundTexture.loadFromFile("images/background.png"); 
    Sprite background(backgroundTexture); 

    Texture barTexture;
    barTexture.loadFromFile("images/bar.png");
    Sprite barOne(barTexture); 
    barOne.setPosition(300, 800); 

    vector<Sprite> platforms(5); 
    generator(platforms, barTexture); 
    position(platforms); 

    Texture playerTexture;
    playerTexture.loadFromFile("images/tempGuy.png");
    Sprite player(playerTexture); 
    player.setPosition(270, 650); 
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
            if (Keyboard::isKeyPressed(Keyboard::Escape)) {window.close();}

            if (event.type == Event::Closed) {window.close();}

            Vector2f guyPos = Steve.getPosition(); 
            Vector2f barPos = barOne.getPosition(); 
            cout << "guy: (" << guyPos.x << ", " << guyPos.y << ")\n"; 
            cout << "bar: (" << barPos.x << ", " << barPos.y << ")\n"; 

            if (current == START)
            {
                if ((barPos.y == (guyPos.y + 132)) && (barPos.x <= (guyPos.x + 75)) && (barPos.x >= (guyPos.x - 75)))
                {
                    int jumpHeight = 55; 
                    int i = 0; 
                    while (i < jumpHeight)
                    {
                        window.clear();
                        Vector2f pos = Steve.getPosition(); 
                        pos.y -=2; 
                        Steve.setPosition(pos); 
                        player.setPosition(pos); 
                        window.draw(player); 
                        i++; 
                    }
                }  

                if (Keyboard::isKeyPressed(Keyboard::Left))
                {
                    window.clear();
                    Vector2f pos = Steve.getPosition(); 
                    pos.x -=2; 
                    Steve.setPosition(pos); 
                    player.setPosition(pos); 
                    window.draw(player); 
                }

                if (Keyboard::isKeyPressed(Keyboard::Right))
                {
                    window.clear();
                    Vector2f pos = Steve.getPosition(); 
                    pos.x +=2; 
                    Steve.setPosition(pos); 
                    player.setPosition(pos); 
                    window.draw(player); 
                }

                window.clear(); 
                Vector2f posi = Steve.getPosition(); 
                posi.y += 2;
                Steve.setPosition(posi);
                player.setPosition(posi);
                window.draw(player);   
                
            }
             
        }

        window.clear();
        
        window.draw(background);
        window.draw(backs); 
        window.draw(barOne); 
        window.draw(platforms[0]);
        window.draw(platforms[1]);
        window.draw(platforms[2]);
        window.draw(platforms[3]);
        window.draw(player); 
        window.display(); 
    }


    return 0;
}

void generator(vector<Sprite>& x, Texture& texture)
{
    for (int i = 0; i < x.size(); i++)
    {
        x[i].setTexture(texture); 
    }
}

void position(vector<Sprite>& x)
{
    for (int i = 0; i < x.size(); i++)
    {
        x[i].setPosition((60*i+4),70+(i*3)); 
        cout << "Bar's position is (" << x[i].getPosition().x << ", " << x[i].getPosition().y << ")." << endl; 
    }
}