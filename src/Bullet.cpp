//
// Created by Brandon Hargitay on 12/7/22.
//

#include <iostream>
#include <cmath>
#include "../include/Bullet.h"

Bullet::Bullet(sf::Vector2f pos, float rot) {
    bullet.setTexture(Texture::getTexture(BULLET));
    bullet.setScale({0.06,0.06});
    sf::Vector2u size = bullet.getTexture()->getSize();
    bullet.setOrigin(size.x / 2, size.y / 2);
    //shape.setPosition(50,500);

    //INIT
    vx = std::cos((rot - 90) * 3.14159265 / 180.0) * 0.2;
    vy = std::sin((rot - 90) * 3.14159265 / 180.0) * 0.2;
    bullet.setRotation(rot+90);
    bullet.setPosition(pos);
    bullet.move(vx, vy);
}

void Bullet::draw(sf::RenderTarget &target, sf::RenderStates states) const {

    target.draw(bullet);
}

void Bullet::update() {
    //shape.setPosition(500,100);
    bullet.move(vx, vy);

    //std::cout << shape.getPosition().x << std::endl;
    //std::cout << shape.getPosition().y << std::endl;
    //std::cout << "MOVE BULLET" << " ";
}



void Bullet::fire(sf::Vector2f pos, float rot) {
//    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
//    isFired = true;
//    vx = std::cos((rot - 90)  * 3.14159265 / 180.0) * 0.2;
//    vy = std::sin((rot - 90)* 3.14159265 / 180.0) * 0.2;
//    shape.setRotation(rot+90);
//    shape.setPosition({10,10});
//
//    shape.move(vx, vy);
//    std::cout << "FIRE";

}

sf::FloatRect Bullet::getGlobalBounds() {
    return bullet.getGlobalBounds();
}

bool Bullet::operator==(const Bullet &other) const {
    return bullet.getPosition() == other.getPosition();
}

sf::Vector2f Bullet::getPosition() const {
    return bullet.getPosition();
}

