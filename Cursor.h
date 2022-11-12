//
// Created by Wing Yin Chan on 7/10/2021.
//

#ifndef TYPINGSFML_CURSOR_H
#define TYPINGSFML_CURSOR_H

#include <SFML/Graphics.hpp>
#include "GUI_Component.h"
#include "Fonts.h"

class Cursor : public GUI_Component {
public:
    Cursor();
    virtual void draw(sf::RenderTarget& window, sf::RenderStates states) const;
    virtual void addEventHandler(sf::RenderWindow& window, sf::Event event);
    virtual void update();
    virtual Snapshot& getSnapshot();
    virtual void applySnapshot(const Snapshot& snapshot);
    void setCharacterSize(int size);
    void setPosition(float x, float y);
    sf::FloatRect getGlobalBounds() const;
    sf::Vector2f getPosition() const;

private:
    sf::Clock clock;
    sf::Text cursor;
};


#endif //TYPINGSFML_CURSOR_H
