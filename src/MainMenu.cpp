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
    std::cout << "MainMenu destructed\n";
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
    delete(playButton);
    delete(settingButton);
    delete(techButton);
    delete(exitButton);
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
