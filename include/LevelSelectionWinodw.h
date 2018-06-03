#ifndef LEVELSELECTIONWINODW_H
#define LEVELSELECTIONWINODW_H
#include <ImageButton.hpp>
#include <SFML/Graphics.hpp>
#include <Resources.hpp>
#include <Events.hpp>
#include <Levels.h>
#include <MenuButton.hpp>
#include <ImageButton.hpp>
#include <GameModeMenu.h>
#include <vector>
#include <string>

class LevelSelectionWindow : public sf::Drawable
{
    public:
        LevelSelectionWindow(const unsigned short& mode);
        virtual ~LevelSelectionWindow();

    protected:

    private:
        void draw(sf::RenderTarget& target, sf::RenderStates states) const;
        unsigned short mode;
        unsigned int levelsNumber;
        MenuButton* backButton;
        std::vector<ImageButton*> levelButtons;
        void back(MenuButton* sender);
        void levelButtonMouseEnter(MenuButton* sender);
        int overButton;
        sf::Text* infoLabel;
};

#endif // LEVELSELECTIONWINODW_H
