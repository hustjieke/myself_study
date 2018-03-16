#include <iostream>
#include <cstdint>
#include <sstream>
#include <vector>

using namespace std;

void print(int*) {
    // do nothing
}

int main()
{
    vector<int> vecInt;
    cout << "size:" << sizeof(vecInt) << endl;
    cout << "size:" << vecInt.size() << endl;
    cout << "size:" << vecInt.capacity() << endl;
    vecInt.reserve(9);
    cout << "size:" << sizeof(vecInt) << endl;
    cout << "size:" << vecInt.size() << endl;
    cout << "size:" << vecInt.capacity() << endl;
    vecInt.reserve(8);
    cout << "size:" << sizeof(vecInt) << endl;
    cout << "size:" << vecInt.size() << endl;
    cout << "size:" << vecInt.capacity() << endl;
    //vecInt.resize(10);
    //cout << "size:" << sizeof(vecInt) << endl;
    //cout << "size:" << vecInt.size() << endl;
    //cout << "size:" << vecInt.capacity() << endl;
    //vecInt.resize(1);
    //cout << "size:" << sizeof(vecInt) << endl;
    //cout << "size:" << vecInt.size() << endl;
    //cout << "size:" << vecInt.capacity() << endl;
    return 0;
    /*
    std::ostringstream oss;
    int32_t a = 8;
    int32_t b = 9;
    int32_t c = 12;
    oss << "-" << a << "-" << b << "-" << c;
    cout << oss.str();

    //cout << "a" << a << "b" << b << "c" << c;
    print(NULL);

    return 0;
    */
}
