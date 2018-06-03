#ifndef MAINMENU_H
#define MAINMENU_H
#include <MenuButton.hpp>
#include <SFML/Graphics.hpp>
#include <Resources.hpp>
#include <Events.hpp>
#include <GameModeMenu.h>

class MainMenu : public sf::Drawable
{
    public:
        MainMenu();
        virtual ~MainMenu();
        void update();
    protected:

    private:
        void draw(sf::RenderTarget& target, sf::RenderStates states) const;
        MenuButton* playButton;
        MenuButton* settingButton;
        MenuButton* techButton;
        MenuButton* exitButton;
        void play(MenuButton* sender);
        void settings(MenuButton* sender);
        void tech(MenuButton* sender);
        void exit(MenuButton* sender);
};

#endif // MAINMENU_H
