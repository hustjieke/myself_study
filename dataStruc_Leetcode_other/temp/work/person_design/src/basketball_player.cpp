//========================================================
// Copyright(c) : 2016-20xx BONC.Inc
// FileName     : basketball_player.cpp (UTF-8)
// Summary      : define functions in header file "basketball_player.h"
// Author       : Gaoriyao
// Version      : v1.0
// CreatTime    : 2016-5-22
// Description  : Hello World in C++, Ansi-style
// History      : # 
//========================================================


#include "basketball_player.h"
#include "judge_string.h"
#include "athletes.h"

// inherited from Athlete
void BasketballPlayer::setTrainingYears(const int& training_years_t) {
    Athlete::m_training_years = training_years_t;
    setSalaries(training_years_t);
}

// inherited from Athlete
void BasketballPlayer::setSalaries(const int& training_years_t) {
    Athlete::m_salaries = 1200 + 80 * training_years_t;
}

void BasketballPlayer::setClub(string club_t) {
    judgeString(club_t);

    m_club = club_t;
}

// virtual func,execute action belong to Runners
void BasketballPlayer::doSport() const {
    cout << "I`m playing basketball!" << endl;
}

// virtual func,execute action belong to Runners
void BasketballPlayer::train() const {
    cout << "Trainning: " << "Basketball" << endl;
}

// virtual func,execute action belong to Runners
void BasketballPlayer::sleep() const {
    cout << "I sleep 7.5 hours one day" << endl;
}

// virtual func,execute action belong to Runners
void BasketballPlayer::entertain() const {
    cout << "Entertainment: " << "Boxing" << endl; 
}

// inherited from Human
void BasketballPlayer::selfIntroduction() const {
    cout << "My name is: " << m_name << endl; 
    cout << "My job is " << m_profession << endl;
}



// virtual func,execute all actions including Human basic action
void BasketballPlayer::doAction() const {
    selfIntroduction();

    // execute behavious
    doSport();
    eat(); // inherited from Human
    train();
    sleep();
    entertain();
}
