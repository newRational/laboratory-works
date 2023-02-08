#ifndef LAB4_CPP_APARTMENT_H
#define LAB4_CPP_APARTMENT_H

#include "Habitation.h"
#include "FlatAddress.h"
#include "Room.h"

#include <iostream>
#include <string>

using namespace std;

class Apartment: public Habitation {
private:
    FlatAddress flatAddress;
    int numberOfRooms;
    Room *rooms;
public:
    Apartment();
    Apartment(FlatAddress &, int, Room *);

    Apartment(const Apartment&);
    Apartment(Apartment&&);
    void operator=(const Apartment&);
    void operator=(Apartment&&);

    ~Apartment();

    Room *begin();
    Room *end();
    const Room *begin() const;
    const Room *end() const;

    void showInfo() override;
    Type getType() override;
    Address &getAddress() override;
    double getArea() override;
};

#endif
