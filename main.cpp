#include <SFML/Graphics.hpp>
#include "Rocket.h"
#include "Asteroids.h"
#include "SpaceshipGun.h"
#include "Fonts.h"
#include "Health.h"
#include "ScoreBoard.h"
int main()
{
    srand((unsigned int)time(NULL));
    sf::RenderWindow window(sf::VideoMode(1080, 1920), "SFML works!");

    Rocket Rocket;
    Asteroids Asteroid;
    SpaceshipGun Gun;
    sf::Clock clock;
    Health health;
    ScoreBoard score({800,10});
    score.setScoreBoard();

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
            Gun.fire(window, event, Rocket.getPosition(), Rocket.getRotation() );

        }

        if(clock.getElapsedTime().asSeconds() >= 1.0f){
            Asteroid.createAsteroid();
            clock.restart();
        }
        Asteroid.update(window);
        score.updateScoreBoard(Gun.getScore());
        Rocket.move(window, event);
//        Gun.update(window, Asteroid.getVector(), Rocket.getGlobalBounds());
        health.update(Gun.update(window, Asteroid.getVector(), Rocket.getGlobalBounds()));
        window.clear();
        window.draw(Rocket);
        window.draw(Asteroid);
        window.draw(Gun);
        window.draw(health);
        window.draw(score);
        window.draw(score);
        window.display();
    }

    return 0;
}