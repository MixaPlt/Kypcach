#include "GameModeMenu.h"

GameModeMenu::GameModeMenu()
{
    firstMode = new ImageButton(sf::Vector2f(300, 150), sf::Vector2f(100, 75));
    secondMode = new ImageButton(sf::Vector2f(300, 150), sf::Vector2f(100, 225));
    thirdMode = new ImageButton(sf::Vector2f(300, 150), sf::Vector2f(100, 375));

    firstMode->setOutColor(sf::Color(255, 255, 255, 255));
    secondMode->setOutColor(sf::Color(255, 255, 255, 255));
    thirdMode->setOutColor(sf::Color(255, 255, 255, 255));

    firstMode->setTexture("resources/easy.jpg");
    secondMode->setTexture("resources/medium.jpg");
    thirdMode->setTexture("resources/hard.jpg");

    firstMode->setOutlineThickness(2);
    secondMode->setOutlineThickness(2);
    thirdMode->setOutlineThickness(2);

    infoLabel = new sf::Text(L"Выберите режим игры", Resources::getSansation(), 30);
    infoLabel->setPosition(100, 0);
    infoLabel->setColor(sf::Color::Black);

}

GameModeMenu::~GameModeMenu()
{
    std::cout << "GameModeMenu deleted";
}

void GameModeMenu::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    target.draw(*firstMode);
    target.draw(*secondMode);
    target.draw(*thirdMode);
    target.draw(*infoLabel);
}
