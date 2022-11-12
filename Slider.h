//
// Created by Wing Yin Chan on 17/11/2021.
//

#ifndef TYPINGSFML_SLIDER_H
#define TYPINGSFML_SLIDER_H
#include <SFML/Graphics.hpp>
#include "GUI_Component.h"
#include "Label.h"
#include "MouseEvents.h"
#include "History.h"
class Slider : public GUI_Component{
public:
    Slider();
    Slider(std::string label, float length, sf::Vector2f position, float startingPoint);
    void setPosition(sf::Vector2f position);
    void setStartingPoint(float x);
    int getValue() const;
    void setValue(int value);
    void setValue(std::string value);

    virtual void draw(sf::RenderTarget& window, sf::RenderStates states) const;
    virtual void addEventHandler(sf::RenderWindow& window, sf::Event event);
    virtual void update();
    virtual Snapshot& getSnapshot();
    virtual void applySnapshot(const Snapshot& snapshot);
private:
    sf::RectangleShape line;
    sf::CircleShape knob;
    Label value;
    Label label;
    int number;
    Snapshot snapshot;
};


#endif //TYPINGSFML_SLIDER_H
