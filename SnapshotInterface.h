//
// Created by Wing Yin Chan on 4/10/2021.
//

#ifndef TYPINGSFML_SNAPSHOTINTERFACE_H
#define TYPINGSFML_SNAPSHOTINTERFACE_H
#include "Snapshot.h"

class SnapshotInterface : public Snapshot{
public:
    // this function will return a snapshot of the object's current state
    virtual Snapshot& getSnapshot() = 0;

// this function will apply a snapshot to the object.
//This will revert the object back to the state that has been recorded in the snapshot
    virtual void applySnapshot(const Snapshot& snapshot) = 0;
};


#endif //TYPINGSFML_SNAPSHOTINTERFACE_H
