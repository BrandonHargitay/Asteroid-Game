//
// Created by Brandon Hargitay on 12/7/22.
//

#include <iostream>
#include "Asteroids.h"

Asteroids::Asteroids() {
    asteroid.setTexture(Texture::getTexture(ASTEROIDS));
    asteroid.setScale(0.5,0.5);
    sf::Vector2u size = asteroid.getTexture()->getSize();
    asteroid.setOrigin(size.x / 2, size.y / 2);
    asteroid.setPosition(500,200);
}

void Asteroids::draw(sf::RenderTarget &target, sf::RenderStates states) const {
    for(Asteroids a : asteroidBelt ){
        sf::Sprite asteroidSprite = a.getSprite();
        target.draw(asteroidSprite);
    }
}

Asteroids::Asteroids(float scale, sf::Vector2f pos) {
    asteroid.setTexture(Texture::getTexture(ASTEROIDS));
    asteroid.setScale(scale,scale);
    sf::Vector2u size = asteroid.getTexture()->getSize();
    asteroid.setOrigin(size.x / 2, size.y / 2);
    asteroid.setPosition(pos);
}

void Asteroids::createAsteroid() {
    int numAsteroids = rand() % 7 + 1;

    for (int i = 0; i < numAsteroids; i++)
    {
        // Create a new asteroid with a random size and position
        Asteroids a(0.2 + (rand() / (double)RAND_MAX) * (0.5 - 0.2), sf::Vector2f(rand() % 1080, rand() % -100));
        // Add the asteroid to the vector
        asteroidBelt.push_back(a);
    }

}

sf::Vector2f Asteroids::getPosition() const{
    return asteroid.getPosition();
}

sf::Sprite Asteroids::getSprite() {
    return asteroid;
}

void Asteroids::update(sf::RenderWindow &window) {

    sf::Vector2u windowSize = window.getSize();
    for(Asteroids &a : asteroidBelt) {
        a.move({0, 0.1f});
        sf::FloatRect bounds = a.getGlobalBounds();
        //std::cout << asteroidBelt.size() << " ";
        auto it = std::find(asteroidBelt.begin(), asteroidBelt.end(), a);
//        for(Bullet b : bullets){
//            if(a.getGlobalBounds().intersects(b.getGlobalBounds())){
//                std::cout << "TOUCHED";
//                asteroidBelt.erase(it);
//                break;
//            }
//        }

        if (bounds.top >= windowSize.y) {
            if (*it == a) {
                asteroidBelt.erase(it);
                break;
            }
        }
    }

//
//        //auto it2 = asteroidBelt.begin();
//        //dasteroidBelt.erase(asteroidBelt.begin());
//        a.move({0,0.1f});
//        sf::FloatRect bounds = a.getGlobalBounds();
//        std::cout << asteroidBelt.size() << " ";
//        if(bounds.top  >= windowSize.y){
//            for (auto it = asteroidBelt.begin(); it != asteroidBelt.end(); ++it) {
//                if (*it == a) {
//                    asteroidBelt.erase(it);
//                    break;
//                }
//            }
//        }

}

void Asteroids::move(sf::Vector2f pos) {
    asteroid.move(pos);
}
sf::FloatRect Asteroids::getGlobalBounds() {
    return asteroid.getGlobalBounds();
}

bool Asteroids::operator==(const Asteroids &other) const {
    return asteroid.getPosition() == other.getPosition();
}

std::vector<Asteroids>& Asteroids::getVector() {
    return asteroidBelt;
}
