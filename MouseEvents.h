//
// Created by Wing Yin Chan on 5/10/2021.
//

#ifndef TYPINGSFML_MOUSEEVENTS_H
#define TYPINGSFML_MOUSEEVENTS_H

#include <SFML/Graphics.hpp>
#include <iostream>
template<class T>
class MouseEvents {

public:
    // returns true if the mouse clicks on the object
//    template <class T>
    static bool mouseClicked(T& object, sf::RenderWindow& window);

    // returns true if the mouse clicks anywhere in the window
    static bool mouseClicked( sf::RenderWindow& window, sf::Event event);

    // returns true if the mouse has been double clicked
    static bool mouseDoubleClicked();

//    //returns true if the mouse has been triple clicked
    static bool mouseTripleClicked();
//
//    // returns if the object has been clicked and the mouse has dragged over the object
//    template <class T>
    static bool draggedOver(T& object, sf::RenderWindow& window, sf::Event event);
//
//    // returns tru if the mouse is hovered over the object
//    template <class T>
    static bool hovered(T& object, sf::RenderWindow& window);

private:
    // this is what I used to determine if a double click or triple click occurred
    // you don't have to use this if you don't want to
    static sf::Clock clock;
    static int clicks;
    static void countClicks();
};

#include "MouseEvents.cpp"
#endif //TYPINGSFML_MOUSEEVENTS_H
