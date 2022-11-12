//
// Created by Wing Yin Chan on 6/10/2021.
//

#ifndef TYPINGSFML_LABEL_H
#define TYPINGSFML_LABEL_H


#include <SFML/Graphics.hpp>
#include "GUI_Component.h"
#include "Fonts.h"
class Label : public GUI_Component{
public:
    Label();
    virtual void draw(sf::RenderTarget& window, sf::RenderStates states) const;
    virtual void addEventHandler(sf::RenderWindow& window, sf::Event event);
    virtual void update();
    virtual Snapshot& getSnapshot();
    virtual void applySnapshot(const Snapshot& snapshot);
    void setPosition(float x, float y);
    void setString(std::string string);
    void setCharacterSize(int size);
    int getCharacterSize() const;
    sf::FloatRect getGlobalBounds() const;
    sf::Vector2f getPosition() const;
private:
    sf::Text label;
};


#endif //TYPINGSFML_LABEL_H
