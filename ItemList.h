//
// Created by Wing Yin Chan on 19/10/2021.
//

#ifndef TYPINGSFML_ITEMLIST_H
#define TYPINGSFML_ITEMLIST_H
#include "Item.h"
#include "LinkedList.h"
#include "MouseEvents.h"
class ItemList : public GUI_Component{
public:
//    void addItem(Item item);
    ItemList();
    void addItem(std::string item);
    void setPosition(float x, float y);
    LinkedList<Item>::iterator begin();
    LinkedList<Item>::iterator end();
    void setSize(int size);
    sf::Vector2f getBoxSize() const;
    bool empty();
    Item& getClickedItem();
    void setClickItem(std::string string);

    virtual void addEventHandler(sf::RenderWindow& window, sf::Event event);
    virtual void update();
    virtual void draw(sf::RenderTarget& window, sf::RenderStates states) const;
    virtual Snapshot& getSnapshot();
    virtual void applySnapshot(const Snapshot& snapshot);
private:
    LinkedList<Item> list;
    int longestWidth;
    sf::Vector2f greatestBoxSize;
    Item clickedItem;
};


#endif //TYPINGSFML_ITEMLIST_H
