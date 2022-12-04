#include <iostream>
#include <SFML/Graphics.hpp>

using namespace std;

int main()
{
    double width = sf::VideoMode::getDesktopMode().width;
    double height = sf::VideoMode::getDesktopMode().height; 

    sf::Event event;
    sf::VideoMode VideoWindow(width, height);
    sf::RenderWindow window(VideoWindow, "JumpGame", Style::Default); 


    return 0;
}