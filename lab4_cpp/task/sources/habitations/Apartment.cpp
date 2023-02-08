#include "Apartment.h"

Apartment::Apartment(): flatAddress(FlatAddress()), numberOfRooms(0), rooms(nullptr) {}

Apartment::Apartment(FlatAddress &flatAddress, int numberOfRooms, Room *rooms):
    flatAddress(flatAddress), numberOfRooms(numberOfRooms), rooms(rooms) {}

Apartment::Apartment(const Apartment &other):
    flatAddress(other.flatAddress),
    numberOfRooms(other.numberOfRooms),
    rooms(new Room[other.numberOfRooms])
{
    copy(other.begin(), other.end(), begin());
}

Apartment::Apartment(Apartment&& other):
    flatAddress(other.flatAddress),
    numberOfRooms(other.numberOfRooms),
    rooms(other.rooms)
{
    other.rooms = nullptr;
    other.numberOfRooms = 0;
}

void Apartment::operator=(const Apartment &other) {
    delete[] rooms;

    flatAddress = other.flatAddress;
    numberOfRooms = other.numberOfRooms;
    rooms = new Room[numberOfRooms];

    copy(other.begin(), other.end(), begin());
}

void Apartment::operator=(Apartment &&other) {
    delete[] rooms;

    flatAddress = other.flatAddress;
    numberOfRooms = other.numberOfRooms;
    rooms = other.rooms;

    other.rooms = nullptr;
    other.numberOfRooms = 0;
}

Apartment::~Apartment() {
    delete[] rooms;
}

Room *Apartment::begin() {
    return rooms;
}

const Room *Apartment::begin() const {
    return rooms;
}

Room *Apartment::end() {
    return rooms + numberOfRooms;
}

const Room *Apartment::end() const {
    return rooms + numberOfRooms;
}

void Apartment::showInfo() {
    cout << "Апартементы" << endl;
    cout << "Суммарная площадь: " << getArea() << endl << endl;
    cout << "Адрес" << endl;
    flatAddress.showAddress();
    cout << endl;
    cout << "Помещения" << endl;
    for (int i = 0; i < numberOfRooms; i++) {
        rooms[i].showInfo();
        cout << endl;
    }
}

Type Apartment::getType() {
    return APARTMENT;
}

Address &Apartment::getAddress() {
    return flatAddress;
}

double Apartment::getArea() {
    double sumArea = 0;
    for (int i = 0; i < numberOfRooms; i++)
        sumArea += rooms[i].getArea();
    return sumArea;
}