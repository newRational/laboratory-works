#ifndef TASK_ELEMENT_H
#define TASK_ELEMENT_H

enum State {
    NON, ZERO, ONE
};

struct Element {
private:
    State state;
    int duration;

public:
    Element();

    State getState() const;
    void setState(State state);

    int getDuration() const;
    void setDuration(int duration);

    static char stateToChar(State state);
    static State charToState(char symbol);
};

#endif