#include "Cottage.h"

Cottage::Cottage(): address(Address()), numberOfBuildings(0), buildings(nullptr) {}

Cottage::Cottage(Address &address, int numberOfBuildings, Building *buildings):
        address(address), numberOfBuildings(numberOfBuildings), buildings(buildings) {}

Cottage::Cottage(const Cottage &other):
    address(other.address),
    numberOfBuildings(other.numberOfBuildings),
    buildings(new Building[other.numberOfBuildings]) {
    copy(other.begin(), other.end(), begin());
}

Cottage::Cottage(Cottage&& other):
        address(other.address), numberOfBuildings(other.numberOfBuildings), buildings(other.buildings) {
    other.buildings = nullptr;
    other.numberOfBuildings = 0;
}

void Cottage::operator=(const Cottage &other) {
    delete[] buildings;
    address = other.address;
    numberOfBuildings = other.numberOfBuildings;
    buildings = new Building[other.numberOfBuildings];
    copy(other.begin(), other.end(), begin());
}

void Cottage::operator=(Cottage &&other) {
    delete[] buildings;
    address = other.address;
    numberOfBuildings = other.numberOfBuildings;
    buildings = other.buildings;

    other.buildings = nullptr;
    other.numberOfBuildings = 0;
}

Cottage::~Cottage() {
    delete[] buildings;
}

Building *Cottage::begin() {
    return buildings;
}

const Building *Cottage::begin() const {
    return buildings;
}

Building *Cottage::end() {
    return buildings + numberOfBuildings;
}

const Building *Cottage::end() const {
    return buildings + numberOfBuildings;
}

void Cottage::showInfo() {
    cout << "Коттедж" << endl;
    cout << "Суммарная площадь: " << getArea() << endl << endl;
    cout << "Адрес" << endl;
    address.showAddress();
    cout << endl;
    cout << "Строения" << endl;
    for (int i = 0; i < numberOfBuildings; i++) {
        cout << "Номер строения: " << buildings[i].getId() << endl;
        buildings[i].getInfoAboutRooms();
    }
}

Type Cottage::getType() {
    return COTTAGE;
}

Address &Cottage::getAddress() {
    return address;
}

double Cottage::getArea() {
    double sumArea = 0;
    for (int i = 0; i < numberOfBuildings; i++)
        sumArea += buildings[i].getArea();
    return sumArea;
}