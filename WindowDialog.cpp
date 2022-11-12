//
// Created by Wing Yin Chan on 28/11/2021.
//

#include "WindowDialog.h"

WindowDialog::WindowDialog() : WindowDialog({500,500})
{

}
WindowDialog::WindowDialog(sf::Vector2i size) : size(size), openBtn("OPEN"), cancelBtn("CANCEL")
{
    enableState(HIDDEN);
}

void WindowDialog::run()
{
        window.create({static_cast<unsigned int>(size.x), static_cast<unsigned int>(size.y), 32}, "Display Dialog");
        openBtn.setBoxSize({200, 70});
        cancelBtn.setBoxSize({200, 70});
        openBtn.setPosition(window.getSize().x - openBtn.getGlobalBounds().width - 30, window.getSize().y - openBtn.getGlobalBounds().height - 30);
        cancelBtn.setPosition(window.getSize().x - openBtn.getGlobalBounds().width - 30 - openBtn.getGlobalBounds().width - 30,window.getSize().y - cancelBtn.getGlobalBounds().height - 30);
        openBtn.setBoxColor(sf::Color(58,58,58));
        cancelBtn.setBoxColor(sf::Color(58,58,58));

        fileTree.push("Files", "logo.txt");

        while(window.isOpen())
        {
            sf::Event event;
            while(window.pollEvent(event))
            {
                if(event.type == sf::Event::Closed)
                {
                    window.close();
                    enableState(HIDDEN);
                    disableState(APPLY);
                }
                if(MouseEvents<Item>::mouseClicked(openBtn, window))
                {
                    enableState(APPLY);
                    clickItem = fileTree.getClickedItem();
                    window.close();
                    enableState(HIDDEN);
                }
                if(MouseEvents<Item>::mouseClicked(cancelBtn, window))
                {
                    disableState(APPLY);
                    window.close();
                    enableState(HIDDEN);
                }
//                if(MouseEvents<FileItem>::mouseClicked(fileTree.getClickedItem(), window))
//                {
//
//                }
                fileTree.addEventHandler(window, event);
            }

            window.clear();
            window.draw(openBtn);
            window.draw(cancelBtn);
            window.draw(fileTree);
            window.display();
        }
}

std::string WindowDialog::getClickItem() {
    return clickItem;
}

