#include "Levels.h"

const unsigned int Levels::levelsNumber[3] = {5, 1, 1};

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
                return Level(5, 5, 5, &m0l0);
                break;
            case 1:
                return Level(6, 6, 5, &m0l1);
                break;
            case 2:
                return Level(6, 6, 5, &m0l2);
                break;
            case 3:
                return Level(6, 6, 5, &m0l3);
                break;
            case 4:
                return Level(6, 6, 5, &m0l4);
                break;
        }
    }
    if(mode == 1)
    {
        switch(number)
        {
            case 0:
                return Level(14, 14, 8, &m1l0);
                break;
        }
    }
    if(mode == 2)
    {
        switch(number)
        {
            case 0:
                return Level(7, 7, 6, &m2l0);
                break;
        }
    }
}

std::string Levels::m0l0(sf::Vector2u from)
{
    return std::to_string(from.x);
}
std::string Levels::m1l0(sf::Vector2u from)
{
    if(from.x == 13 && from.y == 13)
        return "0";
    std::cout << int('A') + from.x + from.y << ' ' << int('A') << ' ' << char(67) << "\n";
    std::string ans = "";
    ans += char(int('A') + from.x + from.y);
    return ans;
}
std::string Levels::m2l0(sf::Vector2u from)
{
    std::string ans = "";
    ans += char((from.x * from.y) % 26 + 'A');
    return ans;
}

std::string Levels::m0l1(sf::Vector2u from)
{
    return std::to_string(5 - from.y);
}

std::string Levels::m0l2(sf::Vector2u from)
{
    return std::to_string(from.y * 6 + from.x);
}

std::string Levels::m0l3(sf::Vector2u from)
{
    return std::to_string((from.y / 2) * 3 + (from.x / 2));
}

std::string Levels::m0l4(sf::Vector2u from)
{
    return std::to_string((from.y + 1) / (from.x + 1));
}
