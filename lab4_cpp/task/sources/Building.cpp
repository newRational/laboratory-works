#include "Building.h"

Building::Building(): id(0), numberOfRooms(0), rooms(nullptr) {}

Building::Building(int id, int numberOfRooms, Room *rooms):
id(id), numberOfRooms(numberOfRooms), rooms(rooms) {}

Building::Building(const Building &other):
id(other.id), numberOfRooms(other.numberOfRooms), rooms(new Room[other.numberOfRooms]) {
    copy(other.begin(), other.end(), begin());
}

Building::Building(Building&& other):
id(other.id), numberOfRooms(other.numberOfRooms), rooms(other.rooms) {
    other.rooms = nullptr;
    other.numberOfRooms = 0;
    other.id = 0;
}

void Building::operator=(const Building &other) {
    delete[] rooms;
    id = other.id;
    numberOfRooms = other.numberOfRooms;
    rooms = new Room[numberOfRooms];
    copy(other.begin(), other.end(), begin());
}

void Building::operator=(Building &&other) {
    delete[] rooms;
    id = other.id;
    numberOfRooms = other.numberOfRooms;
    rooms = other.rooms;

    other.rooms = nullptr;
    other.numberOfRooms = 0;
    other.id = 0;
}

Building::~Building() {
    delete[] rooms;
}

Room *Building::begin() {
    return rooms;
}

const Room *Building::begin() const {
    return rooms;
}

Room *Building::end() {
    return rooms + numberOfRooms;
}

const Room *Building::end() const {
    return rooms + numberOfRooms;
}


int Building::getId() {
    return id;
}

void Building::getInfoAboutRooms() {
    cout << "Суммарная площадь: " << getArea() << endl;
    cout << "Помещения" << endl;
    for (int i = 0; i < numberOfRooms; i++) {
        rooms[i].showInfo();
        cout << endl;
    }
}

double Building::getArea() {
    double sumArea = 0;
    for (int i = 0; i < numberOfRooms; i++)
        sumArea += rooms[i].getArea();
    return sumArea;
}

int Building::getNumberOfRooms() {
    return numberOfRooms;
}

void Building::setId(int id) {
    this->id = id;
}

void Building::setNumberOfRooms(int numberOfRooms) {
    this->numberOfRooms = numberOfRooms;
}

void Building::setRooms(Room *rooms) {
    this->rooms = rooms;
}
