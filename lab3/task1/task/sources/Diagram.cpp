#include "Diagram.h"
#include <iostream>
#include <cstring>

using namespace std;

//------------------------------------------

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

Diagram::Diagram() : size(0) {}

Diagram::Diagram(State state) : size(N) {
    for (int i = 0; i < N; i++)
        elements[i].setState(state);
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
    if (countElems(str) > 10)
        throw invalid_argument("too many elements");

    size = parse(elements, str);
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

void copyElems(Element *dest, int startOfDest, Element *source, int startOfSource, int size) {
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
    int newSize = correctSize(d, time) + countElems(str);

    correctDuration(d, time);

    if (indexOfInserting != d.getSize() && d.getElements()[indexOfInserting].getDuration())
        indexOfInserting++;

    Element *tmp = new Element[12];
    copyElems(tmp, 0, d.getElements(), 0, indexOfInserting);
    copyElems(tmp, indexOfInserting, inserted, 0, countElems(str));

    if (buffer != nullptr)
        copyElems(tmp, indexOfInserting + countElems(str), buffer, 0, bufferSize);

    int correctedSize = correct(tmp, newSize);

    d.setSize(correctedSize);
    copyElems(d.getElements(), 0, tmp, 0, correctedSize);
}

void Diagram::print() {
    if (!size) return;
    for (int i = 0; i < size; i++)
        for (int j = 0; j < elements[i].getDuration(); j++)
            cout << Element::stateToChar(elements[i].getState());
    cout << endl;
}

void Diagram::input(char *str, int time) {
    if (!validToInsert(*this, str, time))
        throw invalid_argument("too many elements");

    Element *inserted = toElements(str);
    Element *buffer = toBuffer(*this, time);
    insert(*this, inserted, buffer, time, str);
}

void Diagram::unite(Diagram &d) {
    bool equals = false;
    if (size) equals = elements[size-1].getState() == d.elements[0].getState();

    int uniteSize = size + d.getSize() + (equals ? -1 : 0);
    if (uniteSize > N) throw logic_error("too long unite signal");

    int startOfSource = 0;

    if (equals) {
        elements[size-1].setDuration(elements[size-1].getDuration() + d.getElements()[0].getDuration());
        startOfSource++;
    }

    copyElems(elements, size, d.elements, startOfSource, d.getSize());
    size = uniteSize;
}

void Diagram::change(Diagram &d, int time) {
    if (time > (d.getDuration(d.getSize()) + 1))
        throw invalid_argument("too much time");

    int index = findIndex(*this, time - 1);
    bool equals1 = elements[index].getState() == d.elements[0].getState();
    bool equals2 = elements[index].getState() == elements[findIndex(*this, time)].getState();

    size = findIndex(*this, time) + d.getSize();
    int startOfSource = 0;

    if (equals1) {
        elements[index].setDuration(time - 1 - getDuration(index) + d.elements[0].getDuration());
        size -= equals2 ? 0 : 1;
        startOfSource++;
    }

    copyElems(elements, index + 1, d.getElements(), startOfSource, d.getSize());

}

void Diagram::copy(int n) {
    if (!n)return;
    bool equals = elements[0].getState() == elements[size-1].getState();
    int sizeOfCopiedPart = equals ? size - 1 : size;
    int startOfSource = equals ? 1 : 0;

    if ((n + 1) * sizeOfCopiedPart > N)
        throw invalid_argument("too big count of repetitions");

    Element *elems = new Element[(n + 1) * sizeOfCopiedPart];
    copyElems(elems, 0, elements, startOfSource, size);

    if (equals) {
        int dur1 = elements[0].getDuration();
        int dur2 = elements[size-1].getDuration();

        for (int i = 0; i < n; i++) {
            elements[size-1].setDuration(dur1 + dur2);
            copyElems(elements, size, elems, 0, sizeOfCopiedPart);
            size += sizeOfCopiedPart;
        }

    }
    else {
        for (int i = 0; i < n; i++) {
            copyElems(elements, size, elems, 0, sizeOfCopiedPart);
            size += sizeOfCopiedPart;
        }
    }
}

void Diagram::rotateRight(int offset) {
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

void Diagram::rotateLeft(int offset) {
    rotateRight(getDuration(size) - offset);
}


