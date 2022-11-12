//
// Created by Wing Yin Chan on 21/11/2021.
//

#ifndef TYPINGSFML_LOGOMAKER_H
#define TYPINGSFML_LOGOMAKER_H
#include <SFML/Graphics.hpp>
#include "Slider.h"
#include "Logo.h"
#include "TextInput.h"
#include "History.h"
#include "ColorPicker.h"
#include "DropdownMenu.h"
#include "MenuBar.h"
#include "WindowDialog.h"
#include <fstream>
#include <vector>
class LogoMaker {
public:
    LogoMaker();
    void run();

private:
    sf::RenderWindow window;
    Slider textOpacity;
    Slider shadowOpacity;
    Slider textXAxis;
    Slider textYAxis;
    Slider shadowXAxis;
    Slider shadowYAxis;
    Slider fontSize;
    Slider backgroundOpacity;
    Slider skew;
    Logo logo;
    TextInput textInput;
    ColorPicker fontColor;
    ColorPicker backgroundColor;
    DropdownMenu fontMenu;
    Label fontLabel;
    Label backgroundLabel;
    MenuBar menuBar;
    WindowDialog newWindow;
    void update();
    void applyChange(std::string state, std::vector<std::string> info);
//    std::ofstream myFile;
//    std::ifstream myFile;
//    std::vector<std::string> info;
};


#endif //TYPINGSFML_LOGOMAKER_H
