//
// Created by Wing Yin Chan on 23/11/2021.
//

#ifndef TYPINGSFML_COLOROPTION_H
#define TYPINGSFML_COLOROPTION_H
#include "ColorBox.h"

class ColorOption : public GUI_Component{
public:
    ColorOption();
    void setPosition(sf::Vector2f position);
    sf::Color getSelectColor();
    sf::Color getOption();

    virtual void draw(sf::RenderTarget& window, sf::RenderStates states) const;
    virtual void addEventHandler(sf::RenderWindow& window, sf::Event event);
    virtual void update();
    virtual Snapshot& getSnapshot();
    virtual void applySnapshot(const Snapshot& snapshot);
private:
    sf::RectangleShape container;
    ColorBox red;
    ColorBox yellow;
    ColorBox green;
    ColorBox blue;
    ColorBox black;
    ColorBox white;
    ColorBox pink;
    ColorBox fluorescentBlue;
    sf::Color selectColor;
    sf::Color option;
    int padding = 10;
};


#endif //TYPINGSFML_COLOROPTION_H
