#include <iostream>
#include <stdint.h>

using namespace std;
int main() {
    int64_t datetimeValue = 5555;
    int64_t* pInt = &datetimeValue;
    //char* pChar = dynamic_cast<char*>(pInt);
    char* pChar = &datetimeValue;
    //cout << "padding: " << *((int8_t*)((char*)(pInt)));
    cout << "padding: " << *((int8_t*)(pChar)) << endl;
    /*
    cout << "second: " << *((int8_t*)(pChar[1]));
    cout << "minute: " << *((int8_t*)(pChar[2]));
    cout << "hour: " << *((int8_t*)(pChar[3]));
    cout << "day: " << *((int8_t*)(pChar[4]));
    cout << "month: " << *((int8_t*)(pChar[5]));
    cout << "year: " << *((int16_t*)(pChar[6]));
    */

    return 0;
}
