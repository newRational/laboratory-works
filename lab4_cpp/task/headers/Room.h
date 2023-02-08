#ifndef LAB4_CPP_ROOM_H
#define LAB4_CPP_ROOM_H

#include <iostream>
#include <string>

using namespace std;

class Room {
private:
    string name;
    double area;
    string comment;
public:
    Room();
    Room(string, double, string);

    string getName();
    double getArea();
    void showInfo();

    void setName(string name);
    void setArea(double area);
    void setComment(string comment);
};

#endif
