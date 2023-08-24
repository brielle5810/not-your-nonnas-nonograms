#include <iostream>
#include <SFML/Graphics.hpp>
#include "welcome.h"
#include "resources.h"
#include "board.h"

int main() {


    while (true) {
        bool welc=true;
        bool instructions = false;
        bool levels =false;
        resources Resource;

        sf::RenderWindow welcomeScreen(sf::VideoMode(500, 500), "Nonograms!", sf::Style::Default);
        Welcome WS(500, 500);

        sf::Color darkpurple(128, 128, 192);
        sf::Color lightpurple(200, 192, 231);

        Resource.set_patterns();
        bool paused = false;
        bool gameover = true;
        bool gameon = false;

        string u = Resource.random();
        int len = Resource.patterns[u].size();

        board* Board = new board(len, len);
        Board->set_gram(len,Resource.patterns,u);
        Board->row_count_col_count(len,  len,Resource.patterns, u);
        Board->numassignrow();
        Board->numassigncol();

        while (welc) {
            while (welcomeScreen.isOpen()) {
                //gameover=true;
                sf::Event event;
                while (welcomeScreen.pollEvent(event)) {
                    if (event.type == sf::Event::MouseButtonPressed) {
                        sf::Mouse mouse;
                        auto coordinate = mouse.getPosition(welcomeScreen);
                        int coordx = (coordinate.x);
                        int coordy = (coordinate.y);

                        if (coordinate.x > (70) && coordinate.x < (210) && coordinate.y > 240 && coordinate.y < 295) {
                            gameon = true;
                            welc = false;
                            welcomeScreen.close();

                        }
                        if (coordx > (292) && coordx < (432) && coordy > (240) && coordy < (295)) {
                            //randomization
                            instructions = true;
                            welc = false;
                            welcomeScreen.close();

                        }
                        if (coordx > (180) && coordx < (320) && coordy > (348) && coordy < (401)) {
                            welc = false;
                            levels=true;
                            welcomeScreen.close();
                        }

                    }
                    if (event.type == sf::Event::Closed) {
                        welcomeScreen.close();
                        //make program END
                    }

                }
                welcomeScreen.clear(darkpurple);
                WS.drawwindow(welcomeScreen);
                welcomeScreen.display();

            }
        }
        while (instructions) {
            sf::RenderWindow instructionScreen(sf::VideoMode(500, 500), "n", sf::Style::Default);
            sf::Sprite instruct;
            sf::Font instructfont;
            sf::Texture instructtext;
            instructtext.loadFromFile("files/images/instructions.png");
            instruct.setTexture(instructtext);
            instructionScreen.draw(instruct);
            while (instructionScreen.isOpen()) {
                sf::Event event;
                while (instructionScreen.pollEvent(event)) {

                    if (event.type == sf::Event::MouseButtonPressed) {
                        instructions = false;
                        instructionScreen.close();
                        welc = true;

                    }
                    instructionScreen.clear(darkpurple);
                    instructionScreen.draw(instruct);
                    instructionScreen.display();
                }
            }
        }
        while (levels){

            sf::RenderWindow levelsScreen(sf::VideoMode(500, 500), "n", sf::Style::Default);
            sf::Sprite levelsp;
            sf::Font levelfont;
            sf::Texture leveltext;
            leveltext.loadFromFile("files/images/levelspage.png");
            levelsp.setTexture(leveltext);
            levelsScreen.draw(levelsp);

            while (levelsScreen.isOpen()) {
                sf::Mouse mouse;
                auto coordinate = mouse.getPosition(levelsScreen);
                sf::Event event;
                while (levelsScreen.pollEvent(event)) {
                    if (event.type == sf::Event::MouseButtonPressed) {
                        if (coordinate.x>68&&coordinate.x <100){
                            if (coordinate.y >125 &&coordinate.y<150){
                                u = "smile";
                                len = Resource.patterns[u].size();
                                board* Board1 = new board(len, len);
                                Board1->set_gram(len,Resource.patterns,u);
                                Board1->row_count_col_count(len,  len,Resource.patterns, u);
                                Board1->numassignrow();
                                Board1->numassigncol();
                                delete Board;
                                Board = Board1;

                                gameon=true;
                                levelsScreen.close();
                                levels=false;

                            }else if (coordinate.y >178 &&coordinate.y<207) {
                                u = "heart";
                                len = Resource.patterns[u].size();
                                board* Board1 = new board(len, len);
                                Board1->set_gram(len,Resource.patterns,u);
                                Board1->row_count_col_count(len,  len,Resource.patterns, u);
                                Board1->numassignrow();
                                Board1->numassigncol();
                                delete Board;
                                Board = Board1;

                                gameon=true;
                                levels=false;
                                levelsScreen.close();

                            }
                            else if (coordinate.y >234 &&coordinate.y<262){
                                u = "nf";
                                int len = Resource.patterns[u].size();
                                board* Board1 = new board(len, len);
                                Board1->set_gram(len,Resource.patterns,u);
                                Board1->row_count_col_count(len,  len,Resource.patterns, u);
                                Board1->numassignrow();
                                Board1->numassigncol();
                                delete Board;
                                Board = Board1;

                                gameon=true;
                                levels=false;
                                levelsScreen.close();

                            }
                            else if (coordinate.y >288 &&coordinate.y<318){
                                string u ="bmo";
                                int len = Resource.patterns[u].size();
                                board* Board1 = new board(len, len);
                                Board1->set_gram(len,Resource.patterns,u);
                                Board1->row_count_col_count(len,  len,Resource.patterns, u);
                                Board1->numassignrow();
                                Board1->numassigncol();
                                delete Board;
                                Board = Board1;

                                gameon=true;
                                levels=false;
                                levelsScreen.close();
                            }
                            else{

                            }
                        }
                    }
                    levelsScreen.clear(darkpurple);
                    levelsScreen.draw(levelsp);
                    levelsScreen.display();
                    if (event.type == sf::Event::Closed){
                        welc = true;
                        levelsScreen.close();
                        levels = false;
                    }
                }

            }
        }
        while (gameon) {
            sf::RenderWindow* gameScreen = new sf::RenderWindow(sf::VideoMode((Board->rowsvv.size()*32) + 200, (Board->rowsvv.size()*32) + 400),
                                                                "Not Your Nonna's Nonograms",
                                                                sf::Style::Default);
            while (gameScreen->isOpen()) {
                sf::Event event;
                while (gameScreen->pollEvent(event)) {
                    if (event.type == sf::Event::Closed) {
                        gameover = true;
                        gameon = false;
                        gameScreen->close();
                    }

                    if (event.type == sf::Event::MouseButtonPressed) {
                        sf::Mouse mouse;
                        auto coordinate = mouse.getPosition(*gameScreen);
                        int coordx = (coordinate.x - 200) / 32;
                        int coordy = (coordinate.y - 200) / 32;

                        if (event.key.code == sf::Mouse::Left) {
                            if (Board->have_we_won()){
                                if (coordinate.x >166 && coordinate.x <340){
                                    if (coordinate.y >265 && coordinate.y <336){
                                        gameon=false;
                                        welc=true;
                                        gameScreen->close();
                                        instructions = false;
                                        levels =false;
                                    }
                                    if (coordinate.y >367 && coordinate.y <436){
                                        string u = Resource.random();
                                        len = Resource.patterns[u].size();
                                        board* Board1 = new board(len, len);
                                        Board1->set_gram(len,Resource.patterns,u);
                                        Board1->row_count_col_count(len,  len,Resource.patterns, u);
                                        Board1->numassignrow();
                                        Board1->numassigncol();
                                        delete Board;
                                        Board = Board1;
                                        gameScreen->close();
                                        sf::RenderWindow* gameScreen1 = new sf::RenderWindow(sf::VideoMode((Board->rowsvv.size()*32) + 200, (Board->rowsvv.size()*32) + 400),
                                                                                            "Not Your Nonna's Nonograms",
                                                                                            sf::Style::Default);;

                                        delete gameScreen;
                                        gameScreen = gameScreen1;
                                        welc=false;
                                        instructions = false;
                                        levels =false;
                                    }
                                }
                            }
                            if (coordy < len) {
                                Board->retrieve(coordx, coordy)->click();
                                Board->checkgame();
                            } else {
                                if (coordinate.x > (((len)) - 304) &&
                                    coordinate.x < (((len)) - 240)) {
                                    if (!paused && Board->returngamecondition()) {
                                    }
                                }
                            }
                        } else if (event.key.code == sf::Mouse::Right) {
                            if (coordy < 16) {
                                bool flagup;
                                Board->retrieve(coordx, coordy)->flag(flagup);
                            }
                        }
                    }

                    gameScreen->clear(darkpurple);
                    Board->loadtextures();
                    Board->drawboard(gameScreen);
                    gameScreen->display();
                    gameon = false;
                }
            }
        }
    }
};