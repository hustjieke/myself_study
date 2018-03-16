//: C03:pass_address.cpp

#include <iostream>

using namespace std;

void f(int* const p) {
    cout << "p = " << p << endl;
    cout << "*p = " << *p << endl;

    *p = 5;
    cout << "p = " << p << endl;
    cout << endl;
    const int a = 55;

    //p = &a;
    //cout << "p = " << p << endl;
    //cout << "*p = " << *p << endl;
}

int main()
{
    int x = 47;
    cout << "x = " << x << endl;
    cout << "&x = " << &x << endl;
    f(&x);

    const int a = 44;
    cout << "x = " << x << endl;

    return 0;

}
