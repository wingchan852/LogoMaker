//
// Created by Wing Yin Chan on 22/9/2021.
//

#include "Typing.h"

Typing::Typing()
{
    text.setFont(Fonts::getFont(Fonts::OPENSANS));
    text.setFillColor(sf::Color::White);
    text.setCharacterSize(50);
}
void Typing::addEventHandler(sf::RenderWindow &window, sf::Event event)
{
    if(event.type == event.TextEntered)
    {
        if(event.text.unicode == 8)
            string.pop_back();
        else if(event.text.unicode <= 126)
            string += (char)event.text.unicode;
    }
    text.setString(string);
}

void Typing::update()
{

}

void Typing::draw(sf::RenderTarget &window, sf::RenderStates states) const
{
    window.draw(text);
}



