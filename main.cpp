#include <iostream>
//#include "TextInput.h"
//#include "History.h"
//#include "DropdownMenu.h"
//#include "MenuBar.h"
//#include "FileTree.h"
//#include "Slider.h"
//#include "Logo.h"
#include "LogoMaker.h"
#include "ColorOption.h"

void convertToRGB(sf::VertexArray& arr, int h)
{
    for(int i = 0; i < 470; i++)
    {
        for(int j = 0; j < 470; j++)
        {
            double s = j/470.0;
            double v = i/470.0;
            int hi = h/60;
            double f = (h/60 - hi);
            double p = v * ( 1 - s)  * 255;
            double q = v * ( 1 - s * f)  * 255;
            double t = v * (1 - s * (1 - f))  * 255;

            switch (hi) {
                case 0:
                    arr[i * 470 + j].color = sf::Color(v * 255,t,p);
                    break;
                case 1:
                    arr[i * 470 + j].color = sf::Color(q,v * 255,p);
                    break;
                case 2:
                    arr[i * 470 + j].color = sf::Color(p,v * 255,t);
                    break;
                case 3:
                    arr[i * 470 + j].color = sf::Color(p,q,v * 255);
                    break;
                case 4:
                    arr[i * 470 + j].color = sf::Color(t,p,v * 255);
                    break;
                case 5:
                    arr[i * 470 + j].color = sf::Color(v * 255,p,q);
                    break;

            }
        }
    }
}
sf::Color getColor(sf::Vector2i coordinate, sf::VertexArray& colors, sf::Vector2i position)
{
    return colors[(coordinate.x - position.x) + (coordinate.y - position.y) * 470].color;
}

int main() {
    LogoMaker logoMaker;
    logoMaker.run();
//    sf::RenderWindow window(sf::VideoMode(2000, 1200), "My window"); //2700, 1200
//    window.setFramerateLimit(60);
//    Logo logo;
//    sf::RenderTexture texture;
//    if (!texture.create(2000, 500))
//        return -1;
//
//    ColorOption option;
////
//    sf::RectangleShape rect;
//    rect.setSize({400,400});
//    rect.setFillColor(sf::Color::Yellow);
//    rect.setPosition(700,700);
////
//    sf::VertexArray color(sf::Points, 470 * 470);
//    for(int i = 0; i < 470; i++) {
//        for (int j = 0; j < 470; j++) {
//            color[i * 470 + j].position = sf::Vector2f(j + 400, i + 400);
//        }
//    }

//    Logo logo;
//    logo.setString("Hello World");
//    logo.setCharacterSize(70);
//    logo.setLogoXAxis(100);
//    logo.setLogoYAxis(100);
//    logo.setTextColor(sf::Color::Red);
//    logo.setBackgroundColor(sf::Color::Blue);

//    Slider slider;
//    slider.setPosition({500,700});
//    sf::RenderTexture renderTexture;
//    if(!renderTexture.create(2000, 500))
//    {
//        return -1;
//    }
//    sf::Text text;
//    text.setFont(Fonts::getFont());
//    text.setString("Hello");
//    text.setCharacterSize(70);
//    text.setPosition({100,100});
//    text.setFillColor(sf::Color::White);
//    FileItem item("file", Image::FILE, {100,100});
        ///file tree
//    FileTree tree;
//    tree.push("directory1", "file1");
//    tree.push("directory1", "file2");
//    tree.push("directory1", "folder1");
//    tree.push("directory1", "folder2");
//    tree.push("folder2", "text1");
//    tree.push("folder1", "folder3");
//    tree.push("folder3", "text2");
//    tree.push("folder3", "text4");
//    tree.push("folder3", "hello");
//    tree.push("folder3", "world");
//    tree.push("directory2", "text7");
//    tree.push("text2", "hi");





///    testInput
//    TextInput ti;
//    ti.setLabel("First Name: ");
//    ti.setPosition(500, 500);
//    ti.setLabelSize(120);

//
//    sf::Sprite sprite(logo.getTexture());
//
//
//    while (window.isOpen())
//    {
//        sf::Event event;
//        while (window.pollEvent(event))
//        {
//            if (event.type == sf::Event::Closed)
//                window.close();
//            if(MouseEvents<sf::RectangleShape>::mouseClicked(window, event))
//            {
////                std::cout<<"x: "<<sf::Mouse::getPosition(window).x<<std::endl;
////                std::cout<<"y: "<<sf::Mouse::getPosition(window).y<<std::endl;
//                rect.setFillColor(getColor((sf::Vector2i) sf::Mouse::getPosition(window), color, {400 ,400}));
//            }
//            slider.addEventHandler(window, event);
//            tree.addEventHandler(window, event);
//            item.addEventHandler(window, event);
//            ti.addEventHandler(window,event);
//            menuBar.addEventHandler(window, event);
//            dropdownMenu.addEventHandler(window, event);
//            History::addEventHandler(window, event);

        }
//        ti.update();
//        menuBar.update();
//        dropdownMenu.update();
//        tree.update();
//            logo.create();
//        texture.clear();
//        texture.draw(rect);
//
//        texture.display();
//        renderTexture.getTexture().copyToImage().saveToFile("logo/logo.png");
//        convertToRGB(color, 0);
//        window.clear();
//        window.draw(color);
//        window.draw(rect);
//        window.draw(option);
//        window.draw(sprite);
//        window.draw(slider);
//        window.draw(item);
//        window.draw(tree);
//        window.draw(ti);
//        window.draw(menuBar);
//        window.draw(dropdownMenu);
//        sf::Sprite sprite(texture.getTexture());
//        window.draw(sprite);
//        window.display();
//    }
//    return 0;
//}


