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
        case ROCKET2: return "Images/Main Ship - Base - Full health.png";
        case ASTEROIDS: return "Images/asteriods.png";
        case ASTEROIDPIXEL: return "Images/Baren.png";
        case BULLET: return "Images/Bullet.png";
        case BACKGROUND: return "Images/Space_Stars2.png";
        case HEART: return  "Images/Heart.png";
        case LAST_TEXTURE: return "";
    }
}

sf::Texture &Texture::getTexture(textureEnum texture) {
    load(texture);
    return map[texture];
}
