//
// Created by Brandon Hargitay on 12/8/22.
//

#ifndef ASTEROIDS_GAME_SPACESHIPGUN_H
#define ASTEROIDS_GAME_SPACESHIPGUN_H
#include "Bullet.h"
#include "Asteroids.h"
#include <SFML/Audio.hpp>
class SpaceshipGun : public sf::Drawable{
public:
    SpaceshipGun();
    void draw(sf::RenderTarget &target, sf::RenderStates states) const override;
    void fire(sf::RenderWindow &window, const sf::Event &event, sf::Vector2f pos, float rot);
    bool update(sf::RenderWindow &window, std::vector<Asteroids>&, sf::FloatRect spaceship);
    int getScore() const;
private:
    std::vector<Bullet> ammo;
    int score = 0;
    sf::SoundBuffer buffer;
    sf::Sound sound;
};


#endif //ASTEROIDS_GAME_SPACESHIPGUN_H
