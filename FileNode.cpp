//
// Created by Wing Yin Chan on 9/11/2021.
//

#include "FileNode.h"
#include <iostream>
FileNode::FileNode()
{

}

FileNode::FileNode(Image::images icon, std::string text, sf::Vector2f position) : data(text, icon, position)
{
    enableState(HIDDEN);
//    disableState(SHOWED);
}

bool FileNode::isLeaf() const {
    return children.empty();
}

FileItem &FileNode::getData() {
    return data;
}

void FileNode::setData(const FileItem &data)
{
    this->data = data;
}

std::map<std::string, FileNode *> &FileNode::getChildren() {
    return children;
}

FileNode::iterator FileNode::begin() {
    return children.begin();
}

FileNode::iterator FileNode::end() {
    return children.end();
}

void FileNode::addEventHandler(sf::RenderWindow &window, sf::Event event) {
    if(MouseEvents<FileItem>::mouseClicked(data,window))
    {
//        disableState(HIDDEN);
//        std::cout<<data.getString()<<std::endl;
        toggleChlidren();
    }


}

void FileNode::update() {
}

void FileNode::draw(sf::RenderTarget &window, sf::RenderStates states) const
{
    reposition();
    window.draw(data);
    if(!checkState(HIDDEN))
    {
        auto iter = children.begin();
        for(;iter != children.end(); ++iter)
        {
            iter->second->draw(window, states);
        }
    }

}

Snapshot &FileNode::getSnapshot() {

}

void FileNode::applySnapshot(const Snapshot &snapshot) {

}

void FileNode::toggleChlidren()
{
    if(checkState(HIDDEN))
        disableState(HIDDEN);
    else
        enableState(HIDDEN);
}

void FileNode::reposition() const
{
    float tempPos = getGlobalBounds().top + data.getGlobalBounds().height;
    auto iter = children.begin();
    for(; iter != children.end(); ++iter)
    {
            iter->second->setPosition({getGlobalBounds().left + iter->second->getData().getIconBounds().width,
                                       tempPos} );
            tempPos += iter->second->getGlobalBounds().height;
    }
}

sf::FloatRect FileNode::getGlobalBounds() const{

    sf::FloatRect totalBounds = data.getGlobalBounds();

    if(!checkState(HIDDEN))
    {
        auto iter = children.begin();
        for(; iter != children.end(); ++iter)
        {
            totalBounds.height += iter->second->getGlobalBounds().height;
        }
    }

    return totalBounds;
}

void FileNode::setPosition(sf::Vector2f position)
{
    data.setPosition(position);
}
