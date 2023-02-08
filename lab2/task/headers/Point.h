#ifndef LAB2_POINT_H
#define LAB2_POINT_H

#include <ostream>

namespace lab2 {

    class Point {
    private:
        double x;
        double y;

    public:
        Point();

        Point(double x, double y);
        double getX() const;
        double getY() const;
        friend std::ostream &operator<<(std::ostream &ostream, Point &point);
    };
}
#endif
