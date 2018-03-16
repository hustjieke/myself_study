//
//
// if temp_str is empty, print out error message and exit

#include "judge_string.h"

#include <cstdlib>
#include <iostream>

using namespace std;

void judgeString(string temp_str) {
    if (temp_str.empty()){
        cout << "Input string message error!" << endl;
        cout << "File: " << __FILE__ << "Line: " << __LINE__ << endl;
        exit(0);
    }
}
