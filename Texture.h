//
// Created by Jessie Mejia on 11/22/22.
//

#ifndef CLASSEXAMPLE1122_TEXTURE_H
#define CLASSEXAMPLE1122_TEXTURE_H

#include <map>
#include "Enums/textureEnum.h"
#include <SFML/Graphics.hpp>

class Texture {
private:
    static std::map<textureEnum, sf::Texture> map;
    static void load(textureEnum texture);
    static std::string getPath(textureEnum texture);
public:
    static sf::Texture& getTexture(textureEnum texture);
};


#endif //CLASSEXAMPLE1122_TEXTURE_H
