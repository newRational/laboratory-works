#include "Diagram.h"
#include <iostream>
#include <cstring>

using namespace std;

//------------------------------------------

void printElems(Element *elems, int size) {
    for (int i = 0; i < size; i++) {
        cout << i << ") ";
        cout << Element::stateToChar(elems[i].getState()) << " : ";
        cout << elems[i].getDuration() << endl;
    }
}

void showElems(Element *elems, int size) {
    for (int i = 0; i < size; i++)
        for (int j = 0; j < elems[i].getDuration(); j++)
            cout << Element::stateToChar(elems[i].getState());
    cout << endl;
}

//------------------------------------------

const int Diagram::getN() {
    return N;
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

Diagram::Diagram() : size(1) {
    elements[0].setDuration(N);
}

Diagram::Diagram(State state) : size(1) {
    elements[0].setState(state);
    elements[0].setDuration(N);
}

int parse(Element *elements, char *str) {
    if (!strlen(str)) return 0;

    char symbol = str[0];
    int duration = 0;
    int index = 0;

    for (int i = 0; i < strlen(str); i++) {
        if (symbol == str[i]) duration++;
        else {
            elements[index].setState(Element::charToState(symbol));
            elements[index].setDuration(duration);

            symbol = str[i];
            duration = 1;
            index++;
        }
    }

    elements[index].setState(Element::charToState(symbol));
    elements[index].setDuration(duration);

    return index + 1;
}

int countElems(char *str) {
    if (!strlen(str)) return 0;

    char symbol = str[0];
    int count = 1;

    for (int i = 0; i < strlen(str); i++)
        if (symbol != str[i]) {
            symbol = str[i];
            count++;
        }

    return count;
}

Diagram::Diagram(char *str) : size(0) {
    if (countElems(str) > N)
        throw invalid_argument("too many elements");

    size = parse(elements, str);
}

Diagram::Diagram(Element e) : size(1) {
    elements[0].setState(e.getState());
    elements[0].setDuration(e.getDuration());
}

int findIndex(Diagram &d, int time) {
    int fullDuration = d.getDuration(d.getSize());
    if (time == (fullDuration + 1)) return d.getSize();

    for (int i = 0; i <= d.getSize(); i++)
        if (time <= d.getDuration(i))
            return i - 1;
}

State findState(Diagram &d, int time) {
    int index = findIndex(d, time);
    return (d.getElements())[index].getState();
}

bool validToInsert(Diagram &d, char *str, int time) {
    if (!strlen(str)) return true;
    if (time > d.getDuration(d.getSize()) + 1)
        throw invalid_argument("too much time");

    int count = d.getSize() + countElems(str);
    State leftState = Element::charToState(str[0]);
    State rightState = Element::charToState(str[strlen(str) - 1]);

    if (time > 1 && time <= d.getDuration(d.getSize())) {
        if (findState(d, time) == findState(d, time - 1)) count++;
    }

    if (time == 1) {
        if (findState(d, time) == rightState) count--;
    }
    else if (time == d.getDuration(d.getSize()) + 1) {
        if (findState(d, time - 1) == leftState) count--;
    }
    else {
        if (findState(d, time - 1) == leftState) count--;
        if (findState(d, time) == rightState) count--;
    }

    return count <= d.getN();
}

void copyElems(Element *dest, int startOfDest, const Element *source, int startOfSource, int size) {
    for (int i = 0; i < size; i++)
        dest[i + startOfDest] = source[i + startOfSource];
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

void insert(Diagram &d, Element *inserted, Element *buffer, int time, char *str) {
    int indexOfInserting = findIndex(d, time);
    int bufferSize = d.getSize() - indexOfInserting;

    correctDuration(d, time);

    if (indexOfInserting != d.getSize() && d.getElements()[indexOfInserting].getDuration())
        indexOfInserting++;

    Element *tmp = new Element[12];
    copyElems(tmp, 0, d.getElements(), 0, indexOfInserting);
    copyElems(tmp, indexOfInserting, inserted, 0, countElems(str));

    if (buffer != nullptr)
        copyElems(tmp, indexOfInserting + countElems(str), buffer, 0, bufferSize);

    int newSize = correctSize(d, time) + countElems(str);

    cout << "show elems : ";
    showElems(tmp, newSize);
    cout << endl;

    int correctedSize = correct(tmp, newSize);

    d.setSize(correctedSize);
    copyElems(d.getElements(), 0, tmp, 0, correctedSize);
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

    if (findState(*this, time) == findState(*this, time - 1)) newSize++;
    if (newSize > N) throw logic_error("too much elements of signal after rotate");

    int oldRightSize = size - index;
    Element *oldRight = toBuffer(*this, time);
    correctDuration(*this, time);

    int oldLeftSize = newSize - oldRightSize;
    Element *oldLeft = new Element[oldLeftSize];
    copyElems(oldLeft, 0, elements, 0, oldLeftSize);

    Element *elems = new Element[newSize];
    copyElems(elems, 0, oldRight, 0, oldRightSize);
    copyElems(elems, oldRightSize, oldLeft, 0, oldLeftSize);

    size = correct(elems, newSize);
    copyElems(elements, 0, elems, 0, size);
}

void Diagram::operator<<=(int offset) {
    *this >>= (getDuration(size) - offset);
}

void Diagram::operator*=(int n) {
    if (!n) throw invalid_argument("n must be positive");
    if (n == 1) return;

    bool equals = elements[0].getState() == elements[size-1].getState();
    int sizeOfCopiedPart = equals ? size - 1 : size;
    int startOfSource = equals ? 1 : 0;

    if (!equals && n * sizeOfCopiedPart > N)
        throw invalid_argument("too big n");
    else if (equals && n * sizeOfCopiedPart + 1 > N)
        throw invalid_argument("too big n");

    Element *elems = new Element[n * sizeOfCopiedPart];
    copyElems(elems, 0, elements, startOfSource, size);

    if (equals) {
        int dur1 = elements[0].getDuration();
        int dur2 = elements[size-1].getDuration();

        for (int i = 0; i < n-1; i++) {
            elements[size-1].setDuration(dur1 + dur2);
            copyElems(elements, size, elems, 0, sizeOfCopiedPart);
            size += sizeOfCopiedPart;
        }

    }
    else {
        for (int i = 0; i < n-1; i++) {
            copyElems(elements, size, elems, 0, sizeOfCopiedPart);
            size += sizeOfCopiedPart;
        }
    }
}

void Diagram::operator()(Diagram &d, int time) {
    if (time < 1 || time > getDuration(size) + 1)
        throw invalid_argument("invalid time");

    int index = findIndex(*this, time - 1);
    bool equals1 = elements[index].getState() == d.elements[0].getState();
    bool equals2 = elements[index].getState() == elements[findIndex(*this, time)].getState();

    int newSize = findIndex(*this, time) + d.getSize() - (equals2 ? 0 : 1);
    if (newSize > N) throw logic_error("too many new elements");
    size = newSize;

    int startOfSource = 0;

    if (equals1) {
        elements[index].setDuration(time - 1 - getDuration(index) + d.elements[0].getDuration());
        startOfSource++;
    }

    copyElems(elements, index + 1, d.getElements(), startOfSource, d.getSize());
}

void Diagram::operator+=(const Diagram &d) {
    bool equals = false;
    if (size) equals = elements[size-1].getState() == d.elements[0].getState();

    int uniteSize = size + d.getSize() + (equals ? -1 : 0);
    if (uniteSize > N) throw logic_error("too long unite signal");

    int startOfSource = 0;

    if (equals) {
        elements[size-1].setDuration(elements[size-1].getDuration() + d.elements[0].getDuration());
        startOfSource++;
    }

    copyElems(elements, size, d.elements, startOfSource, d.getSize());

    size = uniteSize;
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
