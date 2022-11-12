//
// Created by Wing Yin Chan on 21/11/2021.
//

#include "Logo.h"
#include <iostream>
Logo::Logo()
{
    renderTexture.create(2000,700);
    logo.setFont(Fonts::getFont(Fonts::OPENSANS));
    logo.setString("");
    logo.setCharacterSize(70);
    logo.setFillColor(sf::Color::Black);
    logo.setPosition(renderTexture.getSize().x/2 ,renderTexture.getSize().y/2 );

    shadow = logo;
    shadow.setScale(1, -0.3);
//    shadow.setPosition(shadow.getPosition().x, shadow.getPosition().y );
    backgroundColor = sf::Color::White;
}

void Logo::setString(std::string string)
{
    logo.setString(string);
    shadow.setString(string);
}

void Logo::setLogoXAxis(int x)
{
    logo.setPosition(x, logo.getPosition().y);
}

void Logo::setLogoYAxis(int y)
{
    y = y/2;
    logo.setPosition(logo.getPosition().x, y);
}

void Logo::setCharacterSize(int size)
{
    logo.setCharacterSize(size);
    shadow.setCharacterSize(size);
}

void Logo::setTextOpacity(int opacity)
{
    sf::Color color = logo.getFillColor();
    color.a = opacity;
    logo.setFillColor(color);

}

void Logo::create()
{
    renderTexture.clear(backgroundColor);
    renderTexture.draw(logo);
    renderTexture.draw(shadow);
    renderTexture.display();
    sprite.setTexture(renderTexture.getTexture());
    sprite.setPosition({0,90});
}

void Logo::setBackgroundColor(sf::Color color)
{
    backgroundColor = color;
}

sf::Texture& Logo::getTexture()
{
    return const_cast<sf::Texture &>(renderTexture.getTexture());
}

void Logo::setTextColor(sf::Color color)
{
    logo.setFillColor(color);
}

//sf::RenderTexture& Logo::getTexture() {
//    return renderTexture;
//}

sf::Text &Logo::getLogo() {
    return logo;
}

sf::Sprite &Logo::getSprite() {
    return sprite;
}

sf::Text &Logo::getShadow() {
    return shadow;
}

void Logo::setShadowXAxis(int x)
{
    shadow.setPosition(x, shadow.getPosition().y);
}

void Logo::setShadowYAxis(int y)
{
    y = y/2;
    shadow.setPosition(shadow.getPosition().x, y);
}

void Logo::setSkew(double num)
{
    num = -num/100;
    shadow.setScale(1, num);
}

void Logo::setShadowOpacity(int opacity)
{
    sf::Color c = shadow.getFillColor();
    c.a = opacity;
    shadow.setFillColor(c);
}

void Logo::setFont(std::string font)
{
    if(font == "Open Sans")
    {
        logo.setFont(Fonts::getFont(Fonts::OPENSANS));
        shadow.setFont(Fonts::getFont(Fonts::OPENSANS));
    } else if(font == "Josefin Sans")
    {
        logo.setFont(Fonts::getFont(Fonts::JOSEFINSANS));
        shadow.setFont(Fonts::getFont(Fonts::JOSEFINSANS));
    } else if(font == "Marlboro")
    {
        logo.setFont(Fonts::getFont(Fonts::MARLBORO));
        shadow.setFont(Fonts::getFont(Fonts::MARLBORO));
    } else if(font == "Bebas Neue")
    {
        logo.setFont(Fonts::getFont(Fonts::BEBASNEUE));
        shadow.setFont(Fonts::getFont(Fonts::BEBASNEUE));
    }
}

void Logo::setBackgroundOpacity(int opacity)
{
    backgroundColor.a = opacity;
}

void Logo::exportImage(std::string name)
{
    renderTexture.getTexture().copyToImage().saveToFile("export/" + name);
}

void Logo::loadTexture(std::string name)
{
    texture.loadFromFile("logo/" + name);
    sprite.setTexture(texture);
}

void Logo::setBackgroundColor(int num)
{
    backgroundColor = sf::Color(num);
}

void Logo::setTextColor(int num)
{
    logo.setFillColor(sf::Color(num));
}




