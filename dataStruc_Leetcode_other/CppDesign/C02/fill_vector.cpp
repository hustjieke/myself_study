//: C02:fill_vector.cpp
// Copy an entire file into a vector of string
#include <string>
#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

int main()
{
    vector<string> v;
    ifstream in("fill_vector.cpp");
    string  line;

    while (getline(in, line)) {
        v.push_back(line); // Add the line to the end
    }

    // Add line numbers
    for (int i = 0; i < v.size(); i++) {
        cout << i << ": " << v[i] << "---" << i << endl;
    }

    return 0;
} ///:~
