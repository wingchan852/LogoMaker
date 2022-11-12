//
// Created by Wing Yin Chan on 4/10/2021.
//

#ifndef TYPINGSFML_STATES_H
#define TYPINGSFML_STATES_H

#include <map>
#include "ObjectStates.h"

class States {
public:
    States();
    bool checkState(ObjectStates state) const;
    void disableState(ObjectStates state);
    void enableState(ObjectStates state);
private:
    std::map<ObjectStates, bool> states;
};


#endif //TYPINGSFML_STATES_H
