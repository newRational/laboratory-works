#include "Element.h"
#include "Diagram.h"
#include <iostream>
#include <cstring>

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
        cout << "Некорректный ввод\n\n" << message;
        cin >> num;
    }

    refreshCin();

    return num;
}

void getSize(Diagram &d) {
    cout << "размер: " << d.getSize() << endl << endl;
}

void getSumDuration(Diagram &d) {
    cout << "общая длительность: " << d.getDuration(d.getSize()) << endl << endl;
}

void print(Diagram &d) {
    cout << "диаграмма: ";
    cout << d;
    cout << endl;
}

void copy(Diagram &d) {
    int n = getNum(0, INT32_MAX, nonStrictInequality, "Ввести кол-во доп. повторений: ");
    cout << endl;

    try {
        d *= n;
    } catch (invalid_argument e) {
        cout << e.what() << endl << endl;
    }
}

void rotateRight(Diagram &d) {
    int offset = getNum(0, INT32_MAX, nonStrictInequality, "Ввести смещение: ");
    cout << endl;
    offset %= d.getDuration(d.getSize());

    try {
        d >>= offset;
    } catch (logic_error e) {
        cout << e.what() << endl << endl;
    }
}

void rotateLeft(Diagram &d) {
    int offset = getNum(0, INT32_MAX, nonStrictInequality, "Ввести смещение: ");
    cout << endl;

    offset %= d.getDuration(d.getSize());

    try {
        d <<= offset;
    } catch (logic_error e) {
        cout << e.what() << endl << endl;
    }
}

void input(Diagram &d) {
    char str[256];
    cout << "Ввести строку: ";
    cin.getline(str, 256, '\n');
    cout << endl;
    if (!strlen(str)) return;
    try {
        str >> d;
    } catch (invalid_argument e) {
        cout << e.what() << endl << endl;
    }
}

Diagram byDefault() {
    Diagram d;
    return d;
}

Diagram byState() {
    char *message = "Ввести состояние: ";
    char state = getNum(1, 255, nonStrictInequality, message);
    cout << endl;
    while (state != '1' && state != '-' && state != '0' && state != '_' && state != 'x' && state != 'X') {
        refreshCin();
        cout << "Неверный ввод\n\n" << message;
        state = getNum(1, 255, nonStrictInequality, message);
        cout << endl;
    }

    refreshCin();

    Diagram d(Element::charToState(state));
    return d;
}

Diagram byStr() {
    char str[256];
    cout << "Ввести строку: ";
    cin.getline(str, 256, '\n');
    cout << endl;
    Diagram d(str);
    return d;
}

string namesOfCreations[] = {
        "Создание по умолчанию",
        "Создание с заданием общего состояния сигнала",
        "Создание с помощью строки"
};

Diagram (*creations[])() = {
        byDefault,
        byState,
        byStr
};

const int NUM_OF_CREATIONS = sizeof(namesOfCreations) / sizeof (namesOfCreations[0]);

void printCreations() {
    for (int i = 0; i < NUM_OF_CREATIONS; i++)
        std::cout << i << ". " << namesOfCreations[i] << std::endl;
    cout << endl;
}

Diagram create() {
    int actionNumber = 0;
    Diagram d;
    do {
        printCreations();
        actionNumber = getNum(0, NUM_OF_CREATIONS-1, nonStrictInequality, "Ввести номер действия: ");
        cout << endl;
        try {
            d = creations[actionNumber]();
            return d;
        } catch (exception e) {
            cout << e.what() << endl << endl;
        }
    } while (true);
}

void unite(Diagram &d) {
    Diagram other = create();
    try {
        d += other;
    } catch (logic_error e) {
        cout << e.what() << endl << endl;
    }
}

void change(Diagram &d) {
    Diagram other = create();
    int time = getNum(0, INT32_MAX, nonStrictInequality, "Ввести время: ");
    cout << endl;
    try {
        d(other, time);
    } catch (invalid_argument e) {
        cout << e.what() << endl << endl;
    }
}

string namesOfActions[] = {
        "Завершение работы",
        "Получить текущий размер",
        "Получить полную длительность",
        "Ввести сигнал в виде строки",
        "Вывести диаграмму",
        "Скопировать диаграмму определенное число раз",
        "Сдвиг диаграммы вправо на определенное число раз",
        "Сдвиг диаграммы влево на определенное число раз",
        "Объединить две диаграммы",
        "Замена одной диаграммы другой в определенный момент времени"
};

void (*actions[])(Diagram &d) = {
        nullptr,
        getSize,
        getSumDuration,
        input,
        print,
        copy,
        rotateRight,
        rotateLeft,
        unite,
        change
};

const int NUM_OF_ACTIONS = sizeof(namesOfActions) / sizeof (namesOfActions[0]);

void printActions() {
    for (int i = 0; i < NUM_OF_ACTIONS; i++)
        std::cout << i << ". " << namesOfActions[i] << std::endl;
    cout << endl;
}

void dialog(Diagram &d) {
    int actionNumber = 0;
    do {
        printActions();
        actionNumber = getNum(0, NUM_OF_ACTIONS-1, nonStrictInequality, "Ввести номер действия: ");
        cout << endl;
        if (actionNumber != 0)
            actions[actionNumber](d);
    } while (actionNumber);
}