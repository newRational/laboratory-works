#include "Tractrix.h"
#include "Point.h"
#include "gtest/gtest.h"

using namespace std;
using namespace lab2;

TEST(TractrixConstructor, DefaultConstructor) {
    Tractrix t1;
    ASSERT_EQ(1, t1.getTangentLength());
}

TEST(TractrixConstructor, InitConstructor) {
    int tangentLength = 10;
    Tractrix t1(tangentLength);
    ASSERT_EQ(tangentLength, t1.getTangentLength());
}

TEST(TractrixConstruction, TestException) {
    ASSERT_ANY_THROW(Tractrix(0));
    ASSERT_ANY_THROW(Tractrix(-1));
}

TEST(TractrixMethods, Setter) {
    int tangentLength = 10;
    Tractrix t1;
    t1.setTangentLength(tangentLength);
    ASSERT_EQ(tangentLength, t1.getTangentLength());
}

TEST(TractrixMethods, TestInvalidArgumentException) {
    Tractrix t1;
    int angleBelowRange = -5;
    int angleOverRange = 5;

    ASSERT_ANY_THROW(t1.getPointByAngle(angleBelowRange));
    ASSERT_ANY_THROW(t1.getPointByAngle(angleOverRange));

    ASSERT_ANY_THROW(t1.getArcLengthByAngle(angleBelowRange));
    ASSERT_ANY_THROW(t1.getArcLengthByAngle(angleOverRange));

    ASSERT_ANY_THROW(t1.getRadiusOfCurvatureByAngle(angleBelowRange));
    ASSERT_ANY_THROW(t1.getRadiusOfCurvatureByAngle(angleOverRange));
}

TEST(TractrixMethods, TestCorrectnessOfCalculations) {
    Tractrix t1;
    int validAngle = 1;
    Point p = t1.getPointByAngle(validAngle);

    ASSERT_NEAR(0.983325, p.getX(), 0.0001);
    ASSERT_NEAR(0.827439, p.getY(), 0.0001);
    ASSERT_NEAR(0.172604, t1.getArcLengthByAngle(validAngle), 0.0001);
    ASSERT_NEAR(0.642093, t1.getRadiusOfCurvatureByAngle(validAngle), 0.0001);
    ASSERT_NEAR(1.5708, t1.getAreaUnderTractrix(), 0.0001);
    ASSERT_NEAR(25.1327, t1.getAreaOfSurfaceOfRevolution(), 0.0001);
    ASSERT_NEAR(4.18879, t1.getVolumeOfSolidOfRevolution(), 0.0001);
}

int _tmain() {
    testing::InitGoogleTest();
    return RUN_ALL_TESTS();
}
