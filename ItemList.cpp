//
// Created by Wing Yin Chan on 19/10/2021.
//

#include "ItemList.h"

ItemList::ItemList()
{

}
//void ItemList::addItem(Item item)
//{
//    longestWidth = 0;
//    if(item.getGlobalBounds().width > longestWidth)
//    {
//        longestWidth = item.getGlobalBounds().width;
//        greatestBoxSize = item.getBoxSize();
//    }
//    initialSize = item.getCharacterSize();
//    newSize = initialSize + 5;
//    item.setPosition(item.getPosition().x, item.getPosition().y + item.getGlobalBounds().height * list.getSize());
//    list.push_back(item);
//
//}

void ItemList::addItem(std::string item)
{
    longestWidth = 0;
    Item temp;
    temp.setString(item);
    temp.setSize(temp.getCharacterSize());
    if(temp.getGlobalBounds().width > longestWidth)
    {
        longestWidth = temp.getGlobalBounds().width;
        greatestBoxSize = temp.getBoxSize();
    }
    temp.setPosition(temp.getPosition().x, temp.getPosition().y + temp.getGlobalBounds().height * list.getSize());
    list.push_back(temp);
    if(list.getSize() == 1)
        clickedItem = temp;
}

void ItemList::setPosition(float x, float y)
{
    int count = 0;

    LinkedList<Item>::iterator iter;
    for(iter = list.begin(); iter != list.end(); ++iter)
    {
        (*iter).setPosition(x,y + (*iter).getGlobalBounds().height * count);
        count++;
    }
}

void ItemList::addEventHandler(sf::RenderWindow &window, sf::Event event)
{

    LinkedList<Item>::iterator iter;
    for(iter = list.begin(); iter != list.end(); ++iter)
    {
//        if(MouseEvents<Item>::hovered((*iter), window))
//        {
//            (*iter).enableState(HOVERED);
//        }else
//        {
//            (*iter).disableState(HOVERED);
//        }
//
//        if(MouseEvents<Item>::mouseClicked((*iter), window))
//        {
//            clickedItem = *iter;
//            std::cout<<"In itemList:"<<clickedItem.getString()<<std::endl;
//        }
        (*iter).addEventHandler(window, event);
        if((*iter).checkState(CLICKED) && !checkState(HIDDEN))
            clickedItem = (*iter);
//        if(MouseEvents<Item>::hovered((*iter), window))
//            enableState(HOVERED);
//        else
//            disableState(HOVERED);
    }

}

void ItemList::update()
{
    LinkedList<Item>::iterator iter;
    for(iter = list.begin(); iter != list.end(); ++iter)
    {
        (*iter).update();
        (*iter).setBoxSize(greatestBoxSize);
//        (*iter).setTextCenter();
//        if((*iter).checkState(HOVERED))
//        {
//            (*iter).setBoxColor(sf::Color::Blue);
//            (*iter).setCharacterSize(newSize);
//        }else
//        {
//            (*iter).setBoxColor(sf::Color::Transparent);
//            (*iter).setCharacterSize(initialSize);
//        }
    }
}

void ItemList::draw(sf::RenderTarget &window, sf::RenderStates states) const
{
    LinkedList<Item>::iterator iter;
    if(!list.empty() && !checkState(HIDDEN))
    {
        for(iter = list.begin(); iter != list.end(); ++iter)
        {
            window.draw(*iter);
        }
    }
}

Snapshot &ItemList::getSnapshot()
{

}

void ItemList::applySnapshot(const Snapshot &snapshot)
{

}

LinkedList<Item>::iterator ItemList::begin() {
    return list.begin();
}

LinkedList<Item>::iterator ItemList::end() {
    return list.end();
}

void ItemList::setSize(int size)
{
    longestWidth = 0;

    LinkedList<Item>::iterator iter;
    for(iter = list.begin(); iter != list.end(); ++iter)
    {
        (*iter).setSize(size);
        if((*iter).getGlobalBounds().width > longestWidth)
        {
            longestWidth = (*iter).getGlobalBounds().width;
            greatestBoxSize = (*iter).getBoxSize();
        }
    }
    setPosition((*list.begin()).getPosition().x, (*list.begin()).getPosition().y);
}

sf::Vector2f ItemList::getBoxSize() const
{
    return greatestBoxSize;
}

bool ItemList::empty()
{
    return list.empty();
}

Item& ItemList::getClickedItem() {
    return clickedItem;
}

void ItemList::setClickItem(std::string string)
{
    clickedItem.setString(string);
}




