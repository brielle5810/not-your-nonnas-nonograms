//
// Created by B on 8/14/2023.
//

#ifndef SFMLTEST_COLS_H
#define SFMLTEST_COLS_H
#include <SFML/Graphics.hpp>
using namespace std;
#include <iostream>

class cols {
public:
    cols(int x);
    int x;
    string name;
    sf::Text coltext;
    sf::Font colfont;

};


#endif //SFMLTEST_COLS_H
