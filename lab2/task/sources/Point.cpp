#include <iostream>
#include "../headers/Point.h"

namespace lab2 {

    Point::Point() {
        x = 0;
        y = 0;
    }

    Point::Point(double x, double y) {
        Point::x = x;
        Point::y = y;
    }

    double Point::getX() const {
        return x;
    }

    double Point::getY() const {
        return y;
    }

    std::ostream &operator<<(std::ostream &ostream, Point &point) {
        std::cout << "x: " << point.x << ", y: " << point.y;
        return ostream;
    }
}