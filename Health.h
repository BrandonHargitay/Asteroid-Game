//
// Created by Brandon Hargitay on 12/12/22.
//

#ifndef ASTEROIDS_GAME_HEALTH_H
#define ASTEROIDS_GAME_HEALTH_H
#include "Heart.h"
#include <iostream>

class Health : public sf::Drawable{
public:
    Health();
    virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const;
    void update(bool hit);
private:
    Heart h1;
    Heart h2;
    Heart h3;
};


#endif //ASTEROIDS_GAME_HEALTH_H
