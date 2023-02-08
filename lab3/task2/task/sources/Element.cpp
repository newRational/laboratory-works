#include "Element.h"
#include <iostream>
#include <cstring>

using namespace std;

Element::Element() : state(NON), duration(1) {}

int countElems(char *str);
int parse(Element *elements, char *str);
Element::Element(char *str) {
    if (!strlen(str)) {
        state = NON;
        duration = 0;
    }

    if (countElems(str) > 1)
        throw invalid_argument("too many elems");

    state = Element::charToState(str[0]);
    duration = strlen(str);
}

State Element::getState() const {
    return state;
}

void Element::setState(State state) {
    Element::state = state;
}

int Element::getDuration() const {
    return duration;
}

void Element::setDuration(int duration) {
    Element::duration = duration;
}

char Element::stateToChar(State state) {
    switch (state) {
        case NON:
            return 'x';

        case ZERO:
            return '_';

        case ONE:
            return '-';
    }
}

State Element::charToState(char symbol) {
    switch (symbol) {
        case 'x':
        case 'X':
            return NON;

        case '0':
        case '_':
            return ZERO;

        case '1':
        case '-':
            return ONE;

        default:
            throw invalid_argument("illegal symbol");
    }
}