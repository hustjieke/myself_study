//========================================================
// Copyright(c) : 2016-20xx BONC.Inc
// FileName     : football_player.cpp (UTF-8)
// Summary      : define functions in header file "football_player.h"
// Author       : Gaoriyao
// Version      : v1.0
// CreatTime    : 2016-5-22
// Description  : Hello World in C++, Ansi-style
// History      : # 
//========================================================


#include "football_player.h"
#include "judge_string.h"
#include "athletes.h"

// inherited from Athlete
void FootballPlayer::setTrainingYears(const int& training_years_t) {
    Athlete::m_training_years = training_years_t;
    setSalaries(training_years_t);
}

// inherited from Athlete
void FootballPlayer::setSalaries(const int& training_years_t) {
    Athlete::m_salaries = 1500 + 50 * training_years_t;
}

void FootballPlayer::setClub(string club_t) {
    judgeString(club_t);

    m_club = club_t;
}

// virtual func,execute action belong to Runners
void FootballPlayer::train() const {
	cout << "Training: " << "football" << endl;
}

// virtual func,execute action belong to Runners
void FootballPlayer::sleep() const {
	cout << "I sleep 8 hours one day" << endl;
}

// virtual func,execute action belong to Runners
void FootballPlayer::entertain() const {
	cout << "Entertaining: " << "Dancing" << endl;
}

// virtual func,execute action belong to Runners
void FootballPlayer::doSport() const {
    cout << "I`m playing football!" << endl;
}

// inherited from Human
void FootballPlayer::selfIntroduction() const {
	cout << "My name is: " << m_name << " Age: " << m_age << endl;
	cout << "My job is: " << m_profession << endl;
}

// virtual func,execute all actions including Human basic action
void FootballPlayer::doAction() const {
    selfIntroduction();

	eat(); // inherited from Human
	train();
	sleep();
	entertain();
	doSport();
}
