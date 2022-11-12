//
// Created by Wing Yin Chan on 19/10/2021.
//

#ifndef TYPINGSFML_INPUTBOX_H
#define TYPINGSFML_INPUTBOX_H
#include "Item.h"

class InputBox : public GUI_Component{
public:
    InputBox();

    void setString(std::string string);
    void setSize(int size);
    void setBoxSize(sf::Vector2f size);
    void setPosition(float x, float y);
    sf::Vector2f getPosition() const;
    sf::FloatRect getGlobalBounds() const;
    void setOutlineThickness(int size);
    void setOutlineColor(sf::Color color);
    void setTextCenter();
    std::string getString();


    virtual void addEventHandler(sf::RenderWindow& window, sf::Event event);
    virtual void update();
    virtual void draw(sf::RenderTarget& window, sf::RenderStates states) const;
    virtual Snapshot& getSnapshot();
    virtual void applySnapshot(const Snapshot& snapshot);
private:
    Item inputBox;
};


#endif //TYPINGSFML_INPUTBOX_H
