//
// Created by Wing Yin Chan on 23/11/2021.
//

#ifndef TYPINGSFML_COLORPICKER_H
#define TYPINGSFML_COLORPICKER_H
#include "ColorOption.h"
#include "ColorGradient.h"
#include "MouseEvents.h"

class ColorPicker : public GUI_Component{
public:
    ColorPicker();
    ColorPicker(sf::Color initialColor);
    void setPosition(sf::Vector2f position);
    void setOutlineColor(sf::Color color);
    sf::FloatRect getGlobalBounds() const;
    sf::Vector2f getPosition() const;
    sf::Color getColor() const;
    void setColor(std::string color);
    void setColor(sf::Color color);

    virtual void draw(sf::RenderTarget& window, sf::RenderStates states) const;
    virtual void addEventHandler(sf::RenderWindow& window, sf::Event event);
    virtual void update();
    virtual Snapshot& getSnapshot();
    virtual void applySnapshot(const Snapshot& snapshot);
private:
    ColorOption colorOption;
    ColorBox selectColor;
    ColorGradient colorGradient;
    int convertToHeu(sf::Color color);
};


#endif //TYPINGSFML_COLORPICKER_H
