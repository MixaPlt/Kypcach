#ifndef LEVEL_H
#define LEVEL_H
#include <SFML/Graphics.hpp>

class Level
{
    public:
        Level(int _mode, int _levelNumber, int _testsNumber, std::string (*alg)(sf::Vector2u point));
        virtual ~Level();
        std::string step(sf::Vector2u from);
        unsigned short fieldHeight, fieldWidth;
        unsigned int testsNumber;
    protected:

    private:

        std::string (*alg)(sf::Vector2u point);
};

#endif // LEVEL_H
