#ifndef LAB4_CPP_FLAT_H
#define LAB4_CPP_FLAT_H

#include "Habitation.h"
#include "FlatAddress.h"
#include "Room.h"

#include <iostream>
#include <string>

using namespace std;

class Flat: public Habitation {
private:
    FlatAddress flatAddress;
    Room rooms[4];
public:
    Flat();
    Flat(FlatAddress &flatAddress, Room[4]);

    void showInfo() override;
    Type getType() override;
    Address &getAddress() override;
    double getArea() override;
};

#endif
