//
// Created by Wing Yin Chan on 23/9/2021.
//

#ifndef TYPINGSFML_FONTS_H
#define TYPINGSFML_FONTS_H
#include <SFML/Graphics.hpp>

class Fonts {
public:
    enum fonts{ OPENSANS, BEBASNEUE, JOSEFINSANS, MARLBORO };
    static sf::Font& getFont(Fonts::fonts fonts);
private:
//    static sf::Font font;
    static std::map<fonts, sf::Font> font;
    static void loadFont(Fonts::fonts fonts);
    static bool hasLoaded;
    static std::string getFontPath(fonts fonts);
};


#endif //TYPINGSFML_FONTS_H
