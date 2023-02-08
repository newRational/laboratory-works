#include "myVector.h"
#include <iostream>

#include "TableElement.h"
#include "FlatAddress.h"
#include "Apartment.h"
#include "Flat.h"
#include "Cottage.h"

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

string getStr(const string &message = "") {
    string str;
    cout << message;
    getline(cin, str);

    return str;
}

TableElement *findByAddress(myVector<TableElement> &table, Address &address) {
    for (int i = 0; i < table.size(); i++)
        if (table[i].habitation -> getAddress().equals(address))
            return &table[i];
    return nullptr;
}

string types[] = {
        "Апартаменты",
        "Квартира",
        "Коттедж"
};

Type getType() {
    for (int i = 0; i < 3; i++)
        cout << i+1 << ". " << types[i] << endl;
    cout << endl;
    int typeNum = getNum(1, 3, nonStrictInequality, "Введите номер типа жилья: ");
    return (Type) typeNum;
}
Address *getCottageAddress() {
    string street = getStr("- Введите улицу: ");
    int houseNumber = getNum<int>(1, 1000, nonStrictInequality, "- Введите номер дома: ");
    cout << endl;
    return new Address(street, houseNumber);
}

Address *getFlatAddress() {
    string street = getStr("- Введите улицу: ");
    int houseNumber = getNum<int>(1, 1000, nonStrictInequality, "- Введите номер дома: ");
    int flatNumber = getNum<int>(1, 1000, nonStrictInequality, "- Введите номер квартиры: ");
    cout << endl;
    return new FlatAddress(street, houseNumber, flatNumber);
}

Address *getAddress(Type type) {
    cout << endl << "Введите адрес" << endl;
    switch (type) {
        case FLAT:
        case APARTMENT: return getFlatAddress();
        case COTTAGE: return getCottageAddress();
        default: return nullptr;
    }
}

Room *getRooms(int numberOfRooms) {
    Room *rooms = new Room[numberOfRooms];

    for (int i = 0; i < numberOfRooms; i++) {
        cout << endl;
        cout << "Введите параметры " << i+1 << "-ого помещения:" << endl;

        rooms[i].setName(getStr("- Название: "));
        rooms[i].setArea(getNum<double>(1, 1000, nonStrictInequality, "- Площадь: "));
        rooms[i].setComment(getStr("- Комментарий: "));
    }

    cout << endl;
    return rooms;
}

Room *getFlatRooms() {
    Room *rooms = new Room[4];

    rooms[0].setName("Комната");
    rooms[1].setName("Кухня");
    rooms[2].setName("Санузел");
    rooms[3].setName("Прихожая");

    for (int i = 0; i < 4; i++) {
        cout << endl;
        cout << "Введите параметры " << i+1 << "-ого помещения:" << endl;
        cout << "- Название: " << rooms[i].getName() << endl;
        rooms[i].setArea(getNum<double>(1, 1000, nonStrictInequality, "- Площадь: "));
        rooms[i].setComment(getStr("- Комментарий: "));
    }

    cout << endl;
    return rooms;
}

Building *getBuildings(int numberOfBuildings) {
    Building *buildings = new Building[numberOfBuildings];

    cout << endl;
    for (int i = 0; i < numberOfBuildings; i++) {
        cout << "Введите параметры " << i+1 << "-ого строения:" << endl;

        buildings[i].setId(getNum<int>(1, 1000, nonStrictInequality, "- Номер строения: "));
        buildings[i].setNumberOfRooms(getNum<int>(1, 1000, nonStrictInequality, "- Кол-во помещений: "));
        buildings[i].setRooms(getRooms(buildings[i].getNumberOfRooms()));
    }

    return buildings;
}

Apartment *getApartment(Address &address) {
    int numberOfRooms = getNum<int>(1, 100, nonStrictInequality, "Введите кол-во помещений: ");
    Room *rooms = getRooms(numberOfRooms);
    return new Apartment((FlatAddress &) address, numberOfRooms, rooms);
}

Flat *getFlat(Address &address) {
    Room *rooms = getFlatRooms();
    return new Flat((FlatAddress &) address, rooms);
}

Cottage *getCottage(Address &address) {
    int numberOfBuildings = getNum<int>(1, 100, nonStrictInequality, "Введите кол-во строений: ");
    Building *buildings = getBuildings(numberOfBuildings);
    return new Cottage(address, numberOfBuildings, buildings);
}

Habitation *getHabitation(Type type, Address &address) {
    switch (type) {
        case APARTMENT: return getApartment(address);
        case FLAT: return getFlat(address);
        case COTTAGE: return getCottage(address);
        default: return nullptr;
    }
}

TableElement *getItem(double pricePerSquare, Habitation *habitation) {
    TableElement *item = new TableElement;

    item -> inhabited = true;
    item -> pricePerSquare = pricePerSquare;
    item -> habitation = habitation;

    return item;
}

void login(myVector<TableElement> &table) {
    Type type = getType();

    Address *address = getAddress(type);
    TableElement *item = findByAddress(table, *address);

    if (item) {
        item -> inhabited = true;
    } else {
        cout << "Жилья с данным адресом не найдено." << endl;
        cout << "Будет добавлено жилье с данным адресом." << endl << endl;
        double pricePerSquare = getNum<double>(0, 100000, strictInequality, "Цена за кв. м.: ");
        Habitation *habitation = getHabitation(type, *address);
        table.push_back(*getItem(pricePerSquare, habitation));
    }
}

void logout(myVector<TableElement> &table) {
    Type type = getType();

    Address *address = getAddress(type);
    TableElement *item = findByAddress(table, *address);

    if (item != nullptr)
        item -> inhabited = false;
    else
        cout << "Жилья с данным адресом не найдено" << endl << endl;
}

int countInhabited(myVector<TableElement> &table) {
    int count = 0;
    for (int i = 0; i < table.size(); i++)
        if (table[i].inhabited) count++;
    return count;
}

void showInhabited(myVector<TableElement> &table) {
    if (countInhabited(table))
        cout << "Заселенное жилье" << endl << endl;
    else {
        cout << "Заселенного жилья нет" << endl << endl;
        return;
    }

    for (int i = 0; i < table.size(); i++) {
        if (table[i].inhabited) {
            table[i].habitation->showInfo();
            cout << endl;
        }
    }
}

int countUninhabited(myVector<TableElement> &table) {
    return table.size() - countInhabited(table);
}

void showUninhabited(myVector<TableElement> &table) {
    if (countUninhabited(table))
        cout << "Незаселенное жилье" << endl << endl;
    else {
        cout << "Незаселенного жилья нет" << endl << endl;
        return;
    }

    for (int i = 0; i < table.size(); i++)
        if (!table[i].inhabited) {
            table[i].habitation->showInfo();
            cout << endl;
        }
}

void showInfoByAddress(myVector<TableElement> &table) {
    Type type = getType();

    Address *address = getAddress(type);
    TableElement *item = findByAddress(table, *address);

    if (item)
        item->habitation->showInfo();
    else
        cout << "Жилья с данным адресом не найдено" << endl << endl;
}

void showAll(myVector<TableElement> &table) {
    for (int i = 0; i < table.size(); i++) {
        table[i].habitation->showInfo();
        cout << endl;
    }
}

void (*actions[])(myVector<TableElement> &) = {
        nullptr,
        login,
        logout,
        showAll,
        showInhabited,
        showUninhabited,
        showInfoByAddress
};

string namesOfActions[] = {
        "Выход",
        "Зарегистрировать заселение в жилье",
        "Зарегистрировать освобождение жилья",
        "Показать все жилье",
        "Показать заселенное жилье",
        "Показать незаселенное жилье",
        "Показать информацию жилья по адресу"
};

const int NUM_OF_ACTIONS = sizeof(namesOfActions) / sizeof (namesOfActions[0]);

void printActions() {
    for (int i = 0; i < NUM_OF_ACTIONS; i++)
        cout << i << ". " << namesOfActions[i] << endl;
    cout << endl;
}

void dialog(myVector<TableElement> &table) {
    int actionNumber = 0;
    do {
        printActions();
        actionNumber = getNum<int>(0, NUM_OF_ACTIONS, nonStrictInequality, "Введите номер действия: ");
        if (actionNumber) {
            cout << endl;
            actions[actionNumber](table);
        }
    } while (actionNumber);
}