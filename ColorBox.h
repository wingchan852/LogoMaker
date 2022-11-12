//
// Created by Wing Yin Chan on 23/11/2021.
//

#ifndef TYPINGSFML_COLORBOX_H
#define TYPINGSFML_COLORBOX_H
#include <SFML/Graphics.hpp>
#include "GUI_Component.h"
#include "MouseEvents.h"
class ColorBox : public GUI_Component{
public:
    ColorBox();
    ColorBox(sf::Vector2f size, sf::Color color, sf::Vector2f position);
    void setColor(sf::Color color);
    void setPosition(sf::Vector2f position);
    void setSize(sf::Vector2f size);
    void setOutlineColor(sf::Color color);
    sf::Color getColor() const;
    sf::Vector2f getSize() const;
    sf::Vector2f getPosition() const;
    sf::FloatRect getGlobalBounds() const;

    virtual void draw(sf::RenderTarget& window, sf::RenderStates states) const;
    virtual void addEventHandler(sf::RenderWindow& window, sf::Event event);
    virtual void update();
    virtual Snapshot& getSnapshot();
    virtual void applySnapshot(const Snapshot& snapshot);
private:
    sf::RectangleShape box;
};


#endif //TYPINGSFML_COLORBOX_H
