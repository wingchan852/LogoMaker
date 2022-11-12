//
// Created by Wing Yin Chan on 5/10/2021.
//

#ifndef TYPINGSFML_TEXTINPUT_H
#define TYPINGSFML_TEXTINPUT_H

#include "MultiText.h"
#include "GUI_Component.h"
#include "TextBox.h"
#include "Label.h"
#include "Cursor.h"
#include "MouseEvents.h"
#include "Coloring.h"
#include <vector>
class TextInput : public GUI_Component{
public:
    TextInput();
    virtual void draw(sf::RenderTarget& window, sf::RenderStates states) const;
    virtual void addEventHandler(sf::RenderWindow& window, sf::Event event);
    virtual void update();
    virtual Snapshot& getSnapshot();
    virtual void applySnapshot(const Snapshot& snapshot);
    void setLabel(std::string string);
    void setSize(int size);
    void setPosition(float x, float y);
    void setBoxLength(float length);
    void setCharacterSize(int size);
    void setLabelSize(int size);
    void setLabelPosition(sf::Vector2f position);
    void setInputBoxPosition(sf::Vector2f position);

    std::string getText();
    void setText(std::string string);
    void clear();

private:
    TextBox textBox;
    Label label;
    Cursor cursor;
    MultiText multiText;
    Coloring colorCode;

    LinkedList<Letter>::iterator first;
    LinkedList<Letter>::iterator last;
};


#endif //TYPINGSFML_TEXTINPUT_H
