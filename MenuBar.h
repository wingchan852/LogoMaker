//
// Created by Wing Yin Chan on 21/10/2021.
//

#ifndef TYPINGSFML_MENUBAR_H
#define TYPINGSFML_MENUBAR_H
#include "Menu.h"
#include <map>
class MenuBar : public GUI_Component{
public:
    MenuBar();
    void addMenu(std::string string);
    void addItem(std::string menuName, std::string item);
    void setSize(int size);
    void setPosition(float x, float y);
    std::string getClickItem(std::string menu);
    void reset(std::string menu);
//    Item& getClickItem(std::string menu);

    virtual void addEventHandler(sf::RenderWindow& window, sf::Event event);
    virtual void update();
    virtual void draw(sf::RenderTarget& window, sf::RenderStates states) const;
    virtual Snapshot& getSnapshot();
    virtual void applySnapshot(const Snapshot& snapshot);
private:
    std::map<std::string, Menu> menuBar;
    float greatestSize;
};


#endif //TYPINGSFML_MENUBAR_H
