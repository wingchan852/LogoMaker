//
// Created by Wing Yin Chan on 7/10/2021.
//

#include "Cursor.h"

Cursor::Cursor()
{
    cursor.setFont(Fonts::getFont(Fonts::OPENSANS));
    cursor.setFillColor(sf::Color::White);
    cursor.setString("|");
    cursor.setStyle(sf::Text::Bold);
    enableState(HIDDEN);
    cursor.setCharacterSize(70);
}



void Cursor::draw(sf::RenderTarget& window, sf::RenderStates states) const
{
    if(!checkState(HIDDEN))
    {
        window.draw(cursor);
    }
}
void Cursor::addEventHandler(sf::RenderWindow& window, sf::Event event)
{

}
void Cursor::update()
{
    if(checkState(BLINKING))
    {
        if(clock.getElapsedTime().asSeconds() > 0.5 && clock.getElapsedTime().asSeconds() < 1)
        {
            cursor.setFillColor(sf::Color::Transparent);
        }else if( clock.getElapsedTime().asSeconds() > 1)
        {
            cursor.setFillColor(sf::Color::White);
            clock.restart();
        }
    }

}
Snapshot& Cursor::getSnapshot()
{

}
void Cursor::applySnapshot(const Snapshot& snapshot)
{

}

void Cursor::setCharacterSize(int size)
{
    cursor.setCharacterSize(size);
}

void Cursor::setPosition(float x, float y)
{
    cursor.setPosition(x,y);
}

sf::FloatRect Cursor::getGlobalBounds() const {
    return cursor.getGlobalBounds();
}

sf::Vector2f Cursor::getPosition() const{
    return cursor.getPosition();
}

