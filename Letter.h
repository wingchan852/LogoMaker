//
// Created by Wing Yin Chan on 29/9/2021.
//

#ifndef TYPINGSFML_LETTER_H
#define TYPINGSFML_LETTER_H
#include <SFML/Graphics.hpp>
#include "Fonts.h"
#include "States.h"
class Letter : public sf::Text{
public:
    Letter();
    Letter(std::string string);
    bool operator==(const Letter& letter);
};


#endif //TYPINGSFML_LETTER_H
