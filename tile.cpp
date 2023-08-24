//
// Created by B on 8/12/2023.
//

#include "tile.h"

tile::tile(int x,int y){
    this->x=x;
    this->y=y;
    tiletexture.loadFromFile("files/images/tile_hidden.png");
    toptexture.loadFromFile("files/images/tile_hidden.png");
    tile1.setTexture(tiletexture); // del maybs
    tile1.setPosition(static_cast<float>(32 * x)+200, static_cast<float>(32 * y)+200);
    tile2.setPosition(static_cast<float>(32 * x)+200, static_cast<float>(32 * y)+200);
    tilerevealed.setPosition(static_cast<float>(32 * x)+200, static_cast<float>(32 * y)+200);
    tile3.setPosition(static_cast<float>(32 * x)+200, static_cast<float>(32 * y)+200);
    digittile.setPosition(static_cast<float>(32 * x)+200, static_cast<float>(32 * y)+200);
    this->isopen = false;
    this->isgram = false;
    this->isflagged = false;

}

bool tile::flag(bool& flagup){
    if (!isopen){
        this->isflagged = !this->isflagged;
        if (this->isflagged){
            return (flagup =false);
        }
        else if (this->isflagged==false){
            return (flagup =true);
        }
    }

}

void tile::setgram(){
    this->isgram=true;
}

bool tile::gramstatus(){
    return (this->isgram);
}
bool tile::flagstatus(){
    return (this->isflagged);
}
bool tile::openstatus(){
    return (this->isopen);
}
void tile::click(){
    this->isopen = !this->isopen;
    this->isflagged = false;
}

void tile::open(){
    this->isopen=true;
}
