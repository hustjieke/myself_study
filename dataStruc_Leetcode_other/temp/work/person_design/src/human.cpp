//========================================================
// Copyright(c) : 2016-20xx BONC.Inc
// FileName     : main.cpp (UTF-8)
// Summary      : define functions in header file "human.h"
// Author       : Gaoriyao
// Version      : v1.0
// CreatTime    : 2016-5-22
// Description  : Hello World in C++, Ansi-style
// History      : # 
//========================================================


#include "human.h"
#include "judge_string.h"

using namespace std;

// init static var
int Human::obj_count = 0;

// define static func to print numbers of exist obj
void Human::telepathicFunction() {
    cout << "There are: " << Human::obj_count << "exist!" << endl;
}

// set a name
void Human::setName(const string& name_t) {
    judgeString(name_t);
    m_name = name_t;
}

// set age
void Human::setAge(const int& age_t) {
    if ((age_t < 0) || (age_t > 130)) {
        cout << "Warning!! You may input wrong No.,please check"
            << endl;
    }

    m_age = age_t;
}

// set ID for a human
void Human::setID(const string& ID_t) {
    judgeString(ID_t);

    if ((ID_t.size() < 17) || (ID_t.size() > 20)) {
        cout << "Input wrong ID!!" << endl;
    }   

    m_ID = ID_t;
}

void Human::selfIntroduction() const {
    cout << " " << endl;
}
void Human::setGender(const bool& gender_t) {
    if ((0 == gender_t) || (1 == gender_t)) {
        m_gender = gender_t;
        return ;
    }

    cout << "Please input true or false, true means male, false means female."
        << endl;
}

// common action
void Human::eat() const { cout << "I am eating rice!" << endl; }

