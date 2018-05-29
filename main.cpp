#include <SFML/Graphics.hpp>
#include "MenuButton.hpp"
#include "Resources.hpp"
#include <functional>
#include <MainMenu.hpp>

int main()
{
    sf::RenderWindow& window(Resources::mainWindow());
    sf::Color background_color(150, 200, 200, 255);
    if(Resources::unload())
        return 1;
//!-------------------------------------------------------------------------

    MainMenu mainMenu;

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        Resources::updater.call();
        window.clear(background_color);
        window.draw(mainMenu);
        window.display();
    }

    return 0;
}
