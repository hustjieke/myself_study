#include <iostream>

using namespace std;

union judge {
    short num;
    char ch[sizeof(short)];
};

int main()
{
    judge flag;
    flag.num = 0x1122;

    if (sizeof(short) != 2) {
        cout << "short length: " << sizeof(short) << endl;
    }

    cout << hex << &(flag.ch[0]) << ": " << hex << flag.ch[0] << endl;
    cout << hex << &(flag.ch[1]) << ": " << hex << flag.ch[1] << endl;
    //cout << ": " << flag.ch[0] << endl;

    return 0; 
}
