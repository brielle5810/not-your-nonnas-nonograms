//
// Created by B on 8/13/2023.
//

#include "rows.h"
rows::rows(int x) {
    this->x=x;
    if (!rowfont.loadFromFile("files/DigitalDisco.ttf"))
    {
        std::cout << "Font Did Not Load!!!!!!!!!!!!\n";
    }
    rowtext.setFont(rowfont);
    rowtext.setFillColor(sf::Color::White);
    rowtext.setCharacterSize(32);
}