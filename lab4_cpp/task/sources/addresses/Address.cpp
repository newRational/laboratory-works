#include "Address.h"

Address::Address(): street("street"), houseNumber(0) {}

Address::Address(string street, int houseNumber): street(street), houseNumber(houseNumber) {}

string Address::getStreet() {
    return street;
}

int Address::getHouseNumber() {
    return houseNumber;
}

void Address::showAddress() {
    cout << "- Улица: " << street << endl;
    cout << "- Дом: " << houseNumber << endl;
}

bool Address::equals(const Address &other) {
    return  (street == other.street) &&
            (houseNumber == other.houseNumber);
}
