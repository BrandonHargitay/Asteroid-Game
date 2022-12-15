//
// Created by Brandon Hargitay on 12/12/22.
//

#include "../include/Health.h"

Health::Health() {
    h1.setPosition(0,0);
    h2.setPosition(h1.getGlobalBounds().width + h1.getGlobalBounds().left + 10, 0 );
    h3.setPosition(h2.getGlobalBounds().left + h2.getGlobalBounds().width + 10, 0 );
}

void Health::draw(sf::RenderTarget &target, sf::RenderStates states) const {

    target.draw(h1);
    target.draw(h2);
    target.draw(h3);
}

void Health::update(bool hit) {
    if(hit && h2.checkState(HIDDEN)){
        h1.enableState(HIDDEN);
    }
    if(hit && h3.checkState(HIDDEN)){
        h2.enableState(HIDDEN);
    }
    if(hit){
        h3.enableState(HIDDEN);

    }




}
