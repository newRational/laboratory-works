#include "Room.h"

Room::Room(): name("room"), area(0.00), comment("no comment") {}

Room::Room(string name, double area, string comment):
name(name), area(area), comment(comment) {}

string Room::getName() {
    return name;
}

double Room::getArea() {
    return area;
}

void Room::showInfo() {
    cout << "- Название: " << name << endl;
    cout << "- Площадь: " << area << endl;
    cout << "- Комментарий: " << comment  << endl;
}

void Room::setName(string name) {
    this->name = name;
}

void Room::setArea(double area) {
    this->area = area;
}

void Room::setComment(string comment) {
    this->comment = comment;
}
