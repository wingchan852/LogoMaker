//
// Created by Wing Yin Chan on 9/11/2021.
//

#ifndef TYPINGSFML_FILENODE_H
#define TYPINGSFML_FILENODE_H
#include "FileItem.h"

class FileNode : public GUI_Component{
public:
    FileNode();
    FileNode(Image::images icon, std::string text, sf::Vector2f position);
    typedef typename std::map<std::string, FileNode*>::iterator iterator;
    bool isLeaf() const;
    FileItem &getData();
    void setData(const FileItem &data);
    std::map<std::string, FileNode*>& getChildren();
    iterator begin();
    iterator end();
    sf::FloatRect getGlobalBounds() const;
    void setPosition(sf::Vector2f position);

    virtual void addEventHandler(sf::RenderWindow& window, sf::Event event);
    virtual void update();
    virtual void draw(sf::RenderTarget& window, sf::RenderStates states) const;
    virtual Snapshot& getSnapshot();
    virtual void applySnapshot(const Snapshot& snapshot);

private:
    FileItem data;
    std::map<std::string, FileNode*> children;
    void toggleChlidren();
    void reposition() const;
};


#endif //TYPINGSFML_FILENODE_H
