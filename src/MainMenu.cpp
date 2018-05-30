#include "MainMenu.hpp"
#include <iostream>

MainMenu::MainMenu()

{
    playButton = new MenuButton(L"Играть", sf::Vector2f(300, 100), sf::Vector2f(100, 100));
    settingButton = new MenuButton(L"Настройки", sf::Vector2f(300, 100), sf::Vector2f(100, 200));
    techButton = new MenuButton(L"Правила", sf::Vector2f(300, 100), sf::Vector2f(100, 300));
    exitButton = new MenuButton(L"Выход", sf::Vector2f(300, 100), sf::Vector2f(100, 400));

    playButton->OnClick.add(this, &MainMenu::play);

    exitButton->OnClick.add(this, &MainMenu::exit);
}

void MainMenu::update()
{

}

MainMenu::~MainMenu()
{
    std::cout << "MainMenu deleted";
}

void MainMenu::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    target.draw(*playButton);
    target.draw(*settingButton);
    target.draw(*techButton);
    target.draw(*exitButton);
}

void MainMenu::play()
{
    Resources::drawSet.remove(this);
    Resources::deleteSet.add (playButton);
    Resources::deleteSet.add (settingButton);
    Resources::deleteSet.add (techButton);
    Resources::deleteSet.add (exitButton);
    Resources::deleteSet.add (this);

    GameModeMenu* gameModeMenu = new GameModeMenu();
    Resources::drawSet.add(*gameModeMenu);
}

void MainMenu::settings()
{

}

void MainMenu::tech()
{

}

void MainMenu::exit()
{
    Resources::mainWindow().close();
}
