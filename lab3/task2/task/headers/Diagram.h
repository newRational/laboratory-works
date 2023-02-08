#ifndef TASK_DIAGRAM_H
#define TASK_DIAGRAM_H

#include <iostream>
#include "Element.h"

using namespace std;

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
    Diagram(char *str);
    Diagram(Element e);
    Diagram(State state);

    friend ostream &operator << (ostream &, const Diagram &);
    friend Diagram &operator << (Diagram &d, char *);
    friend Diagram operator + (const Diagram &, const Diagram &);
    void operator >>= (int);
    void operator <<= (int);
    void operator *= (int);
    void operator () (Diagram &, int);
    void operator += (const Diagram &);
    char *toStr();
};

#endif
