//
// Created by Brandon Hargitay on 12/7/22.
//

#ifndef ASTEROIDS_GAME_ASTEROIDS_H
#define ASTEROIDS_GAME_ASTEROIDS_H
#include <SFML/Graphics.hpp>
#include "Texture.h"
#include "Bullet.h"

class Asteroids : public sf::Drawable {
public:
    Asteroids();
    Asteroids(float scale, sf::Vector2f pos);
    virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const;
    void createAsteroid();
    void update(sf::RenderWindow &window);
    void move(sf::Vector2f pos);
    sf::FloatRect getGlobalBounds();
    std::vector<Asteroids>& getVector();
    bool operator==(const Asteroids& other) const;
private:
    sf::Sprite getSprite();
    sf::Vector2f getPosition() const;
    sf::Sprite asteroid;
    std::vector<Asteroids> asteroidBelt;
};


#endif //ASTEROIDS_GAME_ASTEROIDS_H
