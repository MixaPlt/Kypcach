#include "Levels.h"

const unsigned int Levels::levelsNumber[3] = {10, 0, 0};

Levels::~Levels()
{

}

Level Levels::getLevel(int mode, int number)
{
    if(!mode)
    {
        switch(number)
        {
            case 0:
                return Level(5, 5, 2, &m0l0);
                break;
        }
    }
    if(mode == 1)
    {

    }
    if(mode == 2)
    {

    }
}

std::string Levels::m0l0(sf::Vector2u from)
{
    return std::to_string(from.x);
}
