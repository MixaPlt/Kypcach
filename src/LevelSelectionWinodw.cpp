#include "LevelSelectionWinodw.h"

LevelSelectionWindow::LevelSelectionWindow(const unsigned short& _mode)
    : mode(_mode),
    levelsNumber(Levels::levelsNumber[_mode])
{
    backButton = new MenuButton(L"Назад", sf::Vector2f(150, 50), sf::Vector2f(0, 550));
    backButton->OnClick.add(this, &LevelSelectionWindow::back);

    levelButtons.resize(levelsNumber);

    for(int i = 0; i < levelsNumber; i++)
    {
        levelButtons[i] = new ImageButton(sf::Vector2f(115, 115));
        levelButtons[i]->setContent(std::to_string(i + 1));
        levelButtons[i]->setOutColor(sf::Color(150, 255, 150, 255));
        levelButtons[i]->setOverColor(sf::Color(100, 255, 100, 255));
        levelButtons[i]->setPosition(sf::Vector2f(5 + 125 * (i % 4), 100 + 125 * (i / 4)));
        levelButtons[i]->MouseEnter.add(this, &LevelSelectionWindow::levelButtonMouseEnter);
        levelButtons[i]->setMouseOverResize(sf::Vector2f(10, 10));
        levelButtons[i]->id = i;
        levelButtons[i]->OnClick.add(this, &LevelSelectionWindow::levelSelected);
    }

    infoLabel = new sf::Text(L"Выберите уровень", Resources::getSansation(), 40);
    infoLabel->setPosition(sf::Vector2f(70, 15));
    infoLabel->setColor(sf::Color(90, 255, 90, 255));
    infoLabel->setOutlineThickness(1);
}

LevelSelectionWindow::~LevelSelectionWindow()
{
    Resources::drawSet.remove(this);
    Resources::deleteSet.add(backButton);
    for(int i = 0; i < levelsNumber; i++)
        Resources::deleteSet.add(levelButtons[i]);
    Resources::deleteSet.add(infoLabel);
}

void LevelSelectionWindow::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    target.draw(*backButton);
    for(int i = 0; i < levelsNumber; i++)
    {
        target.draw(*levelButtons[i]);
    }
    target.draw(*infoLabel);
}

void LevelSelectionWindow::back(MenuButton* sender)
{
    Resources::drawSet.remove(this);
    Resources::deleteSet.add(this);
    GameModeMenu* gameModeMenu = new GameModeMenu;
    Resources::drawSet.add(*gameModeMenu);
}

void LevelSelectionWindow::levelButtonMouseEnter(MenuButton* sender)
{

}

void LevelSelectionWindow::levelSelected(MenuButton* sender)
{
    int selected_id = sender->id;
    Resources::deleteSet.add(this);
    Game* game = new Game(mode, selected_id);
    Resources::drawSet.add(*game);
}
