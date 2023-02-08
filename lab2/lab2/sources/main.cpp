#include "Tractrix.h"
#include "../headers/dialog.h"

using namespace std;

int main() {
    setlocale(LC_ALL, "ru");

    lab2::Tractrix tractrix;
    lab2::dialog(tractrix);

    return 0;
}