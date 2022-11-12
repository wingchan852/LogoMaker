//
// Created by Wing Yin Chan on 2/11/2021.
//

#ifndef TYPINGSFML_IMAGE_H
#define TYPINGSFML_IMAGE_H
#include <SFML/Graphics.hpp>

class Image {
public:
    enum images {FOLDER, FILE};
    static void loadTexture(images images);
    static sf::Texture& getTexture(images images);
private:
    static std::map<images, sf::Texture> image;
    static std::string getImagePath(images images);
};


#endif //TYPINGSFML_IMAGE_H
