//
// Created by Wing Yin Chan on 21/11/2021.
//

#include "LogoMaker.h"


LogoMaker::LogoMaker() : window(sf::VideoMode(2000,1500), "My window"),
textOpacity("Text Opacity: ", 255, {250, 1000}, 250),
shadowOpacity("ShadowOpacity: ", 255, {298, 1070}, 100),
textXAxis("Text X-Axis: ", 1500, {230, 1280}, 500),
textYAxis("Text Y-Axis: ", 1500, {230, 1350}, 700),
shadowXAxis("Shadow X-Axis: ", 1500, {280, 1140}, 500),
shadowYAxis("Shadow Y-Axis: ", 1500, {280, 1210}, 960),
backgroundOpacity("Background Opacity: ", 255, {1100, 1070}, 250),
fontSize("Front Size: ", 300, {947, 1000}, 100),
skew("Skew: ", 150, {1470, 1000}, 28),
backgroundColor(sf::Color::White),
newWindow({1000,700})
{
    window.setFramerateLimit(60);
    textInput.setLabel("Text: ");
    textInput.setLabelSize(30);
    textInput.setBoxLength(800);
//    textInput.setPosition(0, 700);
    textInput.setInputBoxPosition({50, 850});
    textInput.setLabelPosition({50, 800});

    fontColor.setPosition({900, 850});
    backgroundColor.setOutlineColor(sf::Color::White);
    backgroundColor.setPosition({1470, fontColor.getPosition().y});

    fontMenu.addItem("Open Sans");
    fontMenu.addItem("Josefin Sans");
    fontMenu.addItem("Marlboro");
    fontMenu.addItem("Bebas Neue");
    fontMenu.setPosition(1000, 855);

    fontLabel.setString("Font Settings");
    fontLabel.setPosition(fontColor.getPosition().x, fontColor.getPosition().y - fontLabel.getGlobalBounds().height/2);
    fontLabel.setCharacterSize(30);

    backgroundLabel.setString("Background color");
    backgroundLabel.setPosition(backgroundColor.getPosition().x + backgroundColor.getGlobalBounds().width + 30, fontMenu.getGlobalBounds().height + fontMenu.getGlobalBounds().top - backgroundLabel.getGlobalBounds().height/2);
    backgroundLabel.setCharacterSize(30);

    menuBar.addMenu("File");
    menuBar.addItem("File", "Close Project");
    menuBar.addItem("File", "New Project");
    menuBar.addItem("File", "Open Project");
    menuBar.addItem("File", "Save Project");
    menuBar.addItem("File", "Quit");
    menuBar.addMenu("Edit");
    menuBar.addItem("Edit", "Redo");
    menuBar.addItem("Edit", "Undo");
    menuBar.addMenu("Render");
    menuBar.addItem("Render", "Export Image");
    menuBar.setPosition(0,0);

    menuBar.reset("Render");
    menuBar.reset("File");

    fontMenu.setInitialValue("Open Sans");

    std::ifstream myFile;
    myFile.open("save/save.txt");
    std::string state;
    std::vector<std::string> v;
    getline(myFile, state);
    if(state == "save")
    {
        while(getline(myFile, state))
        {
            v.push_back(state);
        }
        applyChange("save", v);
    }
    myFile.close();
}

void LogoMaker::run()
{
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
            if(menuBar.getClickItem("File") == "Quit")
                window.close();
            else if(menuBar.getClickItem("File") == "Open Project")
            {
                newWindow.run();


                std::ifstream myFile;
                std::vector<std::string>v;
                myFile.open("logo/logo.txt");
                std::string text;
                while(getline(myFile, text))
                    v.push_back(text);
                myFile.close();
                applyChange("save", v);
                menuBar.reset("File");
            }
            else if(menuBar.getClickItem("Render") == "Export Image")
            {
                logo.exportImage("logo.png");
                menuBar.reset("Render");

            }
            else if(menuBar.getClickItem("File") == "Save Project")
            {
                std::ofstream myFile;
                myFile.open("save/save.txt");

                myFile<<"save\n";
                myFile<<textInput.getText()<<"\n";
                myFile<<textXAxis.getValue()<<"\n";
                myFile<<textYAxis.getValue()<<"\n";
                myFile<<fontSize.getValue()<<"\n";
                myFile<<shadowXAxis.getValue()<<"\n";
                myFile<<shadowYAxis.getValue()<<"\n";
                myFile<<skew.getValue()<<"\n";
                myFile<<fontMenu.getValue()<<"\n";
                myFile<<fontColor.getColor().toInteger()<<"\n";
                myFile<<backgroundColor.getColor().toInteger()<<"\n";
                myFile<<shadowOpacity.getValue()<<"\n";
                myFile<<textOpacity.getValue()<<"\n";
                myFile<<backgroundOpacity.getValue()<<"\n";
                myFile.close();
                menuBar.reset("File");
            }
            else if(menuBar.getClickItem("File") == "New Project")
            {
                std::ifstream myFile;
                std::vector<std::string>v;
                myFile.open("save/initial.txt");
                std::string text;
                while(getline(myFile, text))
                    v.push_back(text);
                myFile.close();
                menuBar.reset("File");
               applyChange("new", v);

                std::ofstream ofs;
                ofs.open("save/save.txt", std::ofstream::out | std::ofstream::trunc);
                ofs.close();
            }
            else if(menuBar.getClickItem("File") == "Close Project")
            {
                std::ifstream myFile;
                std::vector<std::string>v;
                myFile.open("save/initial.txt");
                std::string text;
                while(getline(myFile, text))
                    v.push_back(text);
                myFile.close();
                menuBar.reset("File");
                applyChange("new", v);
            }
            else if(menuBar.getClickItem("Edit") == "Undo")
            {
                if(!History::empty())
                {
                    History::topHistory().component->applySnapshot(History::topHistory().snapshot);
                    History::popHistory();
                }
            }

            textOpacity.addEventHandler(window, event);
            shadowOpacity.addEventHandler(window, event);
            textXAxis.addEventHandler(window, event);
            textYAxis.addEventHandler(window, event);
            shadowXAxis.addEventHandler(window, event);
            shadowYAxis.addEventHandler(window, event);
            textInput.addEventHandler(window,event);
            backgroundOpacity.addEventHandler(window, event);
            skew.addEventHandler(window, event);
            fontColor.addEventHandler(window, event);
            backgroundColor.addEventHandler(window, event);
            fontSize.addEventHandler(window, event);
            fontMenu.addEventHandler(window, event);
            menuBar.addEventHandler(window, event);
            History::addEventHandler(window, event);
        }

        textOpacity.update();
        shadowOpacity.update();
        textXAxis.update();
        textYAxis.update();
        shadowXAxis.update();
        shadowYAxis.update();
        backgroundOpacity.update();
        skew.update();
        fontColor.update();
        fontSize.update();
        backgroundColor.update();
        textInput.update();
        fontMenu.update();
        menuBar.update();
        logo.create();
        update();

        window.clear();
        window.draw(logo.getSprite());
        window.draw(textOpacity);
        window.draw(shadowOpacity);
        window.draw(textXAxis);
        window.draw(textYAxis);
        window.draw(shadowXAxis);
        window.draw(shadowYAxis);
        window.draw(fontSize);
        window.draw(backgroundOpacity);
        window.draw(skew);
        window.draw(textInput);
        window.draw(fontColor);
        window.draw(fontMenu);
        window.draw(backgroundColor);
        window.draw(fontLabel);
        window.draw(backgroundLabel);
        window.draw(menuBar);
        window.display();
    }
}

void LogoMaker::update()
{
    logo.setString(textInput.getText());
    logo.setLogoXAxis(textXAxis.getValue());
    logo.setLogoYAxis(textYAxis.getValue());
    logo.setCharacterSize(fontSize.getValue());
    logo.setShadowXAxis(shadowXAxis.getValue());
    logo.setShadowYAxis(shadowYAxis.getValue());
    logo.setSkew(skew.getValue());
    logo.setFont(fontMenu.getValue());
    logo.setTextColor(fontColor.getColor());
    logo.setBackgroundColor(backgroundColor.getColor());
    logo.setShadowOpacity(shadowOpacity.getValue());
    logo.setTextOpacity(textOpacity.getValue());
    logo.setBackgroundOpacity(backgroundOpacity.getValue());

}

void LogoMaker::applyChange(std::string state, std::vector<std::string> info)
{

    if(state == "save")
    {
        textInput.clear();
        textInput.setText(info[0]);
    }
    else
        textInput.clear();
    textXAxis.setValue(info[1]);
    textYAxis.setValue(info[2]);
    fontSize.setValue(info[3]);
    shadowXAxis.setValue(info[4]);
    shadowYAxis.setValue(info[5]);
    skew.setValue(info[6]);
    fontMenu.setInitialValue(info[7]);
    fontColor.setColor(info[8]);
    backgroundColor.setColor(info[9]);

    shadowOpacity.setValue(info[10]);
    textOpacity.setValue(info[11]);
    backgroundOpacity.setValue(info[12]);

}
