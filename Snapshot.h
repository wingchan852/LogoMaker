//
// Created by Wing Yin Chan on 4/10/2021.
//

#ifndef TYPINGSFML_SNAPSHOT_H
#define TYPINGSFML_SNAPSHOT_H

#include <SFML/Graphics.hpp>
#include <string>
class Snapshot{
public:
    void setData(std::string string);
    std::string getData() const;
    void setValue(int value);
    int getValue() const;
private:
    std::string data;
    int value;
};


#endif //TYPINGSFML_SNAPSHOT_H
