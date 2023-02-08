#ifndef LAB4_CPP_HABITATION_H
#define LAB4_CPP_HABITATION_H

#include "Address.h"

#include <iostream>
#include <string>

using namespace std;

enum Type {
    HABITATION, APARTMENT, FLAT, COTTAGE
};

class Habitation {
protected:
    Type type;
public:
    Habitation();
    explicit Habitation(Type);

    virtual void showInfo();
    virtual Type getType();
    virtual Address &getAddress();
    virtual double getArea();
};

#endif
