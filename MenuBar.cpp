//
// Created by Wing Yin Chan on 21/10/2021.
//

#include "MenuBar.h"
MenuBar::MenuBar()
{
    greatestSize = 0;
}
void MenuBar::addMenu(std::string string)
{
    float totalWidth = 0;
    menuBar[string] = Menu(string);
    if(menuBar[string].getGlobalBounds().width > greatestSize)
        greatestSize = menuBar[string].getGlobalBounds().width;
//    greatestSize.y = menuBar[string].getGlobalBounds().height;
//    if(menuBar[string].getGlobalBounds().width > greatestSize.x)
//    {
//        greatestSize.x = menuBar[string].getGlobalBounds().width;
//    }
//    std::map<std::string, Menu>::iterator iter;
//    for(iter = menuBar.begin(); iter != menuBar.end(); ++iter)
//    {
//        (*iter).second.setMenuNameBoxSize(greatestSize);
//    }
//    std::map<std::string, sf::FloatRect>::iterator iter;
//    for(iter = width.begin(); iter != width.end(); ++iter)
//    {
//        totalWidth += iter->second.width;
//    }
//    std::cout<<"Total: "<<totalWidth<<std::endl;
//    width[string] = menuBar[string].getGlobalBounds();
    menuBar[string].setPosition(menuBar.begin()->second.getGlobalBounds().left + menuBar.begin()->second.getGlobalBounds().width * (menuBar.size() - 1), menuBar.begin()->second.getPosition().y);
}

void MenuBar::addEventHandler(sf::RenderWindow &window, sf::Event event)
{
    std::map<std::string, Menu>::iterator iter;
    for(iter = menuBar.begin(); iter != menuBar.end(); ++iter)
    {
        (*iter).second.addEventHandler(window, event);
    }
}

void MenuBar::update()
{
    std::map<std::string, Menu>::iterator iter;
    for(iter = menuBar.begin(); iter != menuBar.end(); ++iter)
    {
        (*iter).second.update();
        (*iter).second.setBoxSize({greatestSize, (*iter).second.getBoxSize().y});
//        (*iter).second.setMenuNameBoxSize(greatestSize);
    }
//    setPosition(menuBar.begin()->second.getPosition().x, menuBar.begin()->second.getPosition().y);
}

void MenuBar::draw(sf::RenderTarget &window, sf::RenderStates states) const
{
    std::map<std::string, Menu>::const_iterator iter;
    for(iter = menuBar.begin(); iter != menuBar.end(); ++iter)
    {
        (*iter).second.draw(window, states);
    }
}

Snapshot &MenuBar::getSnapshot()
{

}

void MenuBar::applySnapshot(const Snapshot &snapshot)
{

}

void MenuBar::addItem(std::string menuName, std::string item)
{
    menuBar[menuName].addItem(item);
//    menuBar[menuName].setPosition(menuBar[menuName].getPosition().x, menuBar.begin()->second.getPosition().y);

}

void MenuBar::setSize(int size)
{
    std::map<std::string, Menu>::iterator iter;
    for(iter = menuBar.begin(); iter != menuBar.end(); ++iter)
    {
        (*iter).second.setSize(size);
    }
    setPosition(menuBar.begin()->second.getPosition().x, menuBar.begin()->second.getPosition().y);
}

void MenuBar::setPosition(float x, float y)
{
    int count = 0;
    std::map<std::string, Menu>::iterator iter;
    for(iter = menuBar.begin(); iter != menuBar.end(); ++iter)
    {
        (*iter).second.setPosition(x + menuBar.begin()->second.getGlobalBounds().width * count, y);
        count++;
    }
}

//Item &MenuBar::getClickItem(std::string menu) {
//    return menuBar[menu].getClickItem();
//}

std::string MenuBar::getClickItem(std::string menu) {
    return menuBar[menu].getClickItem().getString();
}

void MenuBar::reset(std::string menu)
{
    menuBar[menu].getClickItem().setString("none");
}



