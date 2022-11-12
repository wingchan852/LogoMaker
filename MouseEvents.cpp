//
// Created by Wing Yin Chan on 5/10/2021.
//

#ifndef TYPINGSFML_MOUSEEVENTS_CPP
#define TYPINGSFML_MOUSEEVENTS_CPP

#include "MouseEvents.h"
template<class T>
int MouseEvents<T>::clicks = 0;

template<class T>
sf::Clock MouseEvents<T>::clock;

template<class T>
bool MouseEvents<T>::mouseClicked(T& object, sf::RenderWindow& window)
{
    return (hovered(object, window) && sf::Mouse::isButtonPressed(sf::Mouse::Left));
}

template<class T>
bool MouseEvents<T>::mouseClicked(sf::RenderWindow &window, sf::Event event)
{
    return (sf::Mouse::isButtonPressed(sf::Mouse::Left));
}

template<class T>
bool MouseEvents<T>::mouseDoubleClicked()
{
    countClicks();
    if(clock.getElapsedTime().asSeconds() < 0.3 && clicks == 2)
    {
        return true;
    } else if( clicks >= 2 || clock.getElapsedTime().asSeconds() > 0.3 && clicks == 1)
        clicks = 0;
    return false;
}

template<class T>
bool MouseEvents<T>::mouseTripleClicked() {
    countClicks();
    if(clock.getElapsedTime().asSeconds() < 0.5 && clicks == 3)
    {
        return true;
    } else if( clicks >= 3 || clock.getElapsedTime().asSeconds() > 0.3 && clicks <= 2 )
        clicks = 0;
    return false;
}

template<class T>
bool MouseEvents<T>::draggedOver(T &object, sf::RenderWindow &window, sf::Event event)
{
    return(mouseClicked(object, window) && event.MouseMoved);
//    return true;
}

template<class T>
bool MouseEvents<T>::hovered(T &object, sf::RenderWindow &window) {
    sf::Vector2f mousePos = (sf::Vector2f) sf::Mouse::getPosition(window);
    sf::FloatRect bound = object.getGlobalBounds();
    return(bound.contains(mousePos));
}

template<class T>
void MouseEvents<T>::countClicks()
{

    if(sf::Mouse::isButtonPressed(sf::Mouse::Left) )
    {
        if(clicks == 0)
            clock.restart();
        clicks++;
    }
//    std::cout<<"Clicks: "<<clicks<<std::endl;
}
#endif