//
// Created by Wing Yin Chan on 23/11/2021.
//

#ifndef TYPINGSFML_COLORGRADIENT_H
#define TYPINGSFML_COLORGRADIENT_H
#include <SFML/Graphics.hpp>
#include "GUI_Component.h"
class ColorGradient : public GUI_Component{
public:
    ColorGradient();
    ColorGradient(int hue, sf::Vector2i position, int size);
    void setColor(int hue);
    void setPosition(sf::Vector2i position);
    sf::Color getColor(sf::Vector2i coordinate);
    sf::FloatRect getGlobalBounds() const;

    virtual void draw(sf::RenderTarget& window, sf::RenderStates states) const;
    virtual void addEventHandler(sf::RenderWindow& window, sf::Event event);
    virtual void update();
    virtual Snapshot& getSnapshot();
    virtual void applySnapshot(const Snapshot& snapshot);
private:
    sf::VertexArray color;
    sf::Vector2i position;
    int size;
};


#endif //TYPINGSFML_COLORGRADIENT_H
