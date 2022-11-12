//
// Created by Wing Yin Chan on 19/10/2021.
//

#include "InputBox.h"
InputBox::InputBox()
{

}
void InputBox::addEventHandler(sf::RenderWindow &window, sf::Event event)
{

}

void InputBox::update()
{

}

void InputBox::draw(sf::RenderTarget &window, sf::RenderStates states) const
{
    if(!checkState(HIDDEN))
        window.draw(inputBox);
}

Snapshot &InputBox::getSnapshot()
{

}

void InputBox::applySnapshot(const Snapshot &snapshot)
{

}

void InputBox::setString(std::string string)
{
    inputBox.setString(string);
}

void InputBox::setSize(int size)
{
    inputBox.setSize(size);
}

void InputBox::setPosition(float x, float y)
{
    inputBox.setPosition(x,y);
}

sf::Vector2f InputBox::getPosition() const
{
    return inputBox.getPosition();
}

sf::FloatRect InputBox::getGlobalBounds() const
{
    return inputBox.getGlobalBounds();
}

void InputBox::setOutlineThickness(int size)
{
    inputBox.setOutlineThickness(size);
}

void InputBox::setOutlineColor(sf::Color color)
{
    inputBox.setOutlineColor(color);
}

void InputBox::setTextCenter()
{
    inputBox.setTextCenter();
}

void InputBox::setBoxSize(sf::Vector2f size)
{
    inputBox.setBoxSize(size);
}

std::string InputBox::getString()
{
    return inputBox.getString();
}

