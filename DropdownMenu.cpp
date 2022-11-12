//
// Created by Wing Yin Chan on 20/10/2021.
//

#include "DropdownMenu.h"

DropdownMenu::DropdownMenu()
{

//    itemList.addItem(Item("ABCDEFGHIJK"));
//    itemList.addItem(Item("Banana"));
//    itemList.addItem(Item("Apple"));
//    itemList.addItem(Item("Hello"));
//    itemList.addItem(Item("Hello Nurse!"));
//
//    inputBox.setString((*itemList.begin()).getString());
//    inputBox.setPosition(0,0);
//    inputBox.setOutlineThickness(3);
//    inputBox.setOutlineColor(sf::Color::White);
//    inputBox.setBoxSize(itemList.getBoxSize());
//
//    itemList.setPosition(inputBox.getPosition().x, inputBox.getGlobalBounds().height + inputBox.getGlobalBounds().top);
    itemList.enableState(HIDDEN);

    inputBox.setPosition(0,0);
}

void DropdownMenu::addEventHandler(sf::RenderWindow &window, sf::Event event)
{
    itemList.addEventHandler(window, event);
    if(MouseEvents<InputBox>::mouseClicked(inputBox, window))
    {
        itemList.disableState(HIDDEN);
        inputBox.enableState(CLICKED);
    } else if(!itemList.checkState(HIDDEN))
    {
        if (MouseEvents<Item>::mouseClicked(itemList.getClickedItem(), window))
        {
            snapshot.setData(inputBox.getString());
            inputBox.setString(itemList.getClickedItem().getString());
            value = inputBox.getString();
            inputBox.setTextCenter();
            History::pushHistory({snapshot, this});
        }

        if(MouseEvents<sf::RectangleShape>::mouseClicked(window, event))
            itemList.enableState(HIDDEN);
    }


//    else if(MouseEvents<sf::RectangleShape>::mouseClicked(window, event))
//    {
//        itemList.enableState(HIDDEN);
//    }
//
//
//    if(inputBox.checkState(CLICKED) && MouseEvents<Item>::mouseClicked(itemList.getClickedItem(), window))
//    {
//        snapshot.setData(inputBox.getString());
//        inputBox.setString(itemList.getClickedItem().getString());
//        inputBox.setTextCenter();
//        History::pushHistory({snapshot, this});
//        inputBox.disableState(CLICKED);
//    }


//    if(itemList.checkState(CLICKED) && MouseEvents<Item>::mouseClicked(itemList.getClickedItem(), window))
//    {
//        snapshot.setData(inputBox.getString());
//        std::cout<<"In dropdownMenu: "<<itemList.getClickedItem().getString()<<std::endl;
//        inputBox.setString(itemList.getClickedItem().getString());
//        inputBox.setTextCenter();
//        History::pushHistory({snapshot, this});
//        itemList.disableState(CLICKED);
//    }
//    if(!itemList.checkState(HIDDEN))
//    {
//        LinkedList<Item>::iterator iter;
//        iter = itemList.begin();
//        for(; iter != itemList.end(); ++iter)
//        {
//            if( MouseEvents<Item>::mouseClicked((*iter), window))
//            {
//                snapshot.setData(inputBox.getString());
//                inputBox.setString((*iter).getString());
//                inputBox.setTextCenter();
//                itemList.enableState(HIDDEN);
//                History::pushHistory({snapshot, this});
//            }
//        }
//    }

}

void DropdownMenu::update()
{
    itemList.update();
    setPosition(inputBox.getPosition().x, inputBox.getPosition().y);
}

void DropdownMenu::draw(sf::RenderTarget &window, sf::RenderStates states) const
{
    if(!inputBox.checkState(HIDDEN))
        window.draw(inputBox);
    if(!itemList.checkState(HIDDEN))
        window.draw(itemList);
}

Snapshot &DropdownMenu::getSnapshot()
{
    return snapshot;
}

void DropdownMenu::applySnapshot(const Snapshot &snapshot)
{
    inputBox.setString(snapshot.getData());
    inputBox.setTextCenter();
}

void DropdownMenu::setPosition(float x, float y)
{
    inputBox.setPosition(x,y);
    itemList.setPosition(inputBox.getPosition().x, inputBox.getGlobalBounds().height + inputBox.getGlobalBounds().top);

}

void DropdownMenu::setSize(int size)
{
    inputBox.setSize(size);
    itemList.setSize(size);
    inputBox.setBoxSize(itemList.getBoxSize());
    itemList.setPosition(inputBox.getPosition().x, inputBox.getGlobalBounds().height + inputBox.getGlobalBounds().top);

//    itemList.setPosition(inputBox.getPosition().x, inputBox.getPosition().y);
}

//void DropdownMenu::addItem(Item item)
//{
//    itemList.addItem(item);
//
//    inputBox.setString((*itemList.begin()).getString());
//    inputBox.setOutlineThickness(3);
//    inputBox.setOutlineColor(sf::Color::White);
//    inputBox.setBoxSize(itemList.getBoxSize());
//    inputBox.setTextCenter();
//}

void DropdownMenu::addItem(std::string item)
{
    itemList.addItem(item);

    inputBox.setString((*itemList.begin()).getString());
    inputBox.setOutlineThickness(3);
    inputBox.setOutlineColor(sf::Color::White);
    inputBox.setBoxSize(itemList.getBoxSize());
    inputBox.setTextCenter();

}

sf::Vector2f DropdownMenu::getPosition() const{
    return inputBox.getPosition();
}

sf::FloatRect DropdownMenu::getGlobalBounds() const {
    return inputBox.getGlobalBounds();
}

std::string DropdownMenu::getValue() {
    return value;
}

void DropdownMenu::setInitialValue(std::string string)
{
    value = string;
    inputBox.setString(string);
}
