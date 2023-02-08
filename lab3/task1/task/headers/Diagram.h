#ifndef TASK_DIAGRAM_H
#define TASK_DIAGRAM_H

#include "Element.h"

class Diagram {
private:
    static const int N = 10;
    int size;
    Element elements[N];

public:
    static const int getN();
    int getSize() const;
    void setSize(int size);
    int getDuration(int n) const;
    Element *getElements();

    Diagram();
    Diagram(State state);
    Diagram(char *str);

    void input(char *str, int time);
    void print();
    void unite(Diagram &d);
    void change(Diagram &d, int time);
    void copy(int n);
    void rotateRight(int offset);
    void rotateLeft(int offset);
};

#endif
