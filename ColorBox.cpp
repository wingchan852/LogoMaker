//
// Created by Wing Yin Chan on 23/11/2021.
//

#include "ColorBox.h"
ColorBox::ColorBox()
{

}

ColorBox::ColorBox(sf::Vector2f size, sf::Color color, sf::Vector2f position)
{
    box.setSize(size);
    box.setFillColor(color);
    box.setPosition(position);
    box.setOutlineColor(sf::Color::Black);
    box.setOutlineThickness(3);
}

void ColorBox::setColor(sf::Color color) {
    box.setFillColor(color);
}

void ColorBox::setPosition(sf::Vector2f position) {
    box.setPosition(position);
}

void ColorBox::setSize(sf::Vector2f size) {
    box.setSize(size);
}

sf::Color ColorBox::getColor() const {
    return box.getFillColor();
}

sf::Vector2f ColorBox::getSize() const {
    return box.getSize();
}

sf::Vector2f ColorBox::getPosition() const {
    return box.getPosition();
}

void ColorBox::draw(sf::RenderTarget &window, sf::RenderStates states) const {
    window.draw(box);
}

void ColorBox::addEventHandler(sf::RenderWindow &window, sf::Event event) {
    if(MouseEvents<sf::RectangleShape>::mouseClicked(box, window))
    {
        enableState(CLICKED);
//        std::cout<<"click"<<std::endl;
    }
    else if(MouseEvents<sf::RectangleShape>::mouseClicked(window, event))
        disableState(CLICKED);
}

void ColorBox::update() {

}

Snapshot &ColorBox::getSnapshot() {

}

void ColorBox::applySnapshot(const Snapshot &snapshot) {

}

sf::FloatRect ColorBox::getGlobalBounds() const {
    return box.getGlobalBounds();
}

void ColorBox::setOutlineColor(sf::Color color)
{
    box.setOutlineColor(color);
}
