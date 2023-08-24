
#ifndef SFMLTEST_TILE_H
#define SFMLTEST_TILE_H
#include <vector>
#include <iostream>
using namespace std;

#include <SFML/Graphics.hpp>

class tile {
public:

    tile(int x, int y);
    bool gramstatus();
    bool flagstatus();
    bool openstatus();

    void setdigtexture();
    bool flag(bool& flagup);
    void click();
    void open();
    void setgram();


    sf::Sprite tile1;
    sf::Texture tiletexture;

    sf::Sprite tile2;
    sf::Texture toptexture;

    sf::Sprite tile3;
    sf::Texture bottomtexture;

    sf::Sprite tilerevealed;
    sf::Texture revealedtexture;
    map<string, sf::Texture> _textures;

    sf::Sprite digittile;
    sf::Texture digit;
    int x;
    int y;

private:

    vector<tile*> adjacent;
    bool isgram=false;
    bool isflagged=false;
    bool isopen=false;

};

#endif //SFMLTEST_TILE_H
