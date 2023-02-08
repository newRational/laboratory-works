#include "../headers/Point.h"
#include "../headers/Tractrix.h"
#include <stdexcept>
#include <cmath>

namespace lab2 {
    using namespace std;

    Tractrix::Tractrix(double tl) {
        if (tl <= 0)
            throw invalid_argument("InvalidArgumentException");

        tangentLength = tl;
    }

    double Tractrix::getTangentLength() const {
        return tangentLength;
    }

    void Tractrix::setTangentLength(double tl) {
        if (Tractrix::tangentLength == tl)
            return;

        Tractrix::tangentLength = tl;
    }

    Point Tractrix::getPointByAngle(double angle) const {
        checkAngle(angle);

        int signOfX = tan(angle) > 0 ? 1 : tan(angle) == 0 ? 0 : -1;
        double x = signOfX * tangentLength * (cos(angle) + log(abs(tan(angle))));
        double y = x * sin(angle);
        Point point(x, y);

        return point;
    }

    double Tractrix::getArcLengthByAngle(double angle) const {
        checkAngle(angle);

        return -tangentLength * log(abs(sin(angle)));
    }

    double Tractrix::getRadiusOfCurvatureByAngle(double angle) const {
        checkAngle(angle);

        return abs(tangentLength / tan(angle));
    }

    double Tractrix::getAreaUnderTractrix() const {
        return M_PI * pow(tangentLength, 2) / 2;
    }

    double Tractrix::getAreaOfSurfaceOfRevolution() const {
        return 2 * 4 * M_PI * pow(tangentLength, 2);
    }

    double Tractrix::getVolumeOfSolidOfRevolution() const {
        return 4 * M_PI * pow(tangentLength, 2) / 3;
    }

    void Tractrix::checkAngle(double angle) {
        if (angle < 0 || angle > (M_PI))
            throw invalid_argument("InvalidArgumentException");
    }
}
