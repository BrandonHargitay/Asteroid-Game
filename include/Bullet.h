//
// Created by Brandon Hargitay on 12/7/22.
//

#ifndef ASTEROIDS_GAME_BULLET_H
#define ASTEROIDS_GAME_BULLET_H
#include "Texture.h"
#include <vector>
class Bullet : public sf::Drawable{
public:
    Bullet(sf::Vector2f pos, float rot);
    virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const;
    void update();
    sf::FloatRect getGlobalBounds();
    sf::Vector2f getPosition() const;
    void fire(sf::Vector2f pos, float rot);
    bool operator==(const Bullet& other) const;

private:
    sf::Sprite bullet;
    bool isFired = false;
    float vx = 0;
    float vy = 0;
};


#endif //ASTEROIDS_GAME_BULLET_H
