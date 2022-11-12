//
// Created by Wing Yin Chan on 29/9/2021.
//

#include "Letter.h"

Letter::Letter()
{
    this->setFont(Fonts::getFont(Fonts::OPENSANS));
    this->setFillColor(sf::Color::White);
    this->setCharacterSize(50);
    this->setPosition({0,0});

//    this->setLetterSpacing(1.5);
}


