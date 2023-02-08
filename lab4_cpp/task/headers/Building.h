#ifndef LAB4_CPP_BUILDING_H
#define LAB4_CPP_BUILDING_H

#include "Room.h"

#include <iostream>
#include <string>

using namespace std;

class Building {
private:
    int id;
    int numberOfRooms;
    Room *rooms;
public:
    Building();
    Building(int, int, Room *);

    Building(const Building&);
    Building(Building&&);
    void operator=(const Building&);
    void operator=(Building&&);

    ~Building();

    Room *begin();
    Room *end();
    const Room *begin() const;
    const Room *end() const;

    int getId();
    void getInfoAboutRooms();
    double getArea();
    int getNumberOfRooms();

    void setId(int id);
    void setNumberOfRooms(int numberOfRooms);
    void setRooms(Room *rooms);
};

#endif
