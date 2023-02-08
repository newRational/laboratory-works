#ifndef LAB2_TRACTRIX_H
#define LAB2_TRACTRIX_H

#include "Point.h"

namespace lab2 {
    class Tractrix {

    private:
        double tangentLength;
        static void checkAngle(double angle);

    public:
        Tractrix(double tl = 1);
        double getTangentLength() const;
        void setTangentLength(double tl);
        Point getPointByAngle(double angle) const;
        double getArcLengthByAngle(double angle) const;
        double getRadiusOfCurvatureByAngle(double angle) const;
        double getAreaUnderTractrix() const;
        double getAreaOfSurfaceOfRevolution() const;
        double getVolumeOfSolidOfRevolution() const;
    };
}

#endif
