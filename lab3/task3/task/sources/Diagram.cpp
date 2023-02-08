#include "Diagram.h"
#include <iostream>
#include <cstring>

using namespace std;

// @ForDebug
void printElems(Element *elems, int size) {
    for (int i = 0; i < size; i++) {
        cout << i << ") ";
        cout << Element::stateToChar(elems[i].getState()) << " : ";
        cout << elems[i].getDuration() << endl;
    }
}

// @ForDebug
void showElems(Element *elems, int size) {
    for (int i = 0; i < size; i++)
        for (int j = 0; j < elems[i].getDuration(); j++)
            cout << Element::stateToChar(elems[i].getState());
    cout << endl;
}

template <class T>
T *realloc(T *src, int oldSize, int newSize) {
    T *dest = new T[newSize];
    memcpy(dest, src, oldSize * sizeof(T));
    delete [] src;
    return dest;
}

void copyElems(Element *dest, int startOfDest, Element *source, int startOfSource, int size) {
    for (int i = 0; i < size; i++)
        dest[i + startOfDest] = source[i + startOfSource];
}

int countElems(char *str) {
    if (!strlen(str)) return 0;

    State state = Element::charToState(str[0]);
    int count = 1;

    for (int i = 0; i < strlen(str); i++)
        if (state != Element::charToState(str[i])) {
            state = Element::charToState(str[i]);
            count++;
        }

    return count;
}

int Diagram::getSize() const {
    return size;
}

void Diagram::setSize(int size) {
    this -> size = size;
}

int Diagram::getDuration(int n) const {
    int duration = 0;

    for (int i = 0; i < n; i++)
        duration += elements[i].getDuration();

    return duration;
}

Element *Diagram::getElements() {
    return elements;
}

void Diagram::setElements(Element *elements) {
    this -> elements = elements;
}

Diagram::~Diagram() {
    delete [] elements;
}

Diagram::Diagram(const Diagram &d) : size(d.size), elements(nullptr) {
    if (size) {
        elements = new Element[size];
        copyElems(elements, 0, d.elements, 0, size);
    }
}

Diagram::Diagram() : size(1) {
    elements = new Element[1];
    elements[0].setDuration(1);
}

Diagram::Diagram(State state) : size(1) {
    elements = new Element[1];
    elements[0].setState(state);
    elements[0].setDuration(1);
}

void parse(Element *elements, char *str) {
    if (!strlen(str)) return;

    State state = Element::charToState(str[0]);
    char symbol = str[0];
    int duration = 0;
    int index = 0;

    for (int i = 0; i < strlen(str); i++) {
        if (state == Element::charToState(str[i])) duration++;
        else {
            elements[index].setState(Element::charToState(symbol));
            elements[index].setDuration(duration);

            state = Element::charToState(str[i]);
            symbol = str[i];
            duration = 1;
            index++;
        }
    }

    elements[index].setState(Element::charToState(symbol));
    elements[index].setDuration(duration);
}

Diagram::Diagram(char *str) {
    size = countElems(str);
    elements = new Element[size];
    parse(elements, str);
}

Diagram::Diagram(Element e) : size(1) {
    elements = new Element[1];
    elements[0].setState(e.getState());
    elements[0].setDuration(e.getDuration());
}

int findIndex(Diagram &d, int time) {
    int fullDuration = d.getDuration(d.getSize());
    if (time == (fullDuration + 1)) return d.getSize();

    for (int i = 0; i <= d.getSize(); i++)
        if (time <= d.getDuration(i))
            return i - 1;

    return -1;
}

State findState(Diagram &d, int time) {
    int index = findIndex(d, time);
    return (d.getElements())[index].getState();
}

Element *toBuffer(Diagram &d, int time) {
    if (time == (d.getDuration(d.getSize()) + 1)) return nullptr;

    int index = findIndex(d, time);
    int number = index + 1;
    int bufferSize = d.getSize() - index;

    Element *buffer = new Element[bufferSize];
    copyElems(buffer, 0, d.getElements(), index, bufferSize);
    buffer[0].setDuration(d.getDuration(number) - time + 1);

    return buffer;
}

void moveBack(Element *elems, int sizeOfElems, int start) {
    copyElems(elems, start, elems, start + 1, sizeOfElems - 1);
}

void correctDuration(Diagram &d, int time) {
    if (time == (d.getDuration(d.getSize()) + 1)) return;

    Element *elems = d.getElements();
    int index = findIndex(d, time);
    int number = index + 1;
    int curDuration = elems[index].getDuration();
    int duration = curDuration - (d.getDuration(number) - time + 1);

    elems[index].setDuration(duration);
}

// @NotUsed
Element *toElements(char *str) {
    Element *elements = new Element[countElems(str)];
    parse(elements, str);
    return elements;
}

int correctSize(Diagram &d, int time) {
    int fullDuration = d.getDuration(d.getSize());
    int size = d.getSize();

    if (time <= 1 || time > fullDuration) return size;
    if (findState(d, time) == findState(d, time-1)) size++;

    return size;
}

void mergeElems(Element *elems, int index) {
    int duration = elems[index-1].getDuration() + elems[index].getDuration();
    elems[index-1].setDuration(duration);
}

int correct(Element *elems, int size) {
    int newSize = size;
    if (!size) return 0;

    State state = elems[0].getState();

    for (int i = 1, k = 1; k < size; i++, k++) {
        if (state == elems[i].getState()) {
            newSize--;
            mergeElems(elems, i);
            moveBack(elems, size, i);
            i--;
        } else
            state = elems[i].getState();
    }

    return newSize;
}

// @NotUsed
void insert(Diagram &d, Element *inserted, Element *buffer, int time, char *str) {
    int indexOfInserting = findIndex(d, time);
    int bufferSize = d.getSize() - indexOfInserting;
    int newSize = correctSize(d, time) + countElems(str);
    correctDuration(d, time);

    if (indexOfInserting != d.getSize() && d.getElements()[indexOfInserting].getDuration())
        indexOfInserting++;

    Element *elems = realloc(d.getElements(), d.getSize(), newSize);
    d.setElements(elems);

    copyElems(d.getElements(), 0, d.getElements(), 0, indexOfInserting);
    copyElems(d.getElements(), indexOfInserting, inserted, 0, countElems(str));

    if (buffer != nullptr)
        copyElems(d.getElements(), indexOfInserting + countElems(str), buffer, 0, bufferSize);

    int correctedSize = correct(d.getElements(), newSize);
    elems = realloc(d.getElements(), d.getSize(), newSize);
    d.setElements(elems);

    d.setSize(correctedSize);
}

ostream &operator<<(ostream &os, const Diagram &d) {
    if (!d.size) return os;

    for (int i = 0; i < d.size; i++)
        for (int j = 0; j < d.elements[i].getDuration(); j++)
            cout << Element::stateToChar(d.elements[i].getState());

    cout << endl;

    return os;
}

void Diagram::operator>>=(int offset) {
    if (!offset || !size || size == 1) return;

    int time = getDuration(size) + 1 - offset;
    int index = findIndex(*this, time);
    int newSize = size;

    if (findState(*this, time) == findState(*this, time-1)) newSize++;

    int rightSize = size - index;
    Element *right = toBuffer(*this, time);
    correctDuration(*this, time);

    int leftSize = newSize - rightSize;
    Element *left = new Element[leftSize];
    copyElems(left, 0, elements, 0, leftSize);

    elements = realloc(elements, size, newSize);
    copyElems(elements, 0, right, 0, rightSize);
    copyElems(elements, rightSize, left, 0, leftSize);

    size = correct(elements, newSize);
    elements = realloc(elements, newSize, size);

    delete [] right;
    delete [] left;
}

void Diagram::operator<<=(int offset) {
    *this >>= (getDuration(size) - offset);
}

void Diagram::operator*=(int n) {
    if (!n) throw invalid_argument("n must be positive");
    if (n == 1) return;

    bool equals = elements[0].getState() == elements[size-1].getState();
    int copiedSize = equals ? size - 1 : size;

    int newSize = equals ? 1 + copiedSize * n : copiedSize * n;
    elements = realloc(elements, size, newSize);

    int dur1 = elements[0].getDuration();
    int dur2 = elements[size-1].getDuration();

    for (int i = 0; i < n-1; i++) {
        if (equals) elements[size-1].setDuration(dur1 + dur2);
        copyElems(elements, size, elements, equals ? 1 : 0, copiedSize);
        size += copiedSize;
    }
}

bool validate(Diagram &d, int time) {
    if (time < 1 || time > d.getDuration(d.getSize()) + 1)
        throw invalid_argument("invalid time");
    return true;
}

void Diagram::operator()(Diagram &d, int time) {
    validate(d, time);

    int index = findIndex(*this, time - 1);

    bool equals1 = elements[index].getState() == d.elements[0].getState();
    bool equals2 = elements[index].getState() == elements[findIndex(*this, time)].getState();

    int newSize = findIndex(*this, time) + d.size - (equals2 ? 0 : 1);
    elements = realloc(elements, size, newSize);
    size = newSize;

    if (equals1)
        elements[index].setDuration(time - 1 - getDuration(index) + d.elements[0].getDuration());

    memcpy(elements + index + 1, d.elements + (equals1 ? 1 : 0), d.size);
}

void Diagram::operator+=(const Diagram &d) {
    if (!d.size) return;

    bool equals = false;
    if (size) equals = elements[size-1].getState() == d.elements[0].getState();

    int newSize = size + d.size + (equals ? -1 : 0);
    elements = realloc(elements, size, newSize);

    if (equals) elements[size-1].setDuration(elements[size-1].getDuration() + d.elements[0].getDuration());
    memcpy(elements + size, d.elements + (equals ? 1 : 0), d.size * sizeof(Element));

    size = newSize;
}

Diagram &operator<<(Diagram &d, char *str) {
    d += str;
    return d;
}

Diagram operator+(const Diagram &d1, const Diagram &d2) {
    Diagram res = d1;
    res += d2;
    return res;
}

char *Diagram::toStr() {
    char *str = new char[getDuration(size) + 1];
    int index = 0;

    for (int i = 0; i < size; i++)
        for (int j = 0; j < elements[i].getDuration(); j++)
            str[index++] = Element::stateToChar(elements[i].getState());

    str[index] = 0;
    return str;
}

Diagram &Diagram::operator=(const Diagram &d) {
    if (this != &d) {
        delete[] elements;
        elements = nullptr;
        size = d.size;
        if (size) {
            elements = new Element[size];
//            copyElems(elements, 0, d.elements, 0, size);
            memcpy(elements, d.elements, size);
        }
    }
    return *this;
}
