//
// Created by Wing Yin Chan on 17/11/2021.
//

#include "Slider.h"

Slider::Slider() : Slider("default:  ", 500, {400,100}, 400)
{

}

Slider::Slider(std::string label, float length, sf::Vector2f position, float startingPoint)
{

    this->label.setString(label);
    this->label.setCharacterSize(30);

    line.setSize({length, 3});
    line.setFillColor(sf::Color::White);

    knob.setRadius(10);
    knob.setFillColor(sf::Color::White);

    number = startingPoint;
    value.setString("  " + std::to_string(number));
    value.setCharacterSize(30);

    setPosition(position);
    setStartingPoint(startingPoint);

}


void Slider::draw(sf::RenderTarget &window, sf::RenderStates states) const
{
    window.draw(line);
    window.draw(knob);
    window.draw(label);
    window.draw(value);
}

void Slider::addEventHandler(sf::RenderWindow &window, sf::Event event)
{
    if(MouseEvents<sf::CircleShape>::draggedOver(knob, window, event))
    {
        if(!checkState(dragging))
        {
            snapshot.setValue(number);
            enableState(dragging);
            History::pushHistory({snapshot, this});
                    std::cout<<snapshot.getValue()<<std::endl;
        }

        sf::Vector2f mousePos = (sf::Vector2f) sf::Mouse::getPosition(window);
        if(mousePos.x >= line.getGlobalBounds().left && mousePos.x <= line.getGlobalBounds().left + line.getGlobalBounds().width)
        {
            knob.setPosition({mousePos.x - knob.getRadius(), knob.getPosition().y});
            number = mousePos.x - line.getGlobalBounds().left;
            value.setString(" " + std::to_string(number));
        }
    } else if( event.type == sf::Event::MouseButtonReleased)
        disableState(dragging);


//    else if(MouseEvents<sf::CircleShape>::hovered(knob, window) )
//    {
//        std::cout<<"knob value1: "<<number<<std::endl;
//        snapshot.setValue(number);
//    }
//    else if(event.type == sf::Event::MouseButtonReleased)
//    {
//        History::pushHistory({snapshot, this});
//        std::cout<<snapshot.getValue()<<std::endl;
//    }

}

void Slider::update()
{

}

Snapshot &Slider::getSnapshot()
{
    return snapshot;
}

void Slider::applySnapshot(const Snapshot &snapshot)
{
    setValue(snapshot.getValue());
    setStartingPoint(snapshot.getValue());

}

void Slider::setPosition(sf::Vector2f position)
{
//    label.setPosition(position.x, position.y);
//    line.setPosition(label.getGlobalBounds().left + label.getGlobalBounds().width, label.getGlobalBounds().height + label.getGlobalBounds().top);
//    knob.setPosition(line.getGlobalBounds().left, line.getGlobalBounds().height/2 + line.getGlobalBounds().top - knob.getRadius());


    line.setPosition(position);
    knob.setPosition({position.x, line.getGlobalBounds().height/2 + line.getGlobalBounds().top - knob.getRadius()});
    label.setPosition(line.getGlobalBounds().left - label.getGlobalBounds().width, line.getGlobalBounds().top + line.getGlobalBounds().height - label.getGlobalBounds().height);
    value.setPosition(line.getGlobalBounds().left + line.getGlobalBounds().width, line.getGlobalBounds().top + line.getGlobalBounds().height - value.getGlobalBounds().height);

}

void Slider::setStartingPoint(float x)
{
    knob.setPosition({x + line.getGlobalBounds().left, knob.getPosition().y});

}

int Slider::getValue() const {
    return number;
}

void Slider::setValue(int value) {
    number = value;
}

void Slider::setValue(std::string value)
{
    number = std::stoi(value);
    this->value.setString("  " + value);
    setStartingPoint(number);

}

