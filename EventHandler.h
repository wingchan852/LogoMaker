//
// Created by Wing Yin Chan on 4/10/2021.
//

#ifndef TYPINGSFML_EVENTHANDLER_H
#define TYPINGSFML_EVENTHANDLER_H

#include <SFML/Graphics.hpp>
class EventHandler {
public:
    virtual void addEventHandler(sf::RenderWindow& window, sf::Event event) = 0;
    virtual void update() = 0;
};


#endif //TYPINGSFML_EVENTHANDLER_H
