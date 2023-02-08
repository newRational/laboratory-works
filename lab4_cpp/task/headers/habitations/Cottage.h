#ifndef LAB4_CPP_COTTAGE_H
#define LAB4_CPP_COTTAGE_H

#include "Habitation.h"
#include "Address.h"
#include "Building.h"

#include <iostream>
#include <string>

using namespace std;

class Cottage: public Habitation {
private:
    Address address;
    int numberOfBuildings;
    Building *buildings;
public:
    Cottage();
    Cottage(Address &, int, Building *);

    Cottage(const Cottage&);
    Cottage(Cottage&&);
    void operator=(const Cottage&);
    void operator=(Cottage&&);

    ~Cottage();

    Building *begin();
    Building *end();
    const Building *begin() const;
    const Building *end() const;

    void showInfo() override;
    Type getType() override;
    Address &getAddress() override;
    double getArea() override;
};

#endif
