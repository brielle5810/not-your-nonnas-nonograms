//
// Created by B on 8/14/2023.
//

#include "cols.h"
cols::cols(int x){
    this->x=x;
    if (!colfont.loadFromFile("files/DigitalDisco.ttf"))
    {
        std::cout << "Font Did Not Load!!!!!!!!!!!!\n";
    }
    coltext.setFont(colfont);
    coltext.setFillColor(sf::Color::White);
    coltext.setCharacterSize(32);
}