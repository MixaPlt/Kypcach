#ifndef LEVEL_H
#define LEVEL_H
#include <SFML/Graphics.hpp>

class Level
{
    public:
        Level();
        virtual ~Level();

        sf::Vector2u (*alg)(sf::Vector2u point);
        unsigned short height, width;

    protected:

    private:
};

#endif // LEVEL_H
