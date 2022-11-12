//
// Created by Wing Yin Chan on 29/9/2021.
//

#ifndef TYPINGSFML_MULTITEXT_H
#define TYPINGSFML_MULTITEXT_H

#include "LinkedList.h"
#include "Letter.h"
#include "GUI_Component.h"
#include "History.h"

class MultiText : public GUI_Component{
public:
    MultiText();
    virtual void addEventHandler(sf::RenderWindow& window, sf::Event event);
    virtual void update();
    virtual void draw(sf::RenderTarget& window, sf::RenderStates states) const;
    virtual Snapshot& getSnapshot();
    virtual void applySnapshot(const Snapshot& snapshot);
    LinkedList<Letter>::iterator begin();
    LinkedList<Letter>::iterator end();
    LinkedList<Letter>::iterator rbegin();
    void push_back(char a);
    void setPosition(float x, float y);
    void setCharacterSize(int size);
    Letter getLastLetter() const;
    bool empty() const;
    int getSize() const;
    int getLineSpace() const;
    void clear();
private:
    void toString();
    std::string string;
    sf::Vector2f position;
    int characterSize;
    LinkedList<Letter> list;
    float lineSpace;
    Letter lastLetter;
    Snapshot snapshot;
};


#endif //TYPINGSFML_MULTITEXT_H
