//
// Created by Wing Yin Chan on 6/10/2021.
//

#include "Label.h"

Label::Label()
{
    label.setFont(Fonts::getFont(Fonts::OPENSANS));
    label.setString("First Name: ");
    label.setFillColor(sf::Color::White);
    label.setCharacterSize(100);
}

void Label::draw(sf::RenderTarget &window, sf::RenderStates states) const
{
    if(!checkState(HIDDEN))
        window.draw(label);
}

void Label::addEventHandler(sf::RenderWindow &window, sf::Event event) {

}

void Label::update() {

}

Snapshot &Label::getSnapshot() {

}

void Label::applySnapshot(const Snapshot &snapshot) {

}

void Label::setPosition(float x, float y)
{
    label.setPosition(x,y);
}

sf::FloatRect Label::getGlobalBounds() const
{
    return label.getGlobalBounds();
}

sf::Vector2f Label::getPosition() const
{
    return label.getPosition();
}

void Label::setString(std::string string)
{
    label.setString(string);
}

void Label::setCharacterSize(int size)
{
    label.setCharacterSize(size);
}

int Label::getCharacterSize() const
{
    return label.getCharacterSize();
}
