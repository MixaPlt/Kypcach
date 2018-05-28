#include <SFML/Graphics.hpp>
#include "MenuButton.hpp"
#include "Resources.hpp"
#include <functional>

int main()
{
    sf::RenderWindow& window(Resources::mainWindow());
    if(Resources::unload())
        return 1;
//!-------------------------------------------------------------------------
    event updater;

    MenuButton button(L"Кто прочитал\nтот здохнет", sf::Vector2f(300, 100), sf::Vector2f(100, 100));
    updater.add(&button, &MenuButton::update);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        updater.call();
        window.clear();
        window.draw(button);
        window.display();
    }

    return 0;
}
