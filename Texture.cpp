//
// Created by Jessie Mejia on 11/22/22.
//

#include "Texture.h"
std::map<textureEnum, sf::Texture> Texture::map;

void Texture::load(textureEnum texture) {
    map[texture].loadFromFile(getPath(texture));
}

std::string Texture::getPath(textureEnum texture) {
    switch(texture){
        case ROCKET: return "Images/Rocket.png";
        case ASTEROIDS: return "Images/asteriods.png";
        case BULLET: return "Images/Bullet.png";
        case HEART: return  "Images/Heart.png";
        case LAST_TEXTURE: return "";
    }
}

sf::Texture &Texture::getTexture(textureEnum texture) {
    load(texture);
    return map[texture];
}
