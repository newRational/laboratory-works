#include "Habitation.h"

#include <stdexcept>

Habitation::Habitation(): type(HABITATION) {}

Habitation::Habitation(Type type): type(type) {}

void Habitation::showInfo() {
    throw logic_error("Habitation info");
}

Type Habitation::getType() {
    throw logic_error("Habitation type");
}

Address &Habitation::getAddress() {
    throw logic_error("Habitation address");
}

double Habitation::getArea() {
    throw logic_error("Habitation area");
}