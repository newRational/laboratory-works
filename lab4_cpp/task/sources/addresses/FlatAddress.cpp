#include "FlatAddress.h"

FlatAddress::FlatAddress(): Address(), flatNumber(0) {}

FlatAddress::FlatAddress(string street, int houseNumber, int flatNumber):
Address(street, houseNumber), flatNumber(flatNumber) {}

int FlatAddress::getFlatNumber() {
    return flatNumber;
}

void FlatAddress::showAddress() {
    Address::showAddress();
    cout << "- Квартира: " << flatNumber << endl;
}

bool FlatAddress::equals(const Address &other) {
    FlatAddress address = (FlatAddress &) other;
    return  (street == address.street) &&
            (houseNumber == address.houseNumber) &&
            (flatNumber == address.flatNumber);
}



