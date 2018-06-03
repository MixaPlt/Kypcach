#ifndef GAMEMODEMENU_H
#define GAMEMODEMENU_H
#include <ImageButton.hpp>
#include <SFML/Graphics.hpp>
#include <Resources.hpp>
#include <Events.hpp>
#include <MainMenu.hpp>
#include <LevelSelectionWinodw.h>

class GameModeMenu : public sf::Drawable
{
    public:
        GameModeMenu();
        virtual ~GameModeMenu();
    private:
        void draw(sf::RenderTarget& target, sf::RenderStates states) const;
        ImageButton* firstModeButton;
        ImageButton* secondModeButton;
        ImageButton* thirdModeButton;
        sf::Text* infoLabel;
        MenuButton* backButton;
        void back(MenuButton* sender);
        void firstMode(MenuButton* sender);
        void secondMode(MenuButton* sender);
        void thirdMode(MenuButton* sender);
};

#endif // GAMEMODEMENU_H
