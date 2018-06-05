#include "Game.hpp"

Game::Game(int _mode, int _levelNumber)
    : mode(_mode),
    levelNumber(_levelNumber),
    level(Levels::getLevel(_mode, _levelNumber))
{
    backButton = new MenuButton(L"Сдаться", sf::Vector2f(250, 50), sf::Vector2f(0, 550));
    backButton->OnClick.add(this, &Game::back);
    readyButton = new MenuButton(L"Готов", sf::Vector2f(250, 50), sf::Vector2f(250, 550));
    readyButton->OnClick.add(this, &Game::ready);
    backButton->setFontSize(40);
    readyButton->setFontSize(40);
    backButton->setOutColor(sf::Color(100, 255, 100));
    backButton->setOverColor(sf::Color(150, 255, 150));
    readyButton->setOutColor(sf::Color(100, 255, 100));
    readyButton->setOverColor(sf::Color(150, 255, 150));

    rectHeight = 500.f / level.fieldHeight;
    rectWidth = 500.f / level.fieldWidth;
    rects.resize(level.fieldHeight);
    for(int i = 0; i < level.fieldHeight; i++)
    {
        rects[i].resize(level.fieldWidth);
        for(int j = 0; j < level.fieldWidth; j++)
        {
            rects[i][j] = new ImageButton(sf::Vector2f(rectWidth, rectHeight));
            rects[i][j]->setPosition(sf::Vector2f(j * rectWidth, i * rectHeight + 50));
            rects[i][j]->id = i * level.fieldHeight + j;
            rects[i][j]->setOutColor(sf::Color(100, 255, 255));
            rects[i][j]->setOverColor(sf::Color::Cyan);
            rects[i][j]->OnClick.add(this, &Game::rectClick);
        }
    }
    Resources::drawSet.add(*readyButton);
    pmod = 0;
    turnsNumber = 0;
    upidptr = 0;
    passedTests = 0;
    kprsdidptr = 0;
    infoLabel = new sf::Text(L"Выберите клетку", Resources::getSansation(), 40);
    infoLabel->setFillColor(sf::Color(255, 20, 20));
    infoLabel->setPosition(sf::Vector2f(100, 0));
}

Game::~Game()
{
    Resources::deleteSet.add(readyButton);
    Resources::deleteSet.add(backButton);
    Resources::textEntered.remove(upidptr);
    Resources::deleteSet.add(infoLabel);
    for(int i = 0; i < rects.size(); i++)
        for(int j = 0; j < rects[i].size(); j++)
            Resources::deleteSet.add(rects[i][j]);
}

void Game::draw(sf::RenderTarget& target, sf::RenderStates stater) const
{
    for(int i = 0; i < rects.size(); i++)
        for(int j = 0; j < rects[i].size(); j++)
            target.draw(*rects[i][j]);
    target.draw(*backButton);
    target.draw(*infoLabel);
}

void Game::back(MenuButton* sender)
{
    Resources::drawSet.remove(this);
    Resources::deleteSet.add(this);
    std::cout <<"KEK1\n";
    LevelSelectionWindow* levelSelectionWindow = new LevelSelectionWindow(mode);
    Resources::drawSet.add(*levelSelectionWindow);
}

void Game::ready(MenuButton* sender)
{
    if(!pmod)
    {
        readyButton->setContent(L"Подтвердить");
        readyButton->setFontSize(35);
        pmod = 1;
        upidptr = Resources::textEntered.add(this, &Game::textEntered);
        checkAlgorithm();
        return;
    }
    if(rects[selectedY][selectedX]->text.getString()[0] == '?')
        return;
    if(std::string(rects[selectedY][selectedX]->text.getString())[0] != level.step(sf::Vector2u(selectedX, selectedY))[0])
    {
        back(backButton);
    }
    passedTests++;
    rects[selectedY][selectedX]->id = -1;
    if(passedTests < level.testsNumber)
        checkAlgorithm();
    else
    {
        won();
    }
}

void Game::checkAlgorithm()
{
    int num = rand() % (level.fieldHeight * level.fieldWidth - turnsNumber - passedTests);
    int i;
    for(i = 0; num >= 0; i++)
        if(rects[i / level.fieldWidth][i % level.fieldWidth]->id != -1)
            num--;
    i--;
    selectedX = i % level.fieldWidth;
    selectedY = i / level.fieldWidth;
    rects[selectedY][selectedX]->setOutColor(sf::Color::Magenta);
    rects[selectedY][selectedX]->setContent("??");
}

void Game::rectClick(MenuButton* sender)
{
    if(!pmod)
    {
        if(turnsNumber + level.testsNumber == level.fieldHeight * level.fieldWidth)
            return;
        int selected_id = sender->id;
        if(selected_id == -1)
            return;
        int h = selected_id / level.fieldWidth;
        int w = selected_id % level.fieldWidth;
        sender->setContent(level.step(sf::Vector2u(w, h)));
        sender->id = -1;
        sender->setOutColor(sf::Color(250, 200, 200));
        sender->setOverColor(sf::Color(255, 220, 220));
        turnsNumber++;
        return;
    }

}

void Game::textEntered(std::string text)
{
    rects[selectedY][selectedX]->setContent(text);
}

void Game::won()
{
    kprsdidptr = Resources::keyPressed.add(this, &Game::winWait);
    infoLabel->setPosition(0, 202);
    infoLabel->setString("WINNER WINNER\nCHICKEN DINNER");
    infoLabel->setStyle(sf::Text::Bold);
    infoLabel->setCharacterSize(56);
    infoLabel->setOutlineThickness(3);
    backButton->hide();
}

void Game::winWait()
{
    Resources::keyPressed.remove(kprsdidptr);
    std::cout <<"KEK\n";
    back(backButton);
}


