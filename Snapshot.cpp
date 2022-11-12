//
// Created by Wing Yin Chan on 4/10/2021.
//

#include "Snapshot.h"

void Snapshot::setData(std::string string)
{
    data = string;
}

std::string Snapshot::getData() const
{
    return data;
}

void Snapshot::setValue(int value)
{
    this->value = value;
}

int Snapshot::getValue() const
{
    return value;
}
