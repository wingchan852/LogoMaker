//
// Created by Wing Yin Chan on 20/10/2021.
//

#ifndef TYPINGSFML_DROPDOWNMENU_H
#define TYPINGSFML_DROPDOWNMENU_H
#include "InputBox.h"
#include "ItemList.h"
#include "History.h"

class DropdownMenu : public GUI_Component{
public:
    DropdownMenu();

    void setPosition(float x, float y);
    void setSize(int size);
//    void addItem(Item item);
    void addItem(std::string item);
    sf::Vector2f getPosition() const;
    sf::FloatRect getGlobalBounds() const;
    std::string getValue();
    void setInitialValue(std::string string);

    virtual void addEventHandler(sf::RenderWindow& window, sf::Event event);
    virtual void update();
    virtual void draw(sf::RenderTarget& window, sf::RenderStates states) const;
    virtual Snapshot& getSnapshot();
    virtual void applySnapshot(const Snapshot& snapshot);

private:
    InputBox inputBox;
    ItemList itemList;
    Snapshot snapshot;
    std::string value;
};


#endif //TYPINGSFML_DROPDOWNMENU_H
