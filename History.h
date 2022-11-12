//
// Created by Wing Yin Chan on 10/10/2021.
//

#ifndef TYPINGSFML_HISTORY_H
#define TYPINGSFML_HISTORY_H

#include <SFML/Graphics.hpp>
#include "HistoryNode.h"
#include <stack>
#include "KeyShortcuts.h"
class History {
public:
    static void pushHistory(const HistoryNode& snapshot);
    static HistoryNode& topHistory();
    static void popHistory();
    static void addEventHandler(sf::RenderWindow& window, sf::Event event);
    static bool empty();

private:
    static std::stack<HistoryNode> stack;
};


#endif //TYPINGSFML_HISTORY_H
