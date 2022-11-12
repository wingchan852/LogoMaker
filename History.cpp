//
// Created by Wing Yin Chan on 10/10/2021.
//

#include "History.h"
#include <iostream>
std::stack<HistoryNode> History::stack;

void History::pushHistory(const HistoryNode &snapshot)
{
    stack.push(snapshot);
//    std::cout<<"stack size: "<<stack.size()<<std::endl;
}

HistoryNode &History::topHistory()
{
//    std::cout<<stack.top().snapshot.getValue()<<std::endl;
    return stack.top();
}

void History::popHistory()
{
    if(!stack.empty())
        stack.pop();
//    std::cout<<"stack size after: "<<stack.size()<<std::endl;

}

void History::addEventHandler(sf::RenderWindow &window, sf::Event event)
{
    if(KeyShortcuts::isUndo())
    {
        if(!stack.empty())
        {
            topHistory().component->applySnapshot(topHistory().snapshot);
            popHistory();
        }
    }
}

bool History::empty() {
    return stack.empty();
}
