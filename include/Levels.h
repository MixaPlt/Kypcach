#ifndef LEVELS_H
#define LEVELS_H
#include <Level.h>
#include <string>
#include <iostream>

class Levels
{
    public:
        virtual ~Levels();

        static const unsigned int levelsNumber[3];
        static Level getLevel(int mode, int number);
    protected:

    private:
        static std::string m0l0(sf::Vector2u);
        static std::string m1l0(sf::Vector2u);
        static std::string m2l0(sf::Vector2u);
        static std::string m0l1(sf::Vector2u);
        static std::string m0l2(sf::Vector2u);
        static std::string m0l3(sf::Vector2u);
        static std::string m0l4(sf::Vector2u);
};

#endif // LEVELS_H
