//: C02:get_words.cpp
//Break a file into whitespace-separated words

#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int main()
{
    vector<string> words;
    ifstream in("get_words.cpp");
    string word;
    while (in >> word) {
        words.push_back(word);
    }

    for (int i = 0; i < words.size(); i++) {
        cout << words[i] << "---" << i << endl;
    }
} ///:~
