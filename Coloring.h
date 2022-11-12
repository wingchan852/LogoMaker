//
// Created by Wing Yin Chan on 11/10/2021.
//

#ifndef TYPINGSFML_COLORING_H
#define TYPINGSFML_COLORING_H
#include "MultiText.h"
#include <map>
class Coloring {
public:
    Coloring();
    bool isNumber(Letter& letter);
    bool isOperator(Letter& letter);
    void ChangeColor(MultiText& multiText);
private:
    std::string operatorKey;
    std::map<std::string, sf::Color> wordsKey;
    LinkedList<Letter>::iterator firstLetter;
    LinkedList<Letter>::iterator iter;
};


#endif //TYPINGSFML_COLORING_H
