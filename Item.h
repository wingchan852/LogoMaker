//
// Created by Wing Yin Chan on 19/10/2021.
//

#ifndef TYPINGSFML_ITEM_H
#define TYPINGSFML_ITEM_H
#include <SFML/Graphics.hpp>
#include "Fonts.h"
#include "GUI_Component.h"
#include "MouseEvents.h"
class Item : public GUI_Component{
public:
    Item();
    Item(std::string string);
    void setString(std::string string);
    void setPosition(float x, float y);
    void setSize(int size);
    void setBoxSize(sf::Vector2f size);
    sf::Vector2f getBoxSize() const;
    sf::FloatRect getGlobalBounds() const;
    sf::Vector2f getPosition() const;
    void setCharacterSize(int size);
    void setBoxColor(sf::Color color);
    int getCharacterSize();
    std::string getString();
    void setOutlineThickness(int size);
    void setOutlineColor(sf::Color color);
    void setTextCenter();
    void setWidth(int width);
    sf::FloatRect  getTextGlobalBounds();
    void setTextPosition(sf::Vector2f position);

    virtual void addEventHandler(sf::RenderWindow& window, sf::Event event);
    virtual void update();
    virtual void draw(sf::RenderTarget& window, sf::RenderStates states) const;
    virtual Snapshot& getSnapshot();
    virtual void applySnapshot(const Snapshot& snapshot);
private:
    sf::Text text;
    sf::RectangleShape box;
    float padding;
    int widthRatio;
    float heightRatio;
    int height;
    int newSize;
    int initialSize;
};


#endif //TYPINGSFML_ITEM_H
