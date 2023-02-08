#ifndef LAB4_CPP_ADDRESS_H
#define LAB4_CPP_ADDRESS_H

#include <iostream>
#include <string>

using namespace std;

class Address {
protected:
    int houseNumber;
    string street;
public:
    Address();
    Address(string, int);

    string getStreet();
    int getHouseNumber();

    virtual void showAddress();
    virtual bool equals(const Address &other);
};

#endif
