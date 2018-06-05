#ifndef LEVELS_H
#define LEVELS_H
#include <Level.h>
#include <string>

class Levels
{
    public:
        virtual ~Levels();

        static const unsigned int levelsNumber[3];
        static Level getLevel(int mode, int number);
    protected:

    private:
        static std::string m0l0(sf::Vector2u);
};

#endif // LEVELS_H
