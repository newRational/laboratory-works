#ifndef LAB4_CPP_FLATADDRESS_H
#define LAB4_CPP_FLATADDRESS_H

#include "Address.h"

#include <iostream>
#include <string>

using namespace std;

class FlatAddress: public Address {
private:
    int flatNumber;
public:
    FlatAddress();
    FlatAddress(string, int, int);

    int getFlatNumber();

    void showAddress() override;
    bool equals(const Address& other) override;
};

#endif
