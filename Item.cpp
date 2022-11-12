//
// Created by Wing Yin Chan on 19/10/2021.
//

#include "Item.h"
#include <iostream>
Item::Item() : Item("default")
{

}

Item::Item(std::string string)
{
    padding = 270;
    height = 30;
    text.setFont(Fonts::getFont(Fonts::OPENSANS));
    text.setString(string);

    box.setFillColor(sf::Color::Transparent);
    box.setOutlineColor(sf::Color::White);
//    box.setOutlineThickness(2);
//    text.setCharacterSize(30);
    initialSize = 30;
    newSize = 30 + 5;
    text.setFillColor(sf::Color::White);
//    box.setSize({300 + padding, text.getGlobalBounds().height + text.getCharacterSize()});
    box.setSize({padding + text.getGlobalBounds().width, height + static_cast<float>(text.getCharacterSize())});
//    box.setPosition(0,0);
    widthRatio = padding/text.getCharacterSize();
    heightRatio = height/text.getCharacterSize();

}
void Item::setString(std::string string)
{
    text.setString(string);
}

void Item::setPosition(float x, float y)
{
    box.setPosition(x, y);
    setTextCenter();
}

void Item::addEventHandler(sf::RenderWindow &window, sf::Event event)
{
    if(MouseEvents<sf::RectangleShape>::hovered(box, window))
        enableState(HOVERED);
    else
        disableState(HOVERED);
    if(MouseEvents<sf::RectangleShape>::mouseClicked(box, window))
        enableState(CLICKED);
    else
        disableState(CLICKED);
}

void Item::update()
{
    if(checkState(HOVERED))
    {
        box.setFillColor(sf::Color::Blue);
        text.setCharacterSize(newSize);
        setTextCenter();
    } else
    {
        box.setFillColor(sf::Color::Black);
        text.setCharacterSize(initialSize);
        setTextCenter();
    }
}

void Item::draw(sf::RenderTarget &window, sf::RenderStates states) const
{
    if(!checkState(HIDDEN))
    {
        window.draw(box);
        window.draw(text);
    }

}

Snapshot &Item::getSnapshot()
{

}

void Item::applySnapshot(const Snapshot &snapshot)
{

}

void Item::setSize(int size)
{
    text.setCharacterSize(size);
    initialSize = size;
    newSize = size + 5;
    padding = widthRatio * text.getCharacterSize();
    height = heightRatio * text.getCharacterSize();
    box.setSize({text.getGlobalBounds().width + padding, (float)height + static_cast<float>(text.getCharacterSize())});
    setTextCenter();
//    box.setSize({300 + padding, text.getGlobalBounds().height + text.getCharacterSize()});
}


sf::FloatRect Item::getGlobalBounds() const
{
    return box.getGlobalBounds();
}

sf::Vector2f Item::getPosition() const
{
    return box.getPosition();
}

void Item::setCharacterSize(int size)
{
    text.setCharacterSize(size);
}

void Item::setBoxColor(sf::Color color)
{
    box.setFillColor(color);
}

int Item::getCharacterSize()
{
    return text.getCharacterSize();
}

std::string Item::getString()
{
    return text.getString();
}

void Item::setOutlineThickness(int size)
{
    box.setOutlineThickness(size);
}

void Item::setOutlineColor(sf::Color color)
{
    box.setOutlineColor(color);
}

void Item::setTextCenter()
{
    text.setPosition(box.getGlobalBounds().left + box.getGlobalBounds().width/2 - text.getGlobalBounds().width/2, box.getGlobalBounds().top + box.getGlobalBounds().height/2 - text.getGlobalBounds().height/2);
}

void Item::setBoxSize(sf::Vector2f size)
{
    box.setSize(size);
}

sf::Vector2f Item::getBoxSize() const {
    return box.getSize();
}

void Item::setWidth(int width)
{
    padding = width;
    box.setSize({padding + text.getGlobalBounds().width, height + static_cast<float>(text.getCharacterSize())});
}

sf::FloatRect Item::getTextGlobalBounds() {
    return text.getGlobalBounds();
}

void Item::setTextPosition(sf::Vector2f position)
{
    text.setPosition(position);
}



