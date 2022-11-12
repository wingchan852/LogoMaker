//
// Created by Wing Yin Chan on 13/10/2021.
//

#ifndef TYPINGSFML_HISTORYNODE_H
#define TYPINGSFML_HISTORYNODE_H

#include "GUI_Component.h"

struct HistoryNode
{
    Snapshot snapshot;
    GUI_Component* component;
};

#endif //TYPINGSFML_HISTORYNODE_H
