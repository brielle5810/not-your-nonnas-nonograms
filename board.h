//
// Created by B on 8/12/2023.
//

#ifndef SFMLTEST_BOARD_H
#define SFMLTEST_BOARD_H
using namespace std;
#include <SFML/Graphics.hpp>
#include <iostream>
#include "tile.h"
#include "rows.h"
#include "cols.h"
#include <vector>
#include <map>

class board {
public:
    sf::Font rowfont;
    sf::Font colfont;
    board(int boardwidth, int boardheight);
    void loadtextures();
    void drawboard(sf::RenderWindow* boardScreen);
    tile* retrieve(int coordx,int coordy);
    bool checkgame();
    bool game_won(bool& game_won_real);
    bool have_we_won();
    bool returngamecondition();
    void numassignrow();
    void numassigncol();
    void set_gram(int W,map<string, vector<vector<int>>>  map_1,string u);
    void row_count_col_count(int W, int H, map<string, vector<vector<int>>>  map_1, string u);
    vector<sf::FloatRect> rectcollrow;
    vector<sf::FloatRect> rectcollcol;
    vector<vector<tile>> boardgrid;
    vector<rows> rowsvv;
    vector<cols> colsvv;
    vector<string>rownums;
    vector<string> colnums;


private:
    bool leadopen=false;
    bool boardpause=false;
    sf::Sprite pauseplay;
    sf::Sprite lbbutton;
    sf::Sprite debugbutton;
    sf::Sprite happysprite;
    sf::Texture coolbutton;
    sf::Texture happybutton;
    sf::Texture pptext;
    sf::Texture lbtext;
    sf::Sprite twbutton;
    sf::Texture twtext;
    int boardwidth;
    int boardheight;


    sf::Font numfont;
    sf::Text numrowtext;

    sf::Color lightpurple = sf::Color(200,192,231);

    bool debugmode=false;
    bool game_won_real = false;
    bool game_lose_real = false;
    bool game_condition = true;


    sf::Font font;
    sf::Text text;

    sf::Sprite tilesprite;
    sf::Text rowtext;
    sf::Text coltext;
    sf::Text row1text;
    sf::Text row2text;
    sf::Text row3text;
    sf::Text row4text;
    sf::Text row5text;
};


#endif //SFMLTEST_BOARD_H
