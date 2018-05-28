#include "Resources.hpp"

sf::Font* Resources::sansation = new sf::Font;
sf::RenderWindow Resources::_mainWindow(sf::VideoMode(800, 600), "Kypcach");

Resources::Resources()
{
    //ctor
}

Resources::~Resources()
{
    //dtor
}

sf::Font& Resources::getSansation()
{
	return *sansation;
}

bool Resources::unload()
{

	if (!sansation->loadFromFile("resources/SansationRegular.ttf"))
		return 1;
    return 0;
}

sf::RenderWindow& Resources::mainWindow()
{
    return _mainWindow;
}
