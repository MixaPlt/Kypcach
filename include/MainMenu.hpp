#ifndef MAINMENU_H
#define MAINMENU_H
#include <MenuButton.hpp>
#include <SFML/Graphics.hpp>
#include "Resources.hpp"
#include "Events.hpp"

class MainMenu : public sf::Drawable
{
    public:
        MainMenu();
        virtual ~MainMenu();
        void update();
    protected:

    private:
        void draw(sf::RenderTarget& target, sf::RenderStates states) const;
        MenuButton playButton;
        MenuButton settingButton;
        MenuButton techButton;
        MenuButton exitButton;
        /*void play();
        void settings();
        void tech();*/
        void exit();
};

#endif // MAINMENU_H
