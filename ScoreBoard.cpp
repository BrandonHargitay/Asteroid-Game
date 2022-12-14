//
// Created by Brandon Hargitay on 10/12/22.
//

#include "ScoreBoard.h"

ScoreBoard::ScoreBoard(){
    scoreBoardPosition.x = 0;
    scoreBoardPosition.y = 0;
}
ScoreBoard::ScoreBoard(sf::Vector2f poistion){
    scoreBoardPosition.x = poistion.x;
    scoreBoardPosition.y = poistion.y;
    font.loadFromFile("Fonts/Pixellari.ttf");
    sf::Text::setFont(font);

}
void ScoreBoard::setScoreBoard(){
    sf::Text::setString("Score: ");
    sf::Text::setPosition(scoreBoardPosition);
    sf::Text::setCharacterSize(40);
}
void ScoreBoard::updateScoreBoard(int score){

    std::string num = "Score: " + std::to_string(score);
    sf::Text::setString(num);
}