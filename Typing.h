//
// Created by Wing Yin Chan on 22/9/2021.
//

#ifndef TYPINGSFML_TYPING_H
#define TYPINGSFML_TYPING_H
#include <SFML/Graphics.hpp>
#include "Fonts.h"
class Typing : public sf::Drawable{
public:
    Typing();
    void addEventHandler(sf::RenderWindow& window, sf::Event event);
    void update();
    virtual void draw(sf::RenderTarget& window, sf::RenderStates states) const;
private:
    sf::Text text;
    std::string string;
};


#endif //TYPINGSFML_TYPING_H
