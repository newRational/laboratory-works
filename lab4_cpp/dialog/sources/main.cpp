#include <iostream>

using namespace std;

class A
{
private:
    int num;
public:
    A(int num): num(num) {};
    A operator+(const A &a) const
    {
        return A(num + a.num);
    }
    friend ostream &operator<<(ostream &, const A &);
};

ostream &operator<< (ostream &os, const A &a)
{
    cout << a.num;
    return os;
}

int main() {
    A a1(1);
    A a2(2);
    A a3 = a1 + a2;
    cout << a1 << a2 << a3 << endl;
    return 0;
}
