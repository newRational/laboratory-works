#ifndef LAB4_CPP_TABLEELEMENT_H
#define LAB4_CPP_TABLEELEMENT_H

#include "Habitation.h"

#include <iostream>
#include <string>

using namespace std;

struct TableElement {
    bool inhabited;
    double pricePerSquare;
    Habitation *habitation;
};

#endif
