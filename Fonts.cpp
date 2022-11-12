//
// Created by Wing Yin Chan on 23/9/2021.
//

#include "Fonts.h"
//sf::Font Fonts::font;
std::map<Fonts::fonts, sf::Font> Fonts::font;
bool Fonts::hasLoaded = false;
sf::Font &Fonts::getFont(Fonts::fonts fonts)
{
    loadFont(fonts);
    return font[fonts];
}

void Fonts::loadFont(Fonts::fonts fonts)
{
    font[fonts].loadFromFile(getFontPath(fonts));
//    if(!hasLoaded)
//    {
//        if(!font.loadFromFile("OpenSans-Bold.ttf"))
//        {
//            exit(1);
//        }
//        hasLoaded = true;
//    }
}

std::string Fonts::getFontPath(Fonts::fonts fonts) {
    switch (fonts)
    {
        case OPENSANS: return "Fonts/OpenSans-Bold.ttf";
        case BEBASNEUE: return "Fonts/BebasNeue-Regular.ttf";
        case JOSEFINSANS: return "Fonts/JosefinSans.ttf";
        case MARLBORO: return "Fonts/Marlboro.ttf";

    }
}

