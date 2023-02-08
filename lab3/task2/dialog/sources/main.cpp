#include <iostream>
#include "Diagram.h"
#include "dialog.h"

int main() {
    setlocale(LC_ALL, "ru");

    Diagram d = create();
    dialog(d);

    return 0;
}
