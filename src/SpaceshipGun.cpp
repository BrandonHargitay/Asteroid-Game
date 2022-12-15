//
// Created by Brandon Hargitay on 12/8/22.
//

#include <iostream>
#include "../include/SpaceshipGun.h"
#include <algorithm>

SpaceshipGun::SpaceshipGun() {
    buffer.loadFromFile("Sounds/assets_beep.ogg");
    sound.setBuffer(buffer);

}
void SpaceshipGun::draw(sf::RenderTarget &target, sf::RenderStates states) const {
    for(Bullet b : ammo){
        target.draw(b);
    }
}


void SpaceshipGun::fire(sf::RenderWindow &window, const sf::Event &event, sf::Vector2f pos, float rot) {
    if((event.type == sf::Event::KeyPressed) && (event.key.code == sf::Keyboard::Space)){

        Bullet b2(pos, rot);
        ammo.push_back(b2);
    }
}

bool SpaceshipGun::update (sf::RenderWindow &window, std::vector<Asteroids>& asteroidB, sf::FloatRect spaceship) {
    bool hit = false;
    sf::Vector2u windowSize = window.getSize();
    for(Asteroids &a : asteroidB){
        auto it2 = std::find(asteroidB.begin(), asteroidB.end(), a);
        //checks if the rockets has hit an asteroid
        if(spaceship.intersects(a.getGlobalBounds())){
            asteroidB.erase(it2);
            hit = true;
        }
    }
    for(Bullet &b : ammo) {
        b.update();
        sf::FloatRect bounds = b.getGlobalBounds();
        auto it = std::find(ammo.begin(), ammo.end(), b);
        for(Asteroids &a : asteroidB){
            auto it2 = std::find(asteroidB.begin(), asteroidB.end(), a);
            //checks if a bullet has hit an asteroid
            if(a.getGlobalBounds().intersects(b.getGlobalBounds())){
                score += 100;
                //deletes the asteroid
                asteroidB.erase(it2);
                //deletes the bullet
                ammo.erase(it);
                std::cout << "Score: " << score;
                sound.play();
                break;
            }
        }
        //checks if the bullet is outside the bounds of the window
        if(bounds.left <= 0 || bounds.top <= 0 || bounds.left + bounds.width >= windowSize.x || bounds.top + bounds.height >= windowSize.y){
            if (*it == b) {
                ammo.erase(it);
                break;
        }
    }
}
    return hit;
}

int SpaceshipGun::getScore() const {
    return score;
}



