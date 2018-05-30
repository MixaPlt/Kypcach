#ifndef GAMEMODEMENU_H
#define GAMEMODEMENU_H
#include <ImageButton.hpp>
#include <SFML/Graphics.hpp>
#include <Resources.hpp>
#include <Events.hpp>

class GameModeMenu : public sf::Drawable
{
    public:
        GameModeMenu();
        virtual ~GameModeMenu();
    private:
        void draw(sf::RenderTarget& target, sf::RenderStates states) const;
        ImageButton* firstMode;
        ImageButton* secondMode;
        ImageButton* thirdMode;
        sf::Text* infoLabel;
};

#endif // GAMEMODEMENU_H
