#ifndef RESOURCES_H
#define RESOURCES_H
#include <SFML/Graphics.hpp>

class Resources
{
    public:
        Resources();
        virtual ~Resources();

        static bool unload();
        static sf::Font& getSansation();
        static sf::RenderWindow& mainWindow();

    protected:

    private:
        static sf::Font* sansation;
        static sf::RenderWindow _mainWindow;
};

#endif // RESOURCES_H
