//
// Created by Wing Yin Chan on 21/11/2021.
//

#ifndef TYPINGSFML_LOGO_H
#define TYPINGSFML_LOGO_H
#include <SFML/Graphics.hpp>
#include "Fonts.h"

class Logo{
public:
    Logo();
    void create();
    void setLogoXAxis(int x);
    void setLogoYAxis(int y);
    void setShadowXAxis(int x);
    void setShadowYAxis(int y);
    void setSkew(double num);
    void setString(std::string string);
    void setCharacterSize(int size);
    void setTextOpacity(int opacity);
    void setShadowOpacity(int opacity);
    void setBackgroundColor(sf::Color color);
    void setBackgroundColor(int num);
    void setFont(std::string font);
    void setBackgroundOpacity(int opacity);
    void exportImage(std::string name);

    void loadTexture(std::string name);
    sf::Texture& getTexture();
    void setTextColor(sf::Color color);
    void setTextColor(int num);
    sf::Text& getLogo();
    sf::Sprite& getSprite();
    sf::Text& getShadow();

private:
    sf::RenderTexture renderTexture;
    sf::Text logo;
    sf::Text shadow;
    sf::Color backgroundColor;
    sf::Sprite sprite;
    sf::Texture texture;

};


#endif //TYPINGSFML_LOGO_H
