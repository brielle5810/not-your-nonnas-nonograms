//
// Created by B on 8/13/2023.
//

#ifndef SFMLTEST_ROWS_H
#define SFMLTEST_ROWS_H
#include <SFML/Graphics.hpp>
using namespace std;
#include <iostream>


class rows {
public:
    rows(int x);
    int x;
    string name;
    sf::Text rowtext;
    sf::Font rowfont;

};

#endif //SFMLTEST_ROWS_H
