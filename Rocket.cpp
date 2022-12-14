//
// Created by Brandon Hargitay on 12/5/22.
//

#include "Rocket.h"

#include <iostream>


Rocket::Rocket() {
    rocket.setTexture(Texture::getTexture(ROCKET));
    rocket.scale(0.2,0.2);
    sf::Vector2u size = rocket.getTexture()->getSize();
    rocket.setOrigin(size.x / 2, size.y / 2);
    rocket.setPosition(500,1000);
}

void Rocket::draw(sf::RenderTarget &target, sf::RenderStates states) const {
    target.draw(rocket);
}

void Rocket::move(sf::RenderWindow &window, const sf::Event &event) {
    // get the current position and rotation of the sprite
    sf::Vector2f pos = rocket.getPosition();
    float angle = rocket.getRotation();
    sf::Vector2<unsigned int> size2 = rocket.getTexture()->getSize();

    if(true){
        // check if the A or D keys are pressed and rotate the sprite accordingly
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)){
            angle -= ROTATION_SPEED; // rotate left
        }
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)){
            angle += ROTATION_SPEED; // rotate right
        }
        // calculate the initial rotation of the sprite (90 degrees if facing to the right)
        float initialRotation = 90.0f;

        // check if the W key is pressed and move the sprite in thde direction it is facing
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
        {
            // move the sprite in the direction it is facing
            pos.x += std::cos((angle - initialRotation) * 3.141592654f / 180.0f) * MOVE_SPEED;
            pos.y += std::sin((angle - initialRotation) * 3.141592654f / 180.0f) * MOVE_SPEED;
            lastAngle = rocket.getRotation();
            speed = MOVE_SPEED;
        }
        else
        {
            if(speed > 0){
                speed -= 0.000025f;
                pos.x += std::cos((lastAngle - initialRotation) * 3.141592654f / 180.0f) * speed;
                pos.y += std::sin((lastAngle - initialRotation) * 3.141592654f / 180.0f) * speed;
            }
        }
    }

    // update the position and rotation of the sprite
    rocket.setPosition(pos);
    rocket.setRotation(angle);
}

bool Rocket::hasTouchedWindowSides(sf::RenderWindow& window) {
    sf::FloatRect bounds = rocket.getGlobalBounds();
    sf::Vector2u windowSize = window.getSize();
    return (bounds.left <= 0 || bounds.top <= 0 || bounds.left + bounds.width >= windowSize.x || bounds.top + bounds.height >= windowSize.y);
}

sf::Vector2f Rocket::getPosition() {
    return rocket.getPosition();
}

float Rocket::getRotation() {
    return rocket.getRotation();
}

sf::FloatRect Rocket::getGlobalBounds() {
    return rocket.getGlobalBounds();
}
