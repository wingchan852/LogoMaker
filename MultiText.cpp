//
// Created by Wing Yin Chan on 29/9/2021.
//

#include "MultiText.h"
MultiText::MultiText()
{
    lineSpace = 70;
    characterSize = 70;
}
void MultiText::addEventHandler(sf::RenderWindow &window, sf::Event event)
{
    if(event.type == event.TextEntered)
    {
        if (!list.empty() && event.text.unicode == 8)
        {
            toString();
            snapshot.setData(string);
            LinkedList<Letter>::iterator iter;
//            iter = list.rbegin();
//            if((*iter).getString() == '\n')
//                list.pop_back();
            list.pop_back();
            if(!list.empty())
                lastLetter = *list.rbegin();
            History::pushHistory({snapshot, this});
        } else if(event.text.unicode <= 126 && event.text.unicode != 8 && !checkState(LIMITED) && event.text.unicode != 10)
        {
//            std::cout<<event.text.unicode<<std::endl;
            toString();
            snapshot.setData(string);
            push_back((char)event.text.unicode);
            if(!checkState(LIMITED))
                History::pushHistory({snapshot, this});
        }
//        std::cout<<snapshot.data<<std::endl;


    }
}

void MultiText::update()
{

}

void MultiText::draw(sf::RenderTarget &window, sf::RenderStates states) const
{
    LinkedList<Letter>::iterator iter;
    if(!list.empty())
    {
        for(iter = list.begin(); iter != list.end(); ++iter)
        {
            window.draw(*iter);
        }
    }

}

void MultiText::push_back(char a)
{

    Letter letter;
    letter.setString(a);
    letter.setCharacterSize(characterSize);
    LinkedList<Letter>::iterator iter;
    iter = list.rbegin();

    if(list.empty())
    {
        letter.setPosition(position);
    }else
    {
//        if(a == '\n' || window.getSize().x < (*iter).getGlobalBounds().width + (*iter).getGlobalBounds().left + (*iter).getCharacterSize()/2)
//        {
//            letter.setPosition(position.x,(*iter).getPosition().y + lineSpace);
//        } else
        {
            letter.setPosition((*iter).getGlobalBounds().width + (*iter).getGlobalBounds().left, (*iter).getPosition().y);
        }
    }
    list.push_back(letter);
    lastLetter = *list.rbegin();
}

LinkedList<Letter>::iterator MultiText::begin() {
    return list.begin();
}

LinkedList<Letter>::iterator MultiText::end() {
    return list.end();
}

Snapshot &MultiText::getSnapshot()
{
    return snapshot;
}

void MultiText::applySnapshot(const Snapshot &snapshot)
{
//    std::cout<<"apply: "<<snapshot.data<<std::endl;
    //deleting letter
    if(list.getSize() > snapshot.getData().size())
    {
        list.pop_back();
        if(list.getSize() > 0)
            lastLetter = *list.rbegin();
    }
    //adding letter back to the list
    if(list.getSize() < snapshot.getData().size())
    {
        if(!list.empty())
        {
            LinkedList<Letter>::iterator iter;
            iter = list.rbegin();
            Letter letter;
            letter.setString(snapshot.getData()[snapshot.getData().size()-1]);
            letter.setPosition((*iter).getGlobalBounds().width + (*iter).getGlobalBounds().left, (*iter).getPosition().y);
            letter.setCharacterSize((*iter).getCharacterSize());
            list.push_back(letter);
        }else
        {
            Letter letter;
            letter.setString(snapshot.getData()[snapshot.getData().size()-1]);
            letter.setPosition(position);
            letter.setCharacterSize(characterSize);
            list.push_back(letter);
        }

        if(list.getSize() > 0)
            lastLetter = *list.rbegin();
    }

    std::cout<<std::endl;
}


void MultiText::setPosition(float x, float y)
{
    position = {x,y};
}

void MultiText::setCharacterSize(int size)
{
    characterSize = size;
}

Letter MultiText::getLastLetter() const{
    return lastLetter;
}

bool MultiText::empty() const {
    return list.empty();
}

int MultiText::getSize() const
{
    return list.getSize();
}

LinkedList<Letter>::iterator MultiText::rbegin() {
    return list.rbegin();
}

void MultiText::toString()
{
    string = "";
    LinkedList<Letter>::iterator iter = list.begin();
    for(;iter != end(); ++iter)
    {
        string +=(*iter).getString();
    }
}

int MultiText::getLineSpace() const {
    return lineSpace;
}

void MultiText::clear()
{
    list.clear();
}





