//
// Created by Wing Yin Chan on 2/11/2021.
//

#include "FileItem.h"

FileItem::FileItem(std::string text, Image::images icon, sf::Vector2f position)
{
    item.setString(text);
    item.setWidth(150);
    this->icon.setTexture(Image::getTexture(icon));
    if(icon == Image::FOLDER)
        this->icon.setScale({0.04, 0.04});
    else
        this->icon.setScale({0.07, 0.07});
//    this->icon.setScale(size);
//    item.setSize(size.x);
//    item.setBoxSize({item.getTextGlobalBounds().width + padding, item.getGlobalBounds().height});
    setPosition(position);
//    enableState(HIDDEN);
}

FileItem::FileItem() : FileItem("default", Image::FOLDER, {0,0})
{

}

void FileItem::addEventHandler(sf::RenderWindow &window, sf::Event event)
{
    item.addEventHandler(window, event);
    if(MouseEvents<sf::Sprite>::mouseClicked(icon,window) || item.checkState(CLICKED))
    {
        enableState(CLICKED);
//        item.setBoxColor(sf::Color::Blue);
//        std::cout<<"Clicked"<<std::endl;
    }
//    else
//    {
//        disableState(CLICKED);
////        item.setBoxColor(sf::Color::Transparent);
//    }
}

void FileItem::update()
{

}

void FileItem::draw(sf::RenderTarget &window, sf::RenderStates states) const
{
        window.draw(item);
        window.draw(icon);

}

Snapshot &FileItem::getSnapshot()
{

}

void FileItem::applySnapshot(const Snapshot &snapshot)
{

}

sf::FloatRect FileItem::getGlobalBounds() const
{
    sf::FloatRect temp;
    temp.height = item.getGlobalBounds().height;
    temp.top = item.getGlobalBounds().top;
    temp.left = icon.getGlobalBounds().left;
    temp.width = item.getGlobalBounds().width;
    return temp;
}

sf::Vector2f FileItem::getPosition() const
{
    return icon.getPosition();
}

void FileItem::setPosition(sf::Vector2f position)
{
    icon.setPosition(position);
    item.setPosition(this->icon.getPosition().x, position.y);
    this->icon.setPosition(this->icon.getPosition().x, item.getGlobalBounds().height/2 + item.getGlobalBounds().top - this->icon.getGlobalBounds().height/2);
    item.setTextPosition({icon.getPosition().x + icon.getGlobalBounds().width, item.getGlobalBounds().height/2 + item.getGlobalBounds().top - item.getTextGlobalBounds().height/2});
}

void FileItem::setIcon(Image::images icon)
{
    this->icon.setTexture(Image::getTexture(icon));
}

sf::FloatRect FileItem::getIconBounds() const
{
    return icon.getGlobalBounds();
}

std::string FileItem::getString() {
    return item.getString();
}

void FileItem::setBoxColor(sf::Color color)
{
    item.setBoxColor(color);
}
