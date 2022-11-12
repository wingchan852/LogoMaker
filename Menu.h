//
// Created by Wing Yin Chan on 21/10/2021.
//

#ifndef TYPINGSFML_MENU_H
#define TYPINGSFML_MENU_H
#include "ItemList.h"

class Menu : public GUI_Component{
public:
    Menu();
    Menu(std::string string);
    void addItem(std::string item);
    void setMenu(std::string string);
    void setPosition(float x, float y);
    void setSize(int size);
    void setBoxSize(sf::Vector2f size);
    sf::Vector2f getBoxSize() const;
    sf::FloatRect getGlobalBounds();
    sf::Vector2f getPosition();
    void setMenuNameBoxSize(sf::Vector2f size);
    Item& getClickItem();

    virtual void addEventHandler(sf::RenderWindow& window, sf::Event event);
    virtual void update();
    virtual void draw(sf::RenderTarget& window, sf::RenderStates states) const;
    virtual Snapshot& getSnapshot();
    virtual void applySnapshot(const Snapshot& snapshot);
private:
    ItemList itemList;
    Item menu;
};


#endif //TYPINGSFML_MENU_H
