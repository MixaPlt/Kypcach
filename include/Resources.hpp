#ifndef RESOURCES_H
#define RESOURCES_H
#include <SFML/Graphics.hpp>
#include <Events.hpp>

class Resources
{
    public:
        Resources();
        virtual ~Resources();

        static bool unload();
        static sf::Font& getSansation();
        static sf::RenderWindow& mainWindow();
        static event updater;
        static sf::Clock clock;
        static sf::Time mouseLeftDown;
        static sf::Time mouseLeftUp;

    protected:

    private:
        static sf::Font* sansation;
        static sf::RenderWindow _mainWindow;
};

#endif // RESOURCES_H
