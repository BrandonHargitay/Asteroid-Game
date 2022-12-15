//
// Created by Brandon Hargitay on 12/12/22.
//

#include "Heart.h"

void Heart::draw(sf::RenderTarget &target, sf::RenderStates states) const {
    if(!checkState(HIDDEN))
        target.draw(heart);
}

Heart::Heart() {
    heart.setTexture(Texture::getTexture(HEART));
    heart.setScale(0.4,0.4);
}

void Heart::setPosition(float x, float y) {
    heart.setPosition(x,y);

}


sf::FloatRect Heart::getGlobalBounds() {
    return heart.getGlobalBounds();
}
