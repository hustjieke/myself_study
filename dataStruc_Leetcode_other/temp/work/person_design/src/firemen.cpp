//========================================================
// Copyright(c) : 2016-20xx BONC.Inc
// FileName     : firemen.cpp (UTF-8)
// Summary      : define functions in header file "firemen.h"
// Author       : Gaoriyao
// Version      : v1.0
// CreatTime    : 2016-5-22
// Description  : Hello World in C++, Ansi-style 
// History      : # 
//========================================================


#include "firemen.h"
#include "judge_string.h"

using namespace std;

void Firemen::setFireStation(const string& fire_station_t) {
    judgeString(fire_station_t);

    m_fire_station = fire_station_t;
}

void Firemen::setYearsOfService(const int& years_of_service_t) {
    m_years_of_service = years_of_service_t;
    setSalaries(years_of_service_t); // salaries follow changed
}

// salaries func, private
void Firemen::setSalaries(const int& m_age) {
    m_salaries = (double)100 * m_age;
    cout << m_salaries << endl;
}

// overload
void Firemen::setAge(const int& age_t) {
    Human::m_age = age_t;
    setSalaries(age_t);
}

// action belong to firemen
void Firemen::putOutFire() const {
    cout << "I can put out fire!" << endl;    
}

// virtual inherited
void Firemen::entertain() const {
    cout << "Entertain: " << "Fish" << endl;
}
// virtual inherited
void Firemen::sleep() const {
    cout << "I sleep 8 hours one day!" << endl;
}

void Firemen::selfIntroduction() const {
    cout << "Firemen self-introduction: " << endl;
    cout << "My name is " << m_name << ", age " << m_age
        << ", ID " << m_ID << endl;
    cout << "My job is " << m_profession << endl;
}

// virtual func, execute all behaviours that Firemen owned
void Firemen::doAction() const {
    selfIntroduction();

    eat(); // inherited from Human
    sleep();
    entertain();
    putOutFire();
}
