#include <iostream>
#include "gtest/gtest.h"
#include "Diagram.h"
#include "Element.h"

using namespace std;

TEST(DIAGRAM, CONSTRUCTORS) {

    Diagram def;
    ASSERT_EQ(1, def.getSize());
    ASSERT_FALSE(strcmp("xxxxxxxxxx", def.toStr()));

    Diagram byGeneralState(ONE);
    ASSERT_EQ(1, byGeneralState.getSize());
    ASSERT_FALSE(strcmp("----------", byGeneralState.toStr()));

    Element e("__");
    Diagram byElem(e);
    ASSERT_EQ(1, byElem.getSize());
    ASSERT_FALSE(strcmp("__", byElem.toStr()));

    Diagram byStr("--x-x-_x");
    ASSERT_EQ(7, byStr.getSize());
    ASSERT_FALSE(strcmp("--x-x-_x", byStr.toStr()));
}

TEST(DIAGRAM, DOUBLE_LT_OPERATOR) {
    char *str1 = "-x_"; // size : 3
    char *str2 = "__xx_"; // size : 3
    char *str3 = "---"; // size : 1
    char *str4 = "-_--_"; // size : 4

    Diagram d(str1);
    ASSERT_NO_THROW(d << str2 << str3 << str4);
    int expectedSize = 9;
    char *expectedStr = "-x___xx_----_--_"; // size : 9
    ASSERT_EQ(expectedSize, d.getSize());
    ASSERT_FALSE(strcmp(expectedStr, d.toStr()));

    d = Diagram(str1);
    ASSERT_ANY_THROW(d << str4 << str4 << str4);
    expectedSize = 7;
    expectedStr = "-x_-_--_"; // size : 7
    ASSERT_EQ(expectedSize, d.getSize());
    ASSERT_FALSE(strcmp(expectedStr, d.toStr()));
}

TEST(DIAGRAM, DOUBLE_GT_EQ_OPERATOR) {
    char *str = "-x___xx_----_--_";
    char *expectedStr0 = "-x___xx_----_--_";
    char *expectedStrD = "-x___xx_----_--_";
    char *expectedStr4 = "_--_-x___xx_----";

    Diagram d(str);
    d >>= 0;
    ASSERT_FALSE(strcmp(expectedStr0, d.toStr()));

    d = Diagram(str);
    d >>= d.getDuration(d.getSize());
    ASSERT_FALSE(strcmp(expectedStrD, d.toStr()));

    d = Diagram(str);
    d >>= 4;
    ASSERT_FALSE(strcmp(expectedStr4, d.toStr()));
}

TEST(DIAGRAM, DOUBLE_LT_EQ_OPERATOR) {
    char *str = "-x___xx_----_--_";
    char *expectedStr0 = "-x___xx_----_--_";
    char *expectedStrD = "-x___xx_----_--_";
    char *expectedStr4 = "_xx_----_--_-x__";

    Diagram d(str);
    d <<= 0;
    ASSERT_FALSE(strcmp(expectedStr0, d.toStr()));

    d = Diagram(str);
    d <<= d.getDuration(d.getSize());
    ASSERT_FALSE(strcmp(expectedStrD, d.toStr()));

    d = Diagram(str);
    d <<= 4;
    ASSERT_FALSE(strcmp(expectedStr4, d.toStr()));
}

TEST(DIAGRAM, MULT_EQ_OPERATOR) {
    int times7 = 7;
    int times3 = 3;
    int times2 = 2;
    int times1 = 1;
    int times0 = 0;

    char *str1 = "_-x-";
    char *str2 = "_-x_";

    Diagram d(str1);

    ASSERT_ANY_THROW(d *= times7);
    ASSERT_ANY_THROW(d *= times3);
    ASSERT_ANY_THROW(d *= times0);
    ASSERT_NO_THROW(d *= times1);
    ASSERT_NO_THROW(d *= times2);
    ASSERT_FALSE(strcmp("_-x-_-x-", d.toStr()));
    ASSERT_EQ(8, d.getSize());

    d = Diagram(str2);

    ASSERT_ANY_THROW(d *= times7);
    ASSERT_ANY_THROW(d *= times0);
    ASSERT_NO_THROW(d *= times1);
    ASSERT_NO_THROW(d *= times3);
    ASSERT_FALSE(strcmp("_-x__-x__-x_", d.toStr()));
    ASSERT_EQ(10, d.getSize());

    d = Diagram(str2);

    ASSERT_NO_THROW(d *= times2);
    ASSERT_FALSE(strcmp("_-x__-x_", d.toStr()));
    ASSERT_EQ(7, d.getSize());
}

TEST(DIAGRAM, PARENTHESIS_OPERATOR) {
    int time10 = 10;
    int time0 = 0;
    int timeNegative = -1;
    int time6 = 6;
    int time7 = 7;

    Diagram d("--x_-__x"); // size : 6
    Diagram d1("---__-_-x--x"); // size : 8
    Diagram d2("---__-_-x--"); // size : 7

    char *expectedStr = "--x_----__-_-x--";
    int expectedSize = 10;

    ASSERT_ANY_THROW(d(d1, time10));
    ASSERT_ANY_THROW(d(d1, time0));
    ASSERT_ANY_THROW(d(d1, timeNegative));

    ASSERT_ANY_THROW(d(d1, time6));
    ASSERT_ANY_THROW(d(d1, time7));
    ASSERT_ANY_THROW(d(d2, time7));

    ASSERT_NO_THROW(d(d2, time6));
    ASSERT_EQ(expectedSize, d.getSize());
    ASSERT_FALSE(strcmp(expectedStr, d.toStr()));
}

TEST(DIAGRAM, PLUS_EQ_OPERATOR) {
    char *str = "--x_-__x";
    Diagram d(str); // size : 6
    Diagram d1("---__-_-x--x"); // size : 8
    Diagram d2("---__-_"); // size : 4
    Diagram d3("x__-_-"); // size : 5
    Diagram d4("-x"); // size : 2

    char *expectedStr2 = "--x_-__x---__-_";
    char *expectedStr3 = "--x_-__xx__-_-";
    char *expectedStr4 = "--x_-__x-x";
    int expectedSize23 = 10;
    int expectedSize4 = 8;

    ASSERT_ANY_THROW(d += d1);

    ASSERT_NO_THROW(d += d2);
    ASSERT_EQ(expectedSize23, d.getSize());
    ASSERT_FALSE(strcmp(expectedStr2, d.toStr()));

    d = Diagram(str);
    ASSERT_NO_THROW(d += d3);
    ASSERT_EQ(expectedSize23, d.getSize());
    ASSERT_FALSE(strcmp(expectedStr3, d.toStr()));

    d = Diagram(str);
    ASSERT_NO_THROW(d += d4);
    ASSERT_EQ(expectedSize4, d.getSize());
    ASSERT_FALSE(strcmp(expectedStr4, d.toStr()));
}

void printElems(Element *elems, int size);
TEST(DIAGRAM, PLUS_OPERATOR) {
    char *str1 = "-x_"; // size : 3
    char *str2 = "__xx_"; // size : 3
    char *str3 = "---"; // size : 1
    char *str4 = "-_--_"; // size : 4

    Diagram d;
    Diagram d1(str1);
    Element e(str3);

    ASSERT_NO_THROW(d = d1 + str2 + e + str4);
    int expectedSize = 9;
    char *expectedStr = "-x___xx_----_--_"; // size : 9
    ASSERT_EQ(expectedSize, d.getSize());
    ASSERT_FALSE(strcmp(expectedStr, d.toStr()));

    ASSERT_ANY_THROW(d = d1 + str4 + e + str4);
    expectedSize = 9;
    expectedStr = "-x___xx_----_--_"; // size : 8
    ASSERT_EQ(expectedSize, d.getSize());
    ASSERT_FALSE(strcmp(expectedStr, d.toStr()));
}

int _tmain() {
    testing::InitGoogleTest();
    return RUN_ALL_TESTS();
}
