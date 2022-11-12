//
// Created by Wing Yin Chan on 23/11/2021.
//

#include "ColorOption.h"

ColorOption::ColorOption() :
red({70,70}, sf::Color::Red, {70,70}),
black({70,70}, sf::Color::Black, {140,70}),
yellow({70,70}, sf::Color::Yellow, {210,70}),
green({70,70}, sf::Color::Green, {280,70}),
pink({70,70}, sf::Color(255,0,255), {70,140}),
blue({70,70}, sf::Color::Blue, {140,140}),
white({70,70}, sf::Color::White, {210,140}),
fluorescentBlue({70,70}, sf::Color(21,244, 238), {280, 140})
{
    container.setSize({280 + (float)padding * 5, 140 + (float)padding * 3});
    container.setFillColor(sf::Color::White);
    setPosition({400, 400});
}

void ColorOption::draw(sf::RenderTarget &window, sf::RenderStates states) const
{
    window.draw(container);
    window.draw(red);
    window.draw(black);
    window.draw(yellow);
    window.draw(green);
    window.draw(blue);
    window.draw(fluorescentBlue);
    window.draw(pink);
    window.draw(white);
}

void ColorOption::addEventHandler(sf::RenderWindow &window, sf::Event event)
{
    red.addEventHandler(window, event);
    black.addEventHandler(window, event);
    yellow.addEventHandler(window, event);
    green.addEventHandler(window, event);
    blue.addEventHandler(window, event);
    fluorescentBlue.addEventHandler(window, event);
    pink.addEventHandler(window, event);
    white.addEventHandler(window, event);
//
//    if(MouseEvents<sf::RectangleShape>::mouseClicked(container, window))
//    {
//        enableState(CLICKED);
//    } else if (MouseEvents<sf::RectangleShape>::mouseClicked(window, event))
//    {
//        disableState(CLICKED);
//    }
}

void ColorOption::update() {
    if(red.checkState(CLICKED) )
    {
        selectColor = red.getColor();
        option = red.getColor();
        enableState(CLICKED);
    }
    else if(black.checkState(CLICKED))
    {
        option = black.getColor();
        selectColor = black.getColor();
        enableState(CLICKED);
    }
    else if(yellow.checkState(CLICKED))
    {
        option = yellow.getColor();
        selectColor = yellow.getColor();
        enableState(CLICKED);
    }
    else if(green.checkState(CLICKED))
    {
        option = green.getColor();
        selectColor = green.getColor();
        enableState(CLICKED);
    }
    else if(blue.checkState(CLICKED))
    {
        option = blue.getColor();
        selectColor = blue.getColor();
        enableState(CLICKED);
    }
    else if(fluorescentBlue.checkState(CLICKED))
    {
        option = fluorescentBlue.getColor();
        selectColor = fluorescentBlue.getColor();
        enableState(CLICKED);
    }
    else if(pink.checkState(CLICKED))
    {
        option = pink.getColor();
        selectColor = pink.getColor();
        enableState(CLICKED);
    }
    else if(white.checkState(CLICKED))
    {
        option = white.getColor();
        selectColor = white.getColor();
        enableState(CLICKED);
    } else
        disableState(CLICKED);
}

Snapshot &ColorOption::getSnapshot() {

}

void ColorOption::applySnapshot(const Snapshot &snapshot) {

}

void ColorOption::setPosition(sf::Vector2f position)
{
    container.setPosition(position);
    red.setPosition({position.x + padding, position.y + padding});
    pink.setPosition({padding + position.x + padding + pink.getSize().x, position.y + padding});
    yellow.setPosition({pink.getPosition().x + yellow.getSize().x + padding, position.y + padding});
    green.setPosition({yellow.getPosition().x + green.getSize().x + padding, position.y + padding});
    blue.setPosition({ position.x + padding, position.y + blue.getSize().y + padding + padding});
    fluorescentBlue.setPosition({blue.getPosition().x + fluorescentBlue.getSize().x + padding, blue.getPosition().y });
    black.setPosition({fluorescentBlue.getPosition().x + black.getSize().x + padding, blue.getPosition().y });
    white.setPosition({black.getPosition().x + white.getSize().x + padding, blue.getPosition().y});

}

sf::Color ColorOption::getSelectColor()
{
    return selectColor;
}

sf::Color ColorOption::getOption() {
    return option;
}
