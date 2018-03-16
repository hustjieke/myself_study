// C16:template.cpp
// write a template for test

#include <iostream>
using namespace std;

template <typename T>

int compare(const T& v1, const T& v2) {
    if (v1 < v2) return -1;
    if (v1 > v2) return 1;

    return 0;
}

int main()
{
    int ret = compare(5, 6);
    cout << "return: " << ret << endl;

    ret = compare("abc", "def");
    cout << "return: " << ret << endl;

    return 0;
}
