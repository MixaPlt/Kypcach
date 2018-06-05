#include "GameModeMenu.h"

GameModeMenu::GameModeMenu()
{
    firstModeButton = new ImageButton(sf::Vector2f(300, 150), sf::Vector2f(100, 75));
    secondModeButton = new ImageButton(sf::Vector2f(300, 150), sf::Vector2f(100, 225));
    thirdModeButton = new ImageButton(sf::Vector2f(300, 150), sf::Vector2f(100, 375));

    firstModeButton->setOutColor(sf::Color(255, 255, 255, 255));
    secondModeButton->setOutColor(sf::Color(255, 255, 255, 255));
    thirdModeButton->setOutColor(sf::Color(200, 200, 200, 255));

    firstModeButton->setTexture("resources/easy.jpg");
    secondModeButton->setTexture("resources/medium.jpg");
    thirdModeButton->setTexture("resources/hard.jpg");

    firstModeButton->setOutlineThickness(2);
    secondModeButton->setOutlineThickness(2);
    thirdModeButton->setOutlineThickness(2);

    infoLabel = new sf::Text(L"Выберите сложность игры", Resources::getSansation(), 30);
    infoLabel->setPosition(75, 0);
    infoLabel->setColor(sf::Color::Black);

    backButton = new MenuButton(L"Назад", sf::Vector2f(150, 50), sf::Vector2f(0, 550));
    backButton->OnClick.add(this, &GameModeMenu::back);

    firstModeButton->OnClick.add(this, &GameModeMenu::firstMode);
    secondModeButton->OnClick.add(this, &GameModeMenu::secondMode);
    thirdModeButton->OnClick.add(this, &GameModeMenu::thirdMode);

    firstModeButton->setFontColor(sf::Color(0, 255, 0, 255));
    secondModeButton->setFontColor(sf::Color(0, 0, 100, 255));
    thirdModeButton->setFontColor(sf::Color(255, 0, 0, 255));

    firstModeButton->setTextOutlineColor(sf::Color::Black);
    secondModeButton->setTextOutlineColor(sf::Color::Magenta);
    thirdModeButton->setTextOutlineColor(sf::Color::Yellow);

    firstModeButton->setTextOutlineThickness(2);
    secondModeButton->setTextOutlineThickness(2);
    thirdModeButton->setTextOutlineThickness(2);

    thirdModeButton->setFontSize(43);

    firstModeButton->setContent(L"Простой");
    secondModeButton->setContent(L"Cложный");
    thirdModeButton->setContent(L"Невозможный");
}

GameModeMenu::~GameModeMenu()
{
    Resources::deleteSet.add(firstModeButton);
    Resources::deleteSet.add(secondModeButton);
    Resources::deleteSet.add(thirdModeButton);
    Resources::deleteSet.add(backButton);
    Resources::deleteSet.add(infoLabel);
}

void GameModeMenu::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    target.draw(*firstModeButton);
    target.draw(*secondModeButton);
    target.draw(*thirdModeButton);
    target.draw(*infoLabel);
    target.draw(*backButton);
}

void GameModeMenu::back(MenuButton* sender)
{
    Resources::drawSet.remove(this);
    Resources::deleteSet.add(this);
    MainMenu* mainMenu = new MainMenu;
    Resources::drawSet.add(*mainMenu);
}

void GameModeMenu::firstMode(MenuButton* sender)
{
    Resources::drawSet.remove(this);
    Resources::deleteSet.add(this);
    LevelSelectionWindow* levelSelectionWindow = new LevelSelectionWindow(0);
    Resources::drawSet.add(*levelSelectionWindow);
}

void GameModeMenu::secondMode(MenuButton* sender)
{
    Resources::drawSet.remove(this);
    Resources::deleteSet.add(this);
    LevelSelectionWindow* levelSelectionWindow = new LevelSelectionWindow(1);
    Resources::drawSet.add(*levelSelectionWindow);
}

void GameModeMenu::thirdMode(MenuButton* sender)
{
    Resources::drawSet.remove(this);
    Resources::deleteSet.add(this);
    LevelSelectionWindow* levelSelectionWindow = new LevelSelectionWindow(2);
    Resources::drawSet.add(*levelSelectionWindow);
}
