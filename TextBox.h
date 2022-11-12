//
// Created by Wing Yin Chan on 6/10/2021.
//

#ifndef TYPINGSFML_TEXTBOX_H
#define TYPINGSFML_TEXTBOX_H

#include <SFML/Graphics.hpp>
#include "GUI_Component.h"
#include "MouseEvents.h"
class TextBox : public GUI_Component{
public:
    TextBox();
    TextBox(sf::Vector2f size, sf::Color color);
    virtual void draw(sf::RenderTarget& window, sf::RenderStates states) const;
    virtual void addEventHandler(sf::RenderWindow& window, sf::Event event);
    virtual void update();
    virtual Snapshot& getSnapshot();
    virtual void applySnapshot(const Snapshot& snapshot);
    void setPosition(float x, float y);
    void setSize(sf::Vector2f size);
    sf::Vector2f getSize() const;
    sf::Vector2f getPosition() const;
    sf::FloatRect getGlobalBounds() const;
    void setOutlineColor(sf::Color color);
    void setOutlineThickness(int size);
private:
    sf::RectangleShape textBox;
};


#endif //TYPINGSFML_TEXTBOX_H
