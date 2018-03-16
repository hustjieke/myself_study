#include <iostream>

using namespace std;

void checkCUPendian() {
    union {
        unsigned short a;
        unsigned char b[2];
    } temp; 

    // judge 
    temp.a = 0x1122;
    if (0x11 == temp.b[0]) {
        cout << "CPU is Big-endian" << endl;
    } else {
        cout << "CPU is Little-endian" << endl;
    }

    // print value and address
    cout << hex << (int)temp.b[0] << "-->" << static_cast<const void*>(&temp.b[0]) << endl; 
    cout << hex << (int)temp.b[1] << "-->" << static_cast<const void*>(&temp.b[1]) << endl; 
}

int main() {
    checkCUPendian();

    return 0;
}
