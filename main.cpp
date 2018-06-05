#include <SFML/Graphics.hpp>
#include "MenuButton.hpp"
#include "Resources.hpp"
#include <functional>
#include <MainMenu.hpp>
#include <iostream>
#include <ImageButton.hpp>

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

		if (event.type == sf::Event::TextEntered)
        {
            Resources::keyPressed.call();
            int code = event.text.unicode;
            if(code >= 'a' && code <= 'z')
                code += 'A' - 'a';
            if (code >= '0' && code <= '9'  || code >= 'A' && code <= 'Z')
            {
                char str[1] = {'a'};
                str[0] = char(code);
                Resources::entered_text = str;
                Resources::textEntered.call(str);
            }
        }
	}
}

int main()
{
    srand( time( 0 ) );
    sf::RenderWindow& window(Resources::mainWindow());
    sf::Color background_color(150, 200, 200, 255);
    Resources::unload();
//!-------------------------------------------------------------------------


    ImageButton img(sf::Vector2f(100, 100), sf::Vector2f(200, 400), "resources/texture.png");

    MainMenu* mainMenu = new MainMenu();
    Resources::drawSet.add(*mainMenu);

    while (window.isOpen())
    {
        pollEvents(window);
        Resources::updater.call();
        window.clear(background_color);
        Resources::drawSet.draw(window);
        window.draw(img);

        window.display();
        Resources::deleteSet.call();
    }

    return 0;
}
