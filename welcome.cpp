//
// Created by B on 8/12/2023.
//

// Created by briel on 4/7/2023.
//
#include "welcome.h"
#include <iostream>
#include <SFML/Graphics.hpp>


Welcome::Welcome(int welcwidth, int welcheight){
    sf::Color darkpurple(128,128,192);
    sf::Color lightpurple(200,192,231);
    //cout << welcheight << welcwidth <<endl;
    if (!font.loadFromFile("files/DigitalDisco.ttf"))
    {
        std::cout << "Font Did Not Load!!!!!!!!!!!!\n";
    }

    titletexture.loadFromFile("files/images/titlepage.png");
    titlepage.setTexture(titletexture);

    text.setFont(font);
    text.setString("");
    text.setCharacterSize(48);
    text.setFillColor(lightpurple);
    text.setStyle(sf::Text::Bold);

    sf::FloatRect textRect = text.getLocalBounds();
    text.setOrigin(textRect.width/2,textRect.height/2);
    text.setPosition(sf::Vector2f(welcwidth/2.0f, (welcheight/2.0f)-150));

    prompt.setFont(font);
    prompt.setCharacterSize(36);
    prompt.setFillColor(lightpurple);
    prompt.setStyle(sf::Text::Bold);
    sf::FloatRect promptRect = prompt.getLocalBounds();
    prompt.setOrigin(promptRect.width/2,promptRect.height/2);
    prompt.setPosition(sf::Vector2f(welcwidth/2.0f, (welcheight/2.0f)-75));

    username.setFont(font);
    username.setString("");
    username.setCharacterSize(24);
    username.setFillColor(lightpurple);
    username.setStyle(sf::Text::Bold);
    sf::FloatRect userRect = username.getLocalBounds();
    username.setOrigin(userRect.width/2,userRect.height/2);
    username.setPosition(sf::Vector2f(welcwidth/2.0f, (welcheight/2.0f)-45));
}

void Welcome::drawwindow(sf::RenderWindow& welcomeScreen){
    welcomeScreen.draw(titlepage);
    welcomeScreen.draw(text);
    welcomeScreen.draw(prompt);
    welcomeScreen.draw(username);
}

