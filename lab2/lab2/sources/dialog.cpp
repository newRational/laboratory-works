#include <iostream>
#include <string>
#include <cmath>
#include "Tractrix.h"

namespace lab2 {
    using namespace std;

    template<typename T>
    bool strictInequality(T num, T min, T max) {
        return min < num && num < max;
    }

    template<typename T>
    bool nonStrictInequality(T num, T min, T max) {
        return min <= num && num <= max;
    }

    template<typename T>
    bool isValidInput(T num, T min, T max, bool (*inequality)(T, T, T)) {
        if (cin.eof())
            exit(0);
        return cin.good() && inequality(num, min, max);
    }

    void refreshCin() {
        cin.clear();
        cin.ignore(INT32_MAX, '\n');
    }

    template<typename T>
    T getNum(T min, T max, bool (*inequality)(T, T, T), const string &message = "") {
        T num;
        cout << message;
        cin >> num;

        while (!isValidInput(num, min, max, inequality)) {
            refreshCin();
            cout << "Incorrect input\n\n" << message;
            cin >> num;
        }

        refreshCin();

        return num;
    }

    void getTangentLength(Tractrix &tractrix) {
        double tangentLength = tractrix.getTangentLength();
        cout << "Длина касательной: " << tangentLength << endl << endl;
    }

    void setTangentLength(Tractrix &tractrix) {
        auto tangentLength = getNum(0, INT32_MAX, strictInequality, "Введите длину касательной: ");
        tractrix.setTangentLength(tangentLength);
        cout << endl;
    }

    void getPointByAngle(Tractrix &tractrix) {
        auto angle = getNum<double>(0, M_PI, strictInequality, "Введите угол: ");
        Point point;

        try {
            point = tractrix.getPointByAngle(angle);
        } catch (invalid_argument &ia) {
            cout << ia.what() << endl << endl;
            return;
        }

        cout << point << endl << endl;
    }

    void getArcLengthByAngle(Tractrix &tractrix) {
        auto angle = getNum<double>(0, M_PI, strictInequality, "Введите угол: ");
        double arcLength;

        try {
            arcLength = tractrix.getArcLengthByAngle(angle);
        } catch (invalid_argument &ia) {
            cout << ia.what() << endl << endl;
            return;
        }

        cout << "Длина трактрисы: " << arcLength << endl << endl;
    }

    void getRadiusOfCurvatureByAngle(Tractrix &tractrix) {
        auto angle = getNum<double>(0, M_PI, strictInequality, "Введите угол: ");
        double radiusOfCurvature;

        try {
            radiusOfCurvature = tractrix.getRadiusOfCurvatureByAngle(angle);
        } catch (invalid_argument &ia) {
            cout << ia.what() << endl << endl;
            return;
        }

        cout << "Радиус кривизны: " << radiusOfCurvature << endl << endl;
    }

    void getAreaUnderTractrix(Tractrix &tractrix) {
        double areaUnderTractrix = tractrix.getAreaUnderTractrix();
        cout << "Площадь под трактрисой: " << areaUnderTractrix << endl << endl;
    }

    void getAreaOfSurfaceOfRevolution(Tractrix &tractrix) {
        double areaOfSurfaceOfRevolution = tractrix.getAreaOfSurfaceOfRevolution();
        cout << "Площадь поверхности вращения: " << areaOfSurfaceOfRevolution << endl << endl;
    }

    void getVolumeOfSolidOfRevolution(Tractrix &tractrix) {
        double volumeOfSolidOfRevolution = tractrix.getVolumeOfSolidOfRevolution();
        cout << "Объем тела вращения: " << volumeOfSolidOfRevolution << endl << endl;
    }

    string namesOfActions[] = {
            "Завершение работы",
            "Получить длину касательной",
            "Установить длину касательной",
            "Получить координаты точки по углу",
            "Получить длину трактрисы по углу",
            "Получить радиус кривизны по углу",
            "Получить площадь под трактрисой",
            "Получить площадь поверхности вращения",
            "Получить объем тела вращения",
    };

    void (*actions[])(Tractrix &tractrix) = {
            nullptr,
            getTangentLength,
            setTangentLength,
            getPointByAngle,
            getArcLengthByAngle,
            getRadiusOfCurvatureByAngle,
            getAreaUnderTractrix,
            getAreaOfSurfaceOfRevolution,
            getVolumeOfSolidOfRevolution,
    };

    const int NUM_OF_ACTIONS = sizeof(namesOfActions) / sizeof (namesOfActions[0]);

    void printActions() {
        for (int i = 0; i < NUM_OF_ACTIONS; i++)
            std::cout << i << ". " << namesOfActions[i] << std::endl;
        cout << endl;
    }

    void dialog(Tractrix &tractrix) {
        int actionNumber = 0;
        do {
            printActions();
            actionNumber = getNum(0, NUM_OF_ACTIONS-1, nonStrictInequality, "Введите номер действия: ");
            std::cout << std::endl;
            if (actionNumber != 0)
                actions[actionNumber](tractrix);
        } while (actionNumber);
    }
}