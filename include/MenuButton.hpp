#ifndef MENUBUTTON_H
#define MENUBUTTON_H
#include <SFML/Graphics.hpp>
#include "Resources.hpp"
#include "Events.hpp"

class MenuButton : public sf::Drawable
{
    public:
        MenuButton(const sf::String& content, const sf::Vector2f& size, const sf::Vector2f& position);
        virtual ~MenuButton();

        void setContent(sf::String content);
        void setSize(const sf::Vector2f &size);
        void setFontSize(unsigned int size);
        void setPosition(const sf::Vector2f &position);
        bool isMouseOver() const;
        void update();
        event MouseEnter;
        event MouseLeave;
        event OnClick;

    protected:

    private:
        sf::RectangleShape rectshape;
        sf::Text text;
        sf::Vector2f position;
        sf::Vector2f size;
        unsigned int fontSize;
        sf::Color out_color;
        sf::Color over_color;
        sf::Color font_color;
        void draw(sf::RenderTarget& target, sf::RenderStates states) const;
        void mouseEnter();
        void mouseLeave();
        void onClick();
        bool mouseOver;
        delegate_void* upid;
        sf::Time clickTime;
        sf::Time overTime;
};

#endif // MENUBUTTON_H
