#include "ImageButton.hpp"
#include <iostream>

ImageButton::ImageButton(const sf::Vector2f& _size, const sf::Vector2f& _position, std::string texture_path)
    : MenuButton("", _size, _position)
{
    out_color = sf::Color(5, 5, 5, 5);
    over_color = sf::Color(255, 255, 255, 100);
    rectshape.setFillColor(out_color);
    rectshape.setOutlineThickness(0.f);
    if(texture_path.length())
        setTexture(texture_path);
}

ImageButton::ImageButton(const sf::Vector2f& _size)
    : MenuButton("", _size, sf::Vector2f(0, 0))
{

}

ImageButton::~ImageButton()
{
    //dtor
}

void ImageButton::setTexture(std::string texture_path)
{
    texture.loadFromFile(texture_path);
    rectshape.setTexture(&texture, 1);
}

void ImageButton::setTexture(sf::Texture& texture)
{
    rectshape.setTexture(&texture, 1);
}
