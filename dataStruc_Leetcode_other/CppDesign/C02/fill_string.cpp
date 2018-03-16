//: C02:fill_string.cpp
// Read an entire file into a single string
#include <iostream>
#include <string>
#include <fstream>

using namespace std;

int main()
{
    ifstream in("fill_string.cpp");
    string s, line;
    
    while (getline(in, line))
        s += line + "\n";
    cout << s;

    return 0;
} ///:~
