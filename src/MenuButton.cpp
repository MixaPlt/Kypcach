#include "MenuButton.hpp"
#include <iostream>

MenuButton::MenuButton(const sf::String& _content, const sf::Vector2f& _size, const sf::Vector2f& _position)
    : size(_size),
    position(_position)
{
    text.setFont(Resources::getSansation());

    out_color = sf::Color(190, 190, 190, 255);
    over_color = sf::Color(200, 200, 250, 255);
    font_color = sf::Color(50, 50, 50, 255);
    text.setFillColor(font_color);

    rectshape.setFillColor(out_color);
	text.setFont(Resources::getSansation());

	rectshape.setOutlineThickness(1);

	setContent(_content);
	setSize(_size);
	setFontSize(45);
	setPosition(_position);
	mouseOver = 0;

	upid = Resources::updater.add(this, &MenuButton::update);
}

bool MenuButton::isMouseOver() const
{

	sf::Vector2i m_position = sf::Mouse::getPosition(Resources::mainWindow());
	if (m_position.x > position.x && m_position.y > position.y && m_position.x < position.x + size.x && m_position.y < position.y + size.y)
		return 1;
	return 0;
}


void MenuButton::setContent(sf::String _content)
{
	text.setString(_content);
	text.setPosition(position + sf::Vector2f((size.x - text.getLocalBounds().width) / 2.f - fontSize * 0.075, (size.y - text.getLocalBounds().height) / 2 - fontSize * 0.3));
}

void MenuButton::setSize(const sf::Vector2f &_size)
{
	rectshape.setSize(_size);
	text.move((_size - size) / 2.f);
	size = _size;
}

void MenuButton::setFontSize(unsigned int _size)
{
	fontSize = _size;
	text.setCharacterSize(_size);
	text.setPosition(position + sf::Vector2f((size.x - text.getLocalBounds().width) / 2.f - _size * 0.075, (size.y - text.getLocalBounds().height) / 2 - _size * 0.3));
}

void MenuButton::setPosition(const sf::Vector2f &_position)
{
	rectshape.setPosition(_position);
	text.move(_position - position);
	position = _position;
}

MenuButton::~MenuButton()
{
    Resources::updater.remove(upid);
    std::cout << "Button deleted\n";
}

void MenuButton::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    target.draw(rectshape);
	target.draw(text);
}

void MenuButton::update()
{
    if(isMouseOver() != mouseOver)
    {
        mouseOver = !mouseOver;
        if(mouseOver)
            mouseEnter();
        else
            mouseLeave();
    }
    if(mouseOver && overTime < Resources::mouseLeftDown && Resources::mouseLeftDown < Resources::mouseLeftUp && clickTime < Resources::mouseLeftDown)
        onClick();
}

void MenuButton::mouseEnter()
{
    overTime = Resources::clock.getElapsedTime();
    rectshape.setFillColor(over_color);
    MouseEnter.call();
}

void MenuButton::mouseLeave()
{
    rectshape.setFillColor(out_color);
    MouseLeave.call();
}

void MenuButton::onClick()
{
    clickTime = Resources::clock.getElapsedTime();
    OnClick.call();
}
