//
// Created by Brandon Hargitay on 12/5/22.
//

#ifndef ASTEROIDS_GAME_ROCKET_H
#define ASTEROIDS_GAME_ROCKET_H
#include <cmath>
#include "Texture.h"
class Rocket : public sf::Drawable{


public:
    Rocket();
    void move(sf::RenderWindow& window, const sf::Event& event);
    virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const;
    sf::FloatRect getGlobalBounds();
    bool hasTouchedWindowSides(sf::RenderWindow& window);
    sf::Vector2f getPosition();
    float getRotation();
private:
    sf::Sprite rocket;
    const float ROTATION_SPEED = 0.1f; // how fast the sprite rotates
    const float MOVE_SPEED = .1; // how fast the sprite moves
    float  speed = 0;
    float lastAngle = 0.f;
};


#endif //ASTEROIDS_GAME_ROCKET_H
