//========================================================
// Copyright(c) : 2016-20xx BONC.Inc
// FileName     : one_hundred_m_runner.cpp (UTF-8)
// Summary      : define class member functions in header file "one_hundred_m_runner.h"
// Author       : Gaoriyao
// Version      : v1.0
// CreatTime    : 2016-5-22
// Description  : Hello World in C++, Ansi-style
// History      : # 
//========================================================


#include "one_hundred_m_runner.h"
#include "athletes.h"

void Runners::setTrainingYears(const int& training_years_t) {
    Athlete::m_training_years = training_years_t;
    setSalaries(training_years_t);
}

void Runners::setSalaries(const int& training_years_t) {
    Athlete::m_salaries = 1000 + 100 * training_years_t;    
}

// virtual func,execute action belong to Runners
void Runners::doSport() const {
	cout << "I`m participate in 100-meter race!" << endl;
}

// behaviour that all Athlete owned
void Runners::train() const {
	cout << "Trainning: " << "running~" << endl;
}

// inherited from Human
void Runners::sleep() const { 
	cout << "I sleep 7.5 hours a day!" << endl; 
}

// inherited from Human
void Runners::entertain() const { 
	cout << "Entertainments: " << "Singing!" << endl; 
}

void Runners::selfIntroduction() const {
	cout << "My name is: " << m_name << " Age: " << m_age
		<< " ID" << m_ID << endl;
	cout << "My job is: " << m_profession << endl;
}

// virtual func,execute all actions including Human basic action
void Runners::doAction() const {
    selfIntroduction();
	
	eat(); // inherited from base Human
	sleep();
	entertain();
	doSport();
	train();
}
