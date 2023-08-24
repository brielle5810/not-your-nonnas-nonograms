//
// Created by B on 8/12/2023.
//
#include "resources.h"
#include "board.h"
#include "rows.h"
#include <map>
using namespace std;

board::board(int boardwidth, int boardheight) {
    if (!numfont.loadFromFile("files/DigitalDisco.ttf"))
    {
        std::cout << "Font Did Not Load!!!!!!!!!!!!\n";
    }

    this->boardwidth = boardwidth;
    this->boardheight = boardheight;

    for (unsigned int j = 0; j < boardheight; j++){
        rows RowJ(j);
        rowsvv.push_back(RowJ);

        cols ColJ(j);
        colsvv.push_back(ColJ);
    }

    for (unsigned int i = 0; i < boardwidth; i++){
        vector<tile> temp;
        for (unsigned int j = 0; j < boardheight; j++){
            temp.push_back(tile(i,j));
        }
        boardgrid.push_back(temp);
        for (unsigned int j=0;j<boardheight;j++){
        }
    }
}

void board::loadtextures(){
    //2020
    twbutton.setOrigin(0,0);
    twtext.loadFromFile("files/images/200200.png");
    twbutton.setTexture(twtext);
}

void board::set_gram(int W,map<string, vector<vector<int>>>  map_1,string u){
    for (unsigned int i = 0; i < W; i++) {
        for (unsigned int j = 0; j < W; j++) {
            if (map_1[u][i][j] == 1) {
                boardgrid[j][i].setgram();
            }
        }
    }
}
void board::row_count_col_count(int W, int H, map<string, vector<vector<int>>>  map_1, string u) {
    string full_text;
    string temp;
    for (unsigned int i = 0; i < W; i++) {
        temp = "";
        full_text = "";
        int rowcount = 0;
        for (unsigned int j = 0; j < H; j++) {
            int recent = map_1[u][i][j];
            if (map_1[u][i][j] == 1) {
                rowcount += 1;
            } else if (map_1[u][i][j] == 0) {
                if (rowcount != 0) {
                    temp = to_string(rowcount);
                    full_text += " " + temp;
                    rowcount = 0;
                }
            }
        }
        if (full_text == "") {
            if (rowcount != 0) {
                full_text = " " + to_string(rowcount);
            } else {
                full_text = " 0";
            }
        }
        rownums.push_back(full_text);
    }

    for (unsigned int i = 0; i < H; i++) {//w
        temp = "";
        full_text = "";
        int colcount = 0;
        for (unsigned int j = 0; j < W; j++) {//h
            int recent = map_1[u][i][j];
            if (map_1[u][j][i] == 1) {
                colcount += 1;
            } else if (map_1[u][j][i] == 0) {
                if (colcount != 0) {
                    temp = to_string(colcount);
                    full_text += temp + "\n";
                    colcount = 0;
                }
            }
        }
        if (full_text == "") {
            if (colcount != 0) {
                full_text = to_string(colcount) + "\n";
            } else {
                full_text = "0\n";
            }
        }

        if (!full_text.empty() && full_text[full_text.length() - 1] == '\n') {
            full_text.erase(full_text.length() - 1);
        }
        colnums.push_back(full_text);
    }
}


void board::drawboard(sf::RenderWindow* boardScreen){
    if (game_condition){
        boardScreen->draw(happysprite);
    }
    else{

        if (game_lose_real){

        }
        else{
            coolbutton.loadFromFile("files/images/winpage.png");
            happysprite.setTexture(coolbutton);
            boardScreen->draw(happysprite);
        }
    }
    if (game_condition) {
        for (unsigned int i=0;i<boardwidth;i++){
            boardScreen->draw(rowsvv[i].rowtext);
            boardScreen->draw(colsvv[i].coltext);
        }
        for (unsigned char i = 0; i < boardwidth; i++) {
            for (unsigned char j = 0; j < boardheight; j++) {

                tilesprite.setPosition((32 * i) + 200, (32 * j) + 200);

                boardgrid[i][j].revealedtexture.loadFromFile("files/images/tile_revealed.png");
                boardgrid[i][j].tilerevealed.setTexture(boardgrid[i][j].revealedtexture);

                if (!boardgrid[i][j].openstatus()) {
                    boardgrid[i][j].tiletexture.loadFromFile("files/images/tile_hidden.png");
                    boardgrid[i][j].tile1.setTexture(boardgrid[i][j].tiletexture);
                }

                if (boardgrid[i][j].flagstatus()) {
                    boardgrid[i][j].toptexture.loadFromFile("files/images/flag.png");
                    boardgrid[i][j].tile2.setTexture(boardgrid[i][j].toptexture);
                }

                if (boardgrid[i][j].gramstatus()) {
                    boardgrid[i][j].bottomtexture.loadFromFile("files/images/tile_revealed.png"); //debugging purposes-> use heartgram.png
                    boardgrid[i][j].tile3.setTexture(boardgrid[i][j].bottomtexture);
                }
                boardScreen->draw(boardgrid[i][j].tilerevealed);
                if (boardpause || leadopen) {

                } else {
                    if (!game_condition) {
                        if (game_won_real) {
                            if (boardgrid[i][j].gramstatus()) {
                                boardScreen->draw(boardgrid[i][j].tile3);
                            }

                            if (!boardgrid[i][j].openstatus()) {
                                boardScreen->draw(boardgrid[i][j].tile1);
                            } else {
                                if (!boardgrid[i][j].gramstatus()) {
                                    if (true) {
                                        boardScreen->draw(boardgrid[i][j].digittile);
                                    }
                                }
                            }
                            if (boardgrid[i][j].flagstatus()) {
                                boardScreen->draw(boardgrid[i][j].tile2);
                            }
                        } else if (game_lose_real) {

                            if (boardgrid[i][j].flagstatus()) {
                                boardScreen->draw(boardgrid[i][j].tile2);
                            }
                            if (boardgrid[i][j].gramstatus()) {
                                boardScreen->draw(boardgrid[i][j].tile3); //mines
                                boardgrid[i][j].open();
                            }

                            if (!boardgrid[i][j].openstatus()) {
                                boardScreen->draw(boardgrid[i][j].tile1);
                            } else {
                                if (!boardgrid[i][j].gramstatus()) {
                                    if (true) {
                                        boardScreen->draw(boardgrid[i][j].digittile);
                                    }
                                }
                            }

                        } else {

                        }
                    } else if (debugmode) {
                        //boardScreen.draw(boardgrid[i][j].tile3);
                        if (!boardgrid[i][j].openstatus()) {
                            boardScreen->draw(boardgrid[i][j].tile1);
                            if (!boardgrid[i][j].gramstatus()) {
                                boardScreen->draw(boardgrid[i][j].digittile);
                            }

                        } else {
                            boardScreen->draw(boardgrid[i][j].digittile);
                        }
                        if (boardgrid[i][j].flagstatus()) {
                            boardScreen->draw(boardgrid[i][j].tile2);
                        }
                        if (boardgrid[i][j].gramstatus()) {
                            boardScreen->draw(boardgrid[i][j].tile3);
                        }

                    } else {
                        if (boardgrid[i][j].gramstatus()) {
                            boardScreen->draw(boardgrid[i][j].tile3);
                        }

                        if (!boardgrid[i][j].openstatus()) {
                            boardScreen->draw(boardgrid[i][j].tile1);
                        } else {
                            if (!boardgrid[i][j].gramstatus()) {
                                boardScreen->draw(boardgrid[i][j].digittile);
                            }
                        }
                        if (boardgrid[i][j].flagstatus()) {
                            boardScreen->draw(boardgrid[i][j].tile2);
                        }
                    }
                }

            }
        }
    }
}

tile* board::retrieve(int coordx,int coordy){
    tile *t = &boardgrid[coordx][coordy];
    return t;
}


void board::numassignrow(){
    if (!rowfont.loadFromFile("files/DigitalDisco.ttf"))
    {
        std::cout << "Font Did Not Load!!!!!!!!!!!!\n";
    }
    for (unsigned int i=0;i<boardheight;i++){
        rowsvv[i].rowtext.setFont(rowfont);
        rowsvv[i].rowtext.setString(rownums[i]);
        sf::FloatRect rowtextRect = rowsvv[i].rowtext.getLocalBounds();
        rectcollrow.push_back(rowtextRect);

        rowsvv[i].rowtext.setOrigin(rectcollrow[i].width,(rectcollrow[i].height/2.5));
        rowsvv[i].rowtext.setPosition(190, (32 * i)+200);
    }
}

void board::numassigncol(){
    if (!colfont.loadFromFile("files/DigitalDisco.ttf"))
    {
        std::cout << "Font Did Not Load!!!!!!!!!!!!\n";
    }
    for (unsigned int i=0;i<boardheight;i++){
        colsvv[i].coltext.setFont(colfont);
        colsvv[i].coltext.setString(colnums[i]);
        sf::FloatRect coltextRect = colsvv[i].coltext.getLocalBounds();
        rectcollcol.push_back(coltextRect);

        colsvv[i].coltext.setOrigin((rectcollcol[i].width-20),(rectcollcol[i].height));
        colsvv[i].coltext.setPosition((32 * i)+205, 182);
    }
}



bool board::checkgame() {
    int gs = 0;
    int possclosedmines = 0;

    for (unsigned int i = 0; i < boardwidth; i++) {
        for (unsigned int j = 0; j < boardheight; j++) {
            if ((boardgrid[i][j].gramstatus() == true)) {
                gs += 1;
            }
            if ((boardgrid[i][j].gramstatus() == false)) {
            }
        }
    }

    int correct = 0;
    for (unsigned int i = 0; i < boardwidth; i++) {
        for (unsigned int j = 0; j < boardheight; j++) {
            if ((boardgrid[i][j].gramstatus() == true) && (boardgrid[i][j].openstatus() == true)) {
                correct += 1;

            }
        }
    }
    if (correct == gs) {
        game_won(game_won_real);
        return game_won_real = true;
    }
}

bool board::returngamecondition(){
    return game_condition;
}
bool board::have_we_won() {
    return game_won_real;
}


bool board::game_won(bool& game_won_real) {
    game_condition = false;
    game_won_real = true;
    return game_won_real;
}



