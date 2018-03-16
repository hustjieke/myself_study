//: C02:s_copy.cpp
//Copy one file to another, a line at a time

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main()
{
    ifstream in("s_copy.cpp"); // Open for reading
    ofstream out("s_copy2.cpp"); // Open or writing

    string s;
    while (getline(in, s)) // Discards newline char
        out << s << "\n"; // ... must add it back

    return 0;
} ///:~
