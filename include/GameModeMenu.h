#ifndef GAMEMODEMENU_H
#define GAMEMODEMENU_H
#include <MenuButton.hpp>
#include <SFML/Graphics.hpp>
#include "Resources.hpp"
#include "Events.hpp"

class GameModeMenu : public sf::Drawable
{
    public:
        GameModeMenu();
        virtual ~GameModeMenu();
    private:
        void draw(sf::RenderTarget& target, sf::RenderStates states) const;

};

#endif // GAMEMODEMENU_H
