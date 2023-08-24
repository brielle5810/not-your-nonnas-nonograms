

#include <iostream>
#include <SFML/Graphics.hpp>
using namespace std;

class Welcome {
public:
    Welcome(int welcwidth, int welcheight);
    void drawwindow(sf::RenderWindow& welcomeScreen);
    char userchar;
    sf::Sprite titlepage;
    sf::Texture titletexture;


private:
    sf::Font font;
    sf::Text text;
    sf::Text prompt;
    sf::Text username;
};


