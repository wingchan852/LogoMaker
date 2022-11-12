//
// Created by Wing Yin Chan on 23/11/2021.
//

#include "ColorPicker.h"

ColorPicker::ColorPicker() : ColorPicker(sf::Color::Red)
{


}

ColorPicker::ColorPicker(sf::Color color) : selectColor({80, 80}, color, {400, 400}),
colorGradient(0, {400,400}, 470)
{
    setPosition({400, 400});
    colorOption.enableState(HIDDEN);
    colorGradient.enableState(HIDDEN);
}

void ColorPicker::setPosition(sf::Vector2f position) {
    selectColor.setPosition(position);
    colorOption.setPosition({position.x, position.y + selectColor.getSize().y});
    colorGradient.setPosition({(int)position.x, (int)position.y + (int)selectColor.getSize().y});
}

void ColorPicker::draw(sf::RenderTarget &window, sf::RenderStates states) const {

    window.draw(selectColor);
    if(!colorOption.checkState(HIDDEN))
        window.draw(colorOption);

    if(!colorGradient.checkState(HIDDEN))
        window.draw(colorGradient);
}

void ColorPicker::addEventHandler(sf::RenderWindow &window, sf::Event event)
{
    selectColor.addEventHandler(window, event);
    colorOption.addEventHandler(window, event);

    if(colorOption.checkState(CLICKED) && !colorOption.checkState(HIDDEN))
    {
        colorGradient.disableState(HIDDEN);
        colorOption.enableState(HIDDEN);
        if(colorOption.getOption() == sf::Color::White)
        {
            selectColor.setColor(sf::Color::White);
            colorGradient.enableState(HIDDEN);
        }
        else if(colorOption.getOption() == sf::Color::Black)
        {
            selectColor.setColor(sf::Color::Black);
            colorGradient.enableState(HIDDEN);
        }
        colorGradient.setColor(convertToHeu(colorOption.getOption()));
//        if(MouseEvents<ColorGradient>::mouseClicked( window, event))
//        {
//            colorGradient.enableState(CLICKED);
//        }
//        selectColor.setColor(colorOption.getSelectColor());
    }

    if(!colorGradient.checkState(HIDDEN) && MouseEvents<ColorGradient>::draggedOver(colorGradient, window, event) && colorOption.getOption() != sf::Color::Black && colorOption.getOption() != sf::Color::White)
    {
        selectColor.setColor(colorGradient.getColor((sf::Vector2i)sf::Mouse::getPosition(window)));
    }
    else if(MouseEvents<sf::RectangleShape>::mouseClicked(window, event))
    {
//        colorGradient.disableState(CLICKED);
        colorGradient.enableState(HIDDEN);
    }
//    else
//        colorGradient.enableState(HIDDEN);
}

void ColorPicker::update() {
    colorOption.update();
    if(selectColor.checkState(CLICKED))
        colorOption.disableState(HIDDEN);
//    else
//        colorOption.enableState(HIDDEN);


}

Snapshot &ColorPicker::getSnapshot()
{

}

void ColorPicker::applySnapshot(const Snapshot &snapshot)
{

}

sf::Vector2f ColorPicker::getPosition() const
{
    return selectColor.getPosition();
}

void ColorPicker::setOutlineColor(sf::Color color)
{
    selectColor.setOutlineColor(color);
}

sf::FloatRect ColorPicker::getGlobalBounds() const
{
    return selectColor.getGlobalBounds();
}

sf::Color ColorPicker::getColor() const{
    return selectColor.getColor();
}

int ColorPicker::convertToHeu(sf::Color color) {
    if(color == sf::Color::Red)
        return 0;
    else if(color == sf::Color::Yellow)
        return 60;
    else if(color == sf::Color::Green)
        return 120;
    else if(color == sf::Color::Blue)
        return 240;
    else if(color == sf::Color(255,0,255))
        return 300;
    else if(color == sf::Color(21,244, 238))
        return 180;
}

void ColorPicker::setColor(std::string string)
{
    unsigned int a = std::stoul(string);

    selectColor.setColor(sf::Color(a));
}

void ColorPicker::setColor(sf::Color color)
{
    selectColor.setColor(color);
}

