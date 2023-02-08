#ifndef LAB2_DIALOG_H
#define LAB2_DIALOG_H

#include <string>
#include "Tractrix.h"

namespace lab2 {
    using namespace std;

    template<typename T>
    bool strictInequality(T num, T min, T max);

    template<typename T>
    bool nonStrictInequality(T num, T min, T max);

    template<typename T>
    T getNum(T min, T max, bool (*inequality)(T, T, T), const string &message = "");

    void dialog(Tractrix &tractrix);
}

#endif
