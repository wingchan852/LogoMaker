//
// Created by Wing Yin Chan on 9/11/2021.
//

#include "FileTree.h"

FileTree::FileTree()
{

}

void FileTree::push(std::string parent, std::string item)
{
    bool found = false;
    push(root, parent, item, found);
    if(!found)
    {
        std::cout<<parent + " is not exist"<<std::endl;
    }
}

void FileTree::push(FileNode *&root, std::string parent, std::string item, bool& found)
{
    if(root == nullptr)
    {
        root = new FileNode(Image::FOLDER, parent, initPosition);
//        root->disableState(HIDDEN);
        sf::Vector2f position;
        position.x = root->getData().getPosition().x + root->getData().getIconBounds().width;
        position.y = root->getData().getPosition().y + root->getData().getGlobalBounds().height;
        root->getChildren()[item] = new FileNode(Image::FILE, item, position);
        found = true;
    } else if(root->getData().getString() == parent)
    {
        root->getData().setIcon(Image::FOLDER);
        sf::Vector2f position = {0,0};
        position.x = root->getData().getPosition().x;
        position.y = root->getData().getPosition().y + root->getData().getGlobalBounds().height*(root->getChildren().size()+1);
        root->getChildren()[item] = new FileNode(Image::FILE, item, position);
        found = true;
    } else
    {
        auto iter = root->begin();
        for(; iter != root->end(); ++iter)
        {
            push(iter->second, parent, item, found);
        }
    }
}

void FileTree::traverse(FileNode *&root, sf::RenderWindow &window, sf::Event event)
{
    if(MouseEvents<FileItem>::mouseClicked(root->getData(), window))
    {
        root->getData().setBoxColor(sf::Color::Blue);
        clicked = root->getData().getString();
    } else if (MouseEvents<FileItem>::mouseClicked(window, event))
    {
        root->getData().setBoxColor(sf::Color::Transparent);
    }

    if(root != nullptr&& !root->isLeaf())
    {
        root->addEventHandler(window,event);
        FileNode::iterator iter = root->begin();
        for(; iter != root->end(); ++iter)
        {
            traverse(iter->second, window, event);
        }
    }
//    std::cout<<clicked<<std::endl;

}

void FileTree::addEventHandler(sf::RenderWindow &window, sf::Event event)
{
    traverse(root, window, event);
}

void FileTree::update()
{

}

void FileTree::draw(sf::RenderTarget &window, sf::RenderStates states) const
{
    window.draw(*root);
}

Snapshot &FileTree::getSnapshot()
{

}

void FileTree::applySnapshot(const Snapshot &snapshot)
{

}

std::string FileTree::getClickedItem() {
//    std::cout<<clicked<<std::endl;
    return clicked;
}


