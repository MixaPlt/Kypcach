#ifndef GAME_H
#define GAME_H
#include <MenuButton.hpp>
#include <SFML/Graphics.hpp>
#include <Resources.hpp>
#include <Events.hpp>
#include <GameModeMenu.h>
#include <vector>
#include <memory>
#include <cstring>
#include <cmath>
#include <algorithm>

class Game : public sf::Drawable
{
    public:
        Game(int mode, int levelNumber);
        virtual ~Game();

    protected:

    private:
        void draw(sf::RenderTarget& target, sf::RenderStates states) const;
        int mode;
        int levelNumber;
        Level level;
        MenuButton* backButton;
        MenuButton* readyButton;
        void back(MenuButton* sender);
        void ready(MenuButton* sender);
        float rectHeight, rectWidth;
        std::vector< std::vector< ImageButton* > > rects;
        void rectClick(MenuButton* sender);
        bool pmod;
        void textEntered(std::string text);
        void checkAlgorithm();
        int turnsNumber;
        int selectedX, selectedY;
        delegate_sender<std::string>* upidptr;
        int passedTests;
        void won();
        delegate_sender<std::string>* kprsdidptr;
        void winWait(std::string key);
        sf::Text* infoLabel;
        void lose();
        int mistakes;
        int score;
};

#endif // GAME_H
