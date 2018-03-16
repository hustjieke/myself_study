#include <iostream>

using namespace std;

class X{ };
class Y : public virtual X{ };
class Z : public virtual X{ };
class A : public Y, public Z { };

int main()
{
    int *p;
    cout << "X: " << sizeof(X) << endl    
        << "Y: " << sizeof(Y) << endl
        << "Z: " << sizeof(Z) << endl
        << "A: " << sizeof(A) << endl;

    cout << "*P: " << sizeof(p) << endl;

    return 0;
}
