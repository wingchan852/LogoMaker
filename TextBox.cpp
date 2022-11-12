//
// Created by Wing Yin Chan on 6/10/2021.
//

#include "TextBox.h"

TextBox::TextBox()
{
    textBox.setSize({1200,100});
    textBox.setFillColor(sf::Color::Transparent);
    textBox.setOutlineColor(sf::Color::White);
    textBox.setOutlineThickness(5);
}

TextBox::TextBox(sf::Vector2f size, sf::Color color)
{
    textBox.setSize(size);
    textBox.setFillColor(color);
}

void TextBox::draw(sf::RenderTarget &window, sf::RenderStates states) const
{
    if(!checkState(HIDDEN))
        window.draw(textBox);
}

void TextBox::addEventHandler(sf::RenderWindow &window, sf::Event event) {
    if(MouseEvents<sf::RectangleShape>::mouseClicked(textBox, window))
    {
        enableState(CLICKED);
    } else if(MouseEvents<sf::RectangleShape>::mouseClicked(window, event))
        disableState(CLICKED);
}

void TextBox::update()
{

}

Snapshot &TextBox::getSnapshot()
{

}

void TextBox::applySnapshot(const Snapshot &snapshot) {

}

void TextBox::setPosition(float x, float y)
{
    textBox.setPosition(x,y);
}

void TextBox::setSize(sf::Vector2f size)
{
    textBox.setSize(size);
}

sf::FloatRect TextBox::getGlobalBounds() const
{
    return textBox.getGlobalBounds();
}

sf::Vector2f TextBox::getPosition() const
{
    return textBox.getPosition();
}

sf::Vector2f TextBox::getSize() const
{
    return textBox.getSize();
}

void TextBox::setOutlineColor(sf::Color color)
{
    textBox.setOutlineColor(color);
}

void TextBox::setOutlineThickness(int size)
{
    textBox.setOutlineThickness(size);
}


