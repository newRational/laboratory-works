#include "Element.h"
#include "Diagram.h"
#include <iostream>

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

void getSize(Diagram &d) {
    cout << "size : " << d.getSize() << endl << endl;
}

void getSumDuration(Diagram &d) {
    cout << "sum duration : " << d.getDuration(d.getSize()) << endl << endl;
}

void print(Diagram &d) {
    cout << "diagram : ";
    d.print();
    cout << endl;
}

void copy(Diagram &d) {
    int n = getNum(0, INT32_MAX, nonStrictInequality, "Введите кол-во повторений : ");
    cout << endl;

    try {
        d.copy(n);
    } catch (invalid_argument e) {
        cout << e.what() << endl << endl;
    }
}

void rotateRight(Diagram &d) {
    int offset = getNum(0, INT32_MAX, nonStrictInequality, "Введите смещение : ");
    cout << endl;

    offset %= d.getSize();

    try {
        d.rotateRight(offset);
    } catch (logic_error e) {
        cout << e.what() << endl << endl;
    }
}

void rotateLeft(Diagram &d) {
    int offset = getNum(0, INT32_MAX, nonStrictInequality, "Введите смещение : ");
    cout << endl;

    offset %= d.getSize();

    try {
        d.rotateLeft(offset);
    } catch (logic_error e) {
        cout << e.what() << endl << endl;
    }
}

void input(Diagram &d) {
    char str[256];
    cout << "Введите строку : ";
    cin.getline(str, 256, '\n');
    int time = getNum(0, INT32_MAX, nonStrictInequality, "Введите время : ");
    cout << endl;
    try {
        d.input(str, time);
    } catch (invalid_argument e) {
        cout << e.what() << endl << endl;
    }
}

Diagram byDefault() {
    Diagram d;
    return d;
}

Diagram byState() {
    char *message = "Введите состояние : ";
    char state = getNum(1, 255, nonStrictInequality, message);
    cout << endl;
    while (state != '1' && state != '-' && state != '0' && state != '_' && state != 'x' && state != 'X') {
        refreshCin();
        cout << "Incorrect input\n\n" << message;
        state = getNum(1, 255, nonStrictInequality, message);
        cout << endl;
    }

    refreshCin();

    Diagram d(Element::charToState(state));
    return d;
}

Diagram byStr() {
    char str[256];
    cout << "Введите строку : ";
    cin.getline(str, 256, '\n');
    cout << endl;
    Diagram d(str);
    return d;
}

string namesOfCreations[] = {
        "Создание по умолчанию",
        "Создание с задание общего состояния сигнала",
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
        actionNumber = getNum(0, NUM_OF_CREATIONS-1, nonStrictInequality, "Введите номер действия: ");
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
        d.unite(other);
    } catch (logic_error e) {
        cout << e.what() << endl << endl;
    }
}

void change(Diagram &d) {
    Diagram other = create();
    int time = getNum(0, INT32_MAX, nonStrictInequality, "Введите время : ");
    cout << endl;
    try {
        d.change(other, time);
    } catch (invalid_argument e) {
        cout << e.what() << endl << endl;
    }
}

string namesOfActions[] = {
        "Завершение работы",
        "Получить текущий размер",
        "Получить суммарную длительность",
        "Ввести сигнал в виде строки и вставить его по времени в диаграмму",
        "Вывести диаграмму",
        "Копирование временной диаграммы определенное число раз",
        "Сдвиг временной диаграммы на определенное время вправо",
        "Сдвиг временной диаграммы на определенное время влево",
        "Объединение временной диаграммы с другой временной диаграммой",
        "Замена временной диаграммы в определенный момент времени другой временной диаграммой"
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
        actionNumber = getNum(0, NUM_OF_ACTIONS-1, nonStrictInequality, "Введите номер действия: ");
        cout << endl;
        if (actionNumber != 0)
            actions[actionNumber](d);
    } while (actionNumber);
}