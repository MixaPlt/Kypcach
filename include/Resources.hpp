#ifndef RESOURCES_H
#define RESOURCES_H
#include <SFML/Graphics.hpp>
#include <Events.hpp>

struct DrawableSet
{
private:
    std::set<sf::Drawable*> ds;
public:
    void add(sf::Drawable& d)
    {
        ds.insert(&d);
    }
    void remove(sf::Drawable& d)
    {
        std::set<sf::Drawable*>::iterator it = ds.find(&d);
        if(it != ds.end())
            ds.erase(it);
    }
    void remove(sf::Drawable* d)
    {
        std::set<sf::Drawable*>::iterator it = ds.find(d);
        if(it != ds.end())
            ds.erase(it);
    }
    void draw(sf::RenderWindow& window)
    {
        for(std::set<sf::Drawable*>::iterator it = ds.begin(); it != ds.end(); it++)
            window.draw(*(*it));
    }
};

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
        static DrawableSet drawSet;

    protected:

    private:
        static sf::Font* sansation;
        static sf::RenderWindow _mainWindow;
};

#endif // RESOURCES_H
