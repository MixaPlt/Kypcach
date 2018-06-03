#ifndef IMAGEBUTTON_H
#define IMAGEBUTTON_H
#include <SFML/Graphics.hpp>
#include <Resources.hpp>
#include <Events.hpp>
#include <MenuButton.hpp>

class ImageButton : public MenuButton
{
    public:
        ImageButton(const sf::Vector2f& size, const sf::Vector2f& position, std::string texture_path = "");
        ImageButton(const sf::Vector2f& size);
        virtual ~ImageButton();
        void setTexture(std::string texture_path);
        void setTexture(sf::Texture& texture);
    protected:

    private:
        sf::Texture texture;
};

#endif // IMAGEBUTTON_H
