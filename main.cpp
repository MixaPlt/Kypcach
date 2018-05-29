#include <SFML/Graphics.hpp>
#include "MenuButton.hpp"
#include "Resources.hpp"
#include <functional>
#include <MainMenu.hpp>
#include <iostream>

void pollEvents(sf::RenderWindow& window)
{
    sf::Event event;
    while (window.pollEvent(event))
	{
		if (event.type == sf::Event::Closed)
			window.close();
		if (event.type == sf::Event::MouseButtonPressed)
		{
			if (event.mouseButton.button == sf::Mouse::Left)
				Resources::mouseLeftDown = Resources::clock.getElapsedTime();
		}
		if (event.type == sf::Event::MouseButtonReleased)
		{
			if (event.mouseButton.button == sf::Mouse::Left)
				Resources::mouseLeftUp = Resources::clock.getElapsedTime();
		}
	}
}

int main()
{
    setlocale(LC_ALL, "Russian");
    std::cout << "Добро пожаловать!\n";
    sf::RenderWindow& window(Resources::mainWindow());
    sf::Color background_color(150, 200, 200, 255);
    if(Resources::unload())
        return 1;
//!-------------------------------------------------------------------------

    MainMenu mainMenu;
    Resources::drawSet.add(mainMenu);

    while (window.isOpen())
    {
        pollEvents(window);
        Resources::updater.call();
        window.clear(background_color);
        Resources::drawSet.draw(window);
        window.display();
    }

    return 0;
}
