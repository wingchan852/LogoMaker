//
// Created by Wing Yin Chan on 5/10/2021.
//

#include "TextInput.h"
#include <algorithm>
TextInput::TextInput()
{
    setPosition(500,500);
    cursor.setCharacterSize(label.getCharacterSize());
    multiText.setPosition(textBox.getPosition().x, label.getPosition().y);
}

void TextInput::draw(sf::RenderTarget &window, sf::RenderStates states) const
{
    window.draw(textBox);
    window.draw(label);
    window.draw(cursor);
    window.draw(multiText);
}

void TextInput::addEventHandler(sf::RenderWindow &window, sf::Event event)
{
    if(!cursor.checkState(HIDDEN))
        multiText.addEventHandler(window, event);
    if(MouseEvents<TextBox>::mouseClicked(textBox,window))
    {
        cursor.disableState(HIDDEN);
        cursor.enableState(BLINKING);
        textBox.setOutlineColor(sf::Color(248, 222, 127));
        textBox.setOutlineThickness(7);
    } else if(MouseEvents<sf::RectangleShape>::mouseClicked(window,event))
    {
        cursor.enableState(HIDDEN);
        cursor.disableState(BLINKING);
        textBox.setOutlineColor(sf::Color::White);
        textBox.setOutlineThickness(5);
    }

    if(multiText.getLastLetter().getGlobalBounds().left + multiText.getLastLetter().getGlobalBounds().width + multiText.getLastLetter().getCharacterSize()>=textBox.getGlobalBounds().left + textBox.getGlobalBounds().width)
    {
        multiText.enableState(LIMITED);
    } else
        multiText.disableState(LIMITED);
}
//multiText.getLastLetter().getPosition().y
void TextInput::update()
{
    //coloring
    colorCode.ChangeColor(multiText);

    //Cursor positioning
    if(!multiText.empty())
        cursor.setPosition(multiText.getLastLetter().getPosition().x + multiText.getLastLetter().getGlobalBounds().width,textBox.getGlobalBounds().top - (textBox.getGlobalBounds().height - cursor.getGlobalBounds().height) );
    else
    {
        cursor.setPosition(textBox.getPosition().x, cursor.getPosition().y );
    }

    cursor.update();

}

Snapshot &TextInput::getSnapshot()
{

}

void TextInput::applySnapshot(const Snapshot &snapshot)
{

}

void TextInput::setLabel(std::string string)
{
    label.setString(string);
}

void TextInput::setSize(int size)
{
    label.setCharacterSize(size);
    cursor.setCharacterSize(size);
    multiText.setCharacterSize(size);
//    float height = static_cast<float>(label.getGlobalBounds().height) + static_cast<float>(label.getGlobalBounds().top) - textBox.getGlobalBounds().top;
    textBox.setSize({textBox.getSize().x, cursor.getGlobalBounds().height});
    setPosition(label.getPosition().x, label.getPosition().y);
}

void TextInput::setPosition(float x, float y)
{
    label.setPosition(x,y);
    textBox.setPosition(label.getGlobalBounds().width + label.getPosition().x, label.getGlobalBounds().top);
//    textBox.setPosition(label.getGlobalBounds().width + label.getPosition().x, label.getPosition().y);
    multiText.setPosition(textBox.getPosition().x, label.getPosition().y +20);
    cursor.setPosition(textBox.getPosition().x, textBox.getGlobalBounds().top - (textBox.getGlobalBounds().height - cursor.getGlobalBounds().height));
}

void TextInput::setBoxLength(float length)
{
    textBox.setSize({length, textBox.getSize().y});
}

void TextInput::setCharacterSize(int size)
{
    multiText.setCharacterSize(size);
    cursor.setCharacterSize(size);
    textBox.setSize({textBox.getSize().x, cursor.getGlobalBounds().height});
}

void TextInput::setLabelSize(int size)
{
    label.setCharacterSize(size);
}

void TextInput::setLabelPosition(sf::Vector2f position)
{
    label.setPosition(position.x, position.y);
}

void TextInput::setInputBoxPosition(sf::Vector2f position)
{
    textBox.setPosition(position.x, position.y);
    multiText.setPosition(textBox.getPosition().x, textBox.getPosition().y);
    cursor.setPosition(textBox.getPosition().x, textBox.getGlobalBounds().top - (textBox.getGlobalBounds().height - cursor.getGlobalBounds().height));
}

std::string TextInput::getText() {
    std::string str;
    auto iter = multiText.begin();
    if(!multiText.empty())
    {
        for(;iter != multiText.end(); ++iter)
        {
            str += (*iter).getString();
//            std::cout<<str<<std::endl;
        }
    } else
        str = "";
//    std::cout<<"str"<<std::endl;
    return str;
}

void TextInput::setText(std::string string)
{
    for(std::string::iterator it = string.begin(); it != string.end(); ++it)
    {
        multiText.push_back(*it);
    }
}

void TextInput::clear()
{
    multiText.clear();
}
