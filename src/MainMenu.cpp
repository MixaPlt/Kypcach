#include "MainMenu.hpp"

MainMenu::MainMenu() :
    playButton(L"Играть", sf::Vector2f(300, 100), sf::Vector2f(100, 100)),
    settingButton(L"Настройки", sf::Vector2f(300, 100), sf::Vector2f(100, 200)),
    techButton(L"Правила", sf::Vector2f(300, 100), sf::Vector2f(100, 300)),
    exitButton(L"Выход", sf::Vector2f(300, 100), sf::Vector2f(100, 400))
{

}

void MainMenu::update()
{

}

MainMenu::~MainMenu()
{
    //dtor
}

void MainMenu::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    target.draw(playButton);
    target.draw(settingButton);
    target.draw(techButton);
    target.draw(exitButton);
}

void MainMenu::exit()
{
    Resources::mainWindow().close();
}
