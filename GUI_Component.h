//
// Created by Wing Yin Chan on 5/10/2021.
//

#ifndef TYPINGSFML_GUI_COMPONENT_H
#define TYPINGSFML_GUI_COMPONENT_H

#include "States.h"
#include "EventHandler.h"
#include "SnapshotInterface.h"

class GUI_Component : public States, public EventHandler, public SnapshotInterface, public sf::Drawable{
public:
//from the sf::Drawable class
    virtual void draw(sf::RenderTarget& window, sf::RenderStates states) const = 0;

// from EventHandler
    virtual void addEventHandler(sf::RenderWindow& window, sf::Event event) = 0;
    virtual void update() = 0;

//from SnapshotInterface
    virtual Snapshot& getSnapshot() = 0;
    virtual void applySnapshot(const Snapshot& snapshot) = 0;
};


#endif //TYPINGSFML_GUI_COMPONENT_H
