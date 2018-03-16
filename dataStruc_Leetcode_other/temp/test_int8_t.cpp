#include <iostream>
#include <string>
#include <stdint.h>

using namespace std;
int main() {
    int8_t temp = 0;
    char a = '\0';
    //char a = 'null';
    cout << "temp is..." << *reinterpret_cast<char*>(&temp) << "...." << endl;
    cout << "a is..." << *reinterpret_cast<int8_t*>(&a) << "...." << endl;

    return 0;
}
