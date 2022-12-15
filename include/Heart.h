//
// Created by Brandon Hargitay on 12/12/22.
//

#ifndef ASTEROIDS_GAME_HEART_H
#define ASTEROIDS_GAME_HEART_H
#include <SFML/Graphics.hpp>
#include "states.h"
#include "Texture.h"

class Heart : public sf::Drawable, public states {
public:
    Heart();
    virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const;
    void setPosition(float x, float y);

    sf::FloatRect getGlobalBounds();

private:
    sf::Sprite heart;
};


#endif //ASTEROIDS_GAME_HEART_H
