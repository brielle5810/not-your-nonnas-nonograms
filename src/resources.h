//
// Created by B on 8/12/2023.
//

#ifndef SFMLTEST_RESOURCES_H
#define SFMLTEST_RESOURCES_H

using namespace std;
#include <iostream>
#include <fstream>
#include <map>
#include <SFML/Graphics.hpp>
class resources {

    public:
        string random();
        void set_patterns();

        map<string, sf::Texture> collection;

        map<string, vector<vector<int>>> patterns;

    private:
        int colnum;
        int rownum;
};


#endif //SFMLTEST_RESOURCES_H
