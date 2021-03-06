#include "Level.h"

Level::Level(int _height, int _width, int _testsNumber, std::string (*_alg)(sf::Vector2u point), int _score)
    :fieldHeight(_height),
    fieldWidth(_width),
    alg(_alg),
    testsNumber(_testsNumber),
    score(_score)
{

}

Level::~Level()
{

}

std::string Level::step(sf::Vector2u from)
{
    return (*alg)(from);
}
