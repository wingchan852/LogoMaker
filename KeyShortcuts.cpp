//
// Created by Wing Yin Chan on 10/10/2021.
//

#include "KeyShortcuts.h"

bool KeyShortcuts::isUndo()
{
    return((sf::Keyboard::isKeyPressed(sf::Keyboard::LControl) || sf::Keyboard::isKeyPressed(sf::Keyboard::RControl)||
        sf::Keyboard::isKeyPressed(sf::Keyboard::LSystem) || sf::Keyboard::isKeyPressed(sf::Keyboard::RSystem))
        && sf::Keyboard::isKeyPressed(sf::Keyboard::Z));
}