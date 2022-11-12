//
// Created by Wing Yin Chan on 28/11/2021.
//

#ifndef TYPINGSFML_WINDOWDIALOG_H
#define TYPINGSFML_WINDOWDIALOG_H
#include <SFMl/Graphics.hpp>
#include "Item.h"
#include "States.h"
#include "FileTree.h"
class WindowDialog : public States{
public:
    WindowDialog();
    WindowDialog(sf::Vector2i size);
    void run();
    std::string getClickItem();
private:
    sf::RenderWindow window;
    sf::Vector2i size;
    Item openBtn;
    Item cancelBtn;
    FileTree fileTree;
    std::string clickItem;
};


#endif //TYPINGSFML_WINDOWDIALOG_H
