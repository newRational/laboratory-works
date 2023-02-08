#include "Flat.h"

Flat::Flat(): flatAddress(FlatAddress()) {}

Flat::Flat(FlatAddress &flatAddress, Room *rooms): flatAddress(flatAddress) {
    for (int i = 0; i < 4; i++)
        (this->rooms)[i] = rooms[i];
}

void Flat::showInfo() {
    cout << "Квартира" << endl;
    cout << "Суммарная площадь: " << getArea() << endl << endl;
    cout << "Адрес" << endl;
    flatAddress.showAddress();
    cout << endl;
    cout << "Помещения" << endl;
    for (int i = 0; i < 4; i++) {
        rooms[i].showInfo();
        cout << endl;
    }
}

Type Flat::getType() {
    return FLAT;
}

Address &Flat::getAddress() {
    return flatAddress;
}

double Flat::getArea() {
    double sumArea = 0;
    for (int i = 0; i < 4; i++)
        sumArea += rooms[i].getArea();
    return sumArea;
}