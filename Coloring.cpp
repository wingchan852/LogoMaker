//
// Created by Wing Yin Chan on 11/10/2021.
//

#include "Coloring.h"

Coloring::Coloring()
{
    operatorKey = "=-+/<>*!%&|:()[].^~?,";
    wordsKey["int"] = sf::Color::Blue;
    wordsKey["float"] = sf::Color::Blue;
    wordsKey["char"] = sf::Color::Blue;
    wordsKey["double"] = sf::Color::Blue;
}

bool Coloring::isNumber(Letter& letter)
{
    return isdigit(letter.getString()[0]);
}

bool Coloring::isOperator(Letter& letter)
{
    for(int i = 0; i < operatorKey.length(); i++)
    {
        if(letter.getString()[0] == operatorKey[i])
        {
            return true;
        }
    }
    return false;
}

void Coloring::ChangeColor(MultiText& multiText)
{
    LinkedList<Letter>::iterator begin = multiText.begin();
    std::string text;
    iter = begin;
    firstLetter = begin;
    LinkedList<Letter>::iterator iter2;

    while(iter != multiText.end())
    {
        while(iter != multiText.end() && (*iter).getString() != " ")
        {
            text += (*iter).getString();
            ++iter;
        }

        if(wordsKey[text] == sf::Color::Blue)
        {
            for(; firstLetter != iter; ++firstLetter)
            {
                (*firstLetter).setFillColor(wordsKey[text]);
            }
        }
        else
        {
            for(; firstLetter != iter; ++firstLetter)
            {
                (*firstLetter).setFillColor(sf::Color::White);
            }
        }
        text = "";
        if(iter != multiText.end())
            ++iter;
    }

    for(; begin != multiText.end(); ++begin)
    {
        if(isNumber(*(begin)))
            (*begin).setFillColor(sf::Color::Red);
        if(isOperator((*begin)))
            (*begin).setFillColor(sf::Color::Green);
    }


//    for(; iter != end; ++iter)
//    {
//        text += (*iter).getString();
////        std::cout << "text: " << text << std::endl;
//
//        while(i < text.size())
//        {
////            int initialPos = 0;
//            lastPos = i;
//            std::cout<<"initial pos: "<<initialPos<<std::endl;
//            std::cout<<"lastPos: "<<lastPos<<std::endl;
//            std::cout<<"i: "<<i<<std::endl;
//            if(text[i] == ' ')
//            {
//                std::cout<<i<<": SPACE"<<std::endl;
////                std::cout<<"text substr: "<<text.substr(0, i - 1);
//                if(wordsKey[text.substr(initialPos, lastPos - initialPos)] == sf::Color::Blue)
//                {
//                    std::cout<<i<<": CHECKED"<<std::endl;
//                    last = firstLetter;
//                    std::advance(last, text.substr(initialPos, lastPos - initialPos).size());
////                    if((*last).getString() == ' ')
////                        std::cout<<"SPACE"<<std::endl;
//                    for(; firstLetter != last; ++firstLetter)
//                    {
////                        std::cout<<(*firstLetter).getString()[0]<<std::endl;
//                        (*firstLetter).setFillColor(wordsKey[text.substr(initialPos, lastPos - initialPos)]);
//                    }
//                } else
//                {
//                    last = firstLetter;
//                    std::advance(last, text.substr(initialPos, lastPos - initialPos).size());
//                    for(; firstLetter != last; ++firstLetter)
//                    {
////                        std::cout<<(*firstLetter).getString()[0]<<std::endl;
//                        (*firstLetter).setFillColor(sf::Color::White);
//                    }
//                }
//                initialPos = lastPos+1;
//                firstLetter = ++last;
//            }
//            i++;
//        }
//    }

}


