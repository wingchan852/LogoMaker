//
// Created by Wing Yin Chan on 2/11/2021.
//

#include "Image.h"

std::map<Image::images, sf::Texture> Image::image;


void Image::loadTexture(images images)
{
    image[images].loadFromFile(getImagePath(images));
}

std::string Image::getImagePath(Image::images images) {
    switch (images)
    {
        case FILE: return "Image/file.png";
        case FOLDER: return "Image/folder.png";
    }
}

sf::Texture &Image::getTexture(Image::images images) {
    loadTexture(images);
    return image[images];
}
