//
// Created by Wing Yin Chan on 23/11/2021.
//

#include "ColorGradient.h"
ColorGradient::ColorGradient() : ColorGradient(0, {0,0}, 256)
{

}

ColorGradient::ColorGradient(int hue, sf::Vector2i position, int size) : color(sf::Points, size * size)
{
    this->size = size;
    this->position = position;
    for(int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            color[i * size + j].position = sf::Vector2f(j + position.x, i + position.y);
        }
    }
    setColor(hue);
}
void ColorGradient::setColor(int hue)
{
    for(int i = 0; i < size; i++)
    {
        for(int j = 0; j < size; j++)
        {
            double s = j/(float)size;
            double v = i/(float)size;
            int hi = hue/60;
            double f = (hue/60 - hi);
            double p = v * ( 1 - s)  * 255;
            double q = v * ( 1 - s * f)  * 255;
            double t = v * (1 - s * (1 - f))  * 255;

            switch (hi) {
                case 0:
                    color[i * size + j].color = sf::Color(v * 255,t,p);
                    break;
                case 1:
                    color[i * size + j].color = sf::Color(q,v * 255,p);
                    break;
                case 2:
                    color[i * size + j].color = sf::Color(p,v * 255,t);
                    break;
                case 3:
                    color[i * size + j].color = sf::Color(p,q,v * 255);
                    break;
                case 4:
                    color[i * size + j].color = sf::Color(t,p,v * 255);
                    break;
                case 5:
                    color[i * size + j].color = sf::Color(v * 255,p,q);
                    break;

            }
        }
    }
}

sf::Color ColorGradient::getColor(sf::Vector2i coordinate)
{
    return color[(coordinate.x - position.x) + (coordinate.y - position.y) * size].color;
}

void ColorGradient::setPosition(sf::Vector2i position)
{
    this->position = position;
    for(int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            color[i * size + j].position = sf::Vector2f(j + position.x, i + position.y);
        }
    }
}

void ColorGradient::draw(sf::RenderTarget &window, sf::RenderStates states) const
{
    window.draw(color);
}

void ColorGradient::addEventHandler(sf::RenderWindow &window, sf::Event event) {

}

void ColorGradient::update()
{

}

Snapshot &ColorGradient::getSnapshot()
{
}

void ColorGradient::applySnapshot(const Snapshot &snapshot)
{

}

sf::FloatRect ColorGradient::getGlobalBounds() const {
    return color.getBounds();
}

