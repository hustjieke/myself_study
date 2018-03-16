//========================================================
// Copyright(c) : 2016-20xx BONC.Inc
// FileName     : pilot.cpp (UTF-8)
// Summary      : define class member functions in header file "Pilot.h"
// Author       : Gaoriyao
// Version      : v1.0
// CreatTime    : 2016-5-22
// Description  : Hello World in C++, Ansi-style
// History      : # 
//========================================================


#include "pilot.h"

#include <iostream>

#include "human.h"
#include "judge_string.h"

using namespace std;

void Pilot::setAirlineComp(const string& airline_comp_t) {
    judgeString(airline_comp_t);

    m_airline_comp = airline_comp_t;
}

void Pilot::setModelDrived(const string& model_drived_t) {
    judgeString(model_drived_t);

    m_model_drived = model_drived_t;
}

void Pilot::setAge(const int& age_t) {
    Human::m_age = age_t; // m_age is protected
    setSalaries(age_t);
}

void Pilot::setSalaries(const int& age_t) {
    m_salaries = (double)200 * age_t;
}

// virtual inherited from Human
void Pilot::sleep() const {
    cout << "I sleep 10 hours one day!" << endl;
} 

// virtual inherited from Human
void Pilot::entertain() const {
    cout << "Entertain: " << "cycling" << endl;
}

void Pilot::selfIntroduction() const {
    cout << "Pilot self-introduction:" << endl;
    cout << "My name is: " << m_name << "age: " << m_age 
        << "ID: " << m_ID << endl;
    cout << "My job is " << m_profession << endl;
}

// action belong to Pilot
void Pilot::drivePlane() const {
    cout << "I can drive plane!" << endl;
}

// virtual func, execute all behaviours that Pilot owned
void Pilot::doAction() const {
    selfIntroduction();

    eat(); // inherited from Human
    sleep();
    entertain(); 
    drivePlane();
}
