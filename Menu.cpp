//
// Created by Wing Yin Chan on 21/10/2021.
//

#include "Menu.h"

Menu::Menu() : Menu("Menu")
{
//    menu.setString("Menu");
//    itemList.addItem(Item("item1"));
//    itemList.addItem(Item("item2"));
//    itemList.addItem(Item("item3"));
//    itemList.addItem(Item("item4"));
//    menu.setPosition(0,0);
//    itemList.setPosition(menu.getPosition().x, menu.getGlobalBounds().height + menu.getGlobalBounds().top);
//    menu.setBoxSize({itemList.getBoxSize().x/2, itemList.getBoxSize().y});
//    menu.setTextCenter();
}

Menu::Menu(std::string string)
{
    menu.setString(string);
    menu.setTextCenter();
//        menu.setPosition(0,0);
    itemList.enableState(HIDDEN);
}


void Menu::addEventHandler(sf::RenderWindow &window, sf::Event event)
{
    itemList.addEventHandler(window, event);
    if(MouseEvents<Item>::mouseClicked(menu, window))
    {
        menu.enableState(HOVERED);
    } else if(MouseEvents<sf::RectangleShape>::mouseClicked(window, event))
    {
        menu.disableState(HOVERED);
    }
//    if(MouseEvents<Item>::mouseClicked(itemList.getClickedItem(), window))
//    {
//        itemList.enableState(HIDDEN);
//    }


//    LinkedList<Item>::iterator iter;
//    iter = itemList.begin();
//    for(; iter != itemList.end(); ++iter)
//    {
//        if(!itemList.checkState(HIDDEN) && MouseEvents<Item>::mouseClicked((*iter), window))
//        {
//            itemList.enableState(HIDDEN);
//            menu.disableState(HOVERED);
//        }
//    }
}

void Menu::update()
{
    itemList.update();
    if(menu.checkState(HOVERED))
    {
        menu.setBoxColor(sf::Color::Blue);
        itemList.disableState(HIDDEN);
    }
    else
    {
        menu.setBoxColor(sf::Color::Transparent);
        itemList.enableState(HIDDEN);
    }
}

void Menu::draw(sf::RenderTarget &window, sf::RenderStates states) const
{
    if(!menu.checkState(HIDDEN))
        window.draw(menu);
    if(!itemList.checkState(HIDDEN))
        window.draw(itemList);
}

Snapshot &Menu::getSnapshot()
{

}

void Menu::applySnapshot(const Snapshot &snapshot)
{

}

void Menu::addItem(std::string item)
{
    itemList.addItem(item);
    menu.setSize(menu.getCharacterSize());
    menu.setTextCenter();
    setPosition(menu.getPosition().x, menu.getPosition().y);
}

void Menu::setMenu(std::string string)
{
    menu.setString(string);
    menu.setTextCenter();
}

void Menu::setPosition(float x, float y)
{
    menu.setPosition(x,y);
    itemList.setPosition(menu.getPosition().x, menu.getGlobalBounds().height + menu.getGlobalBounds().top);

}

void Menu::setSize(int size)
{
    menu.setSize(size);
    itemList.setSize(size);
    itemList.setPosition(menu.getPosition().x, menu.getGlobalBounds().height + menu.getGlobalBounds().top);
//    itemList.setPosition(menu.getPosition().x, menu.getGlobalBounds().height + menu.getGlobalBounds().top);

}

sf::FloatRect Menu::getGlobalBounds() {
    return menu.getGlobalBounds();
}

sf::Vector2f Menu::getPosition() {
    return menu.getPosition();
}

void Menu::setMenuNameBoxSize(sf::Vector2f size)
{
    menu.setBoxSize(size);
}

void Menu::setBoxSize(sf::Vector2f size)
{
    menu.setBoxSize(size);
    menu.setTextCenter();
}

sf::Vector2f Menu::getBoxSize() const{
    return menu.getBoxSize();
}

Item& Menu::getClickItem() {
    return itemList.getClickedItem();
}


