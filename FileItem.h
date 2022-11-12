//
// Created by Wing Yin Chan on 2/11/2021.
//

#ifndef TYPINGSFML_FILEITEM_H
#define TYPINGSFML_FILEITEM_H
#include "Item.h"
#include "Image.h"
class FileItem : public GUI_Component{
public:
    FileItem();
    FileItem(std::string text, Image::images icon, sf::Vector2f position);
    sf::FloatRect getGlobalBounds() const;
    sf::Vector2f getPosition() const;
    void setPosition(sf::Vector2f position);
    void setIcon(Image::images icon);
    sf::FloatRect getIconBounds() const;
    std::string getString();
    void setBoxColor(sf::Color color);

    virtual void addEventHandler(sf::RenderWindow& window, sf::Event event);
    virtual void update();
    virtual void draw(sf::RenderTarget& window, sf::RenderStates states) const;
    virtual Snapshot& getSnapshot();
    virtual void applySnapshot(const Snapshot& snapshot);

private:
    Item item;
    sf::Sprite icon;
    float padding = 10;
};


#endif //TYPINGSFML_FILEITEM_H
