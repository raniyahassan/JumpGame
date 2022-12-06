#include <iostream>
#include <SFML/Graphics.hpp>
#include <time.h>
#include <vector> 
#include "Screen.h"
#include "Guy.h"

using namespace std;
using namespace sf;

void generator(vector<Sprite>&, Texture&); 
void position(vector<Sprite>&);
void random(Sprite&); 
int positionCheck(Sprite&, vector<Vector2f>&); 
void jump(RenderWindow& win, Guy& x, Sprite& p); 

int main()
{
    double width = 686; //VideoMode::getDesktopMode().width;
    double height = 966; //VideoMode::getDesktopMode().height; 

    Texture backgroundTexture; 
    backgroundTexture.loadFromFile("images/background.png"); 
    Sprite background(backgroundTexture); 

    Texture barTexture;
    barTexture.loadFromFile("images/bar.png");
    Sprite barOne(barTexture); 
    barOne.setPosition(300, 800); 

    vector<Sprite> platforms(20); 
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
    VideoMode VideoWindow(width, height); 
    RenderWindow window(VideoWindow, "JumpGame" ); 

    enum State {START, PLAYING, END}; 
    State current = START; 

    while (window.isOpen())
    {
        
        while (window.pollEvent(event))
        {

            if (Keyboard::isKeyPressed(Keyboard::Escape)) {window.close();}

            if (event.type == Event::Closed) {window.close();}

            if (event.type == Event::MouseButtonPressed )
			{
					int clickedX = event.mouseButton.x;
					int clickedY = event.mouseButton.y;

                    cout << "clicked: (" << clickedX << ", " << clickedY << ")\n"; 
            }

            Vector2f guyPos = Steve.getPosition(); 
            Vector2f barPos = barOne.getPosition(); 

            if (current == START)
            {
                
                if ((barPos.y == (guyPos.y + 132)) && (barPos.x <= (guyPos.x + 55)) && (barPos.x >= (guyPos.x - 15)))
                {
                    jump(window, Steve, player); 
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

        for (int i = 0; i < platforms.size(); i++) {window.draw(platforms[i]);}
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
    srand(time(0)); 
    for (int i = 0; i < x.size(); i++)
    {
        random(x[i]); 
        cout << "Bar's position is (" << x[i].getPosition().x << ", " << x[i].getPosition().y << ")." << endl; 
    }
}

void random(Sprite& x)
{
    x.setPosition(70 + (rand() % 510), 70 + (rand() % 590));
}

void jump(RenderWindow& win, Guy& x, Sprite& p)
{
    int JumpHeight = 55;
    for (int i = 0; i < JumpHeight; i++)
    {
        win.clear();
        Vector2f pos = x.getPosition(); 
        pos.y -=2; 
        x.setPosition(pos); 
        p.setPosition(pos); 
        win.draw(p); 
    }
}