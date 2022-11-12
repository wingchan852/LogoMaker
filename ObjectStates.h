//
// Created by Wing Yin Chan on 4/10/2021.
//

#ifndef TYPINGSFML_OBJECTSTATES_H
#define TYPINGSFML_OBJECTSTATES_H

#include <map>

    enum ObjectStates{
        HIDDEN,
        HIGHLIGHTED,
        BLINKING,
        LIMITED,
        CLICKED,
        DISABLED,
        SHOWED,
        HOVERED,
        APPLY,
        CHANGE,
        dragging,
        ///This should always be the last state
        LAST_STATE
    };



#endif //TYPINGSFML_OBJECTSTATES_H
