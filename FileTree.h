//
// Created by Wing Yin Chan on 9/11/2021.
//

#ifndef TYPINGSFML_FILETREE_H
#define TYPINGSFML_FILETREE_H
#include "FileNode.h"

class FileTree : public GUI_Component{
public:
    FileTree();
    void push(std::string parent, std::string item);
    std::string getClickedItem();

    virtual void addEventHandler(sf::RenderWindow& window, sf::Event event);
    virtual void update();
    virtual void draw(sf::RenderTarget& window, sf::RenderStates states) const;
    virtual Snapshot& getSnapshot();
    virtual void applySnapshot(const Snapshot& snapshot);

private:
    FileNode* root = nullptr;
    void push(FileNode*& root, std::string parent, std::string item, bool& found);
    void traverse(FileNode* &root, sf::RenderWindow& window, sf::Event event);
    sf::Vector2f initPosition = {0, 0};
    std::string clicked;
};


#endif //TYPINGSFML_FILETREE_H
