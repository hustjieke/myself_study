//===================================================================
// Copyright(c) : 2016-20xx BONC.Inc
// FileName     : one_hundred_m_runner.h (UTF-8)
// Summary      : define subclass(Runners) inherited from parent(Athlete) 
// Author       : Gaoriyao
// Version      : v1.0
// CreatTime    : 2016-5-22
// Description  : Hello World in C++, Ansi-style
// History      : #
//===================================================================


#ifndef PERSON_DESIGN_INCLUDE_ONE_HUNDRED_M_RUNNERS_H_
#define PERSON_DESIGN_INCLUDE_ONE_HUNDRED_M_RUNNERS_H_

#include "athletes.h"
#include "human.h"

// ClassName: Student
// Author   : Gaoriyaoi 
// Brief    : inherited all menbers from Athlete,define specific members
//            belong to Runners
class Runners : public Athlete {
    public:
        Runners() {}
        Runners(string name_t, int age_t, string ID_t, bool gender_t,
                string profession_t, int training_years_t)
            :Athlete(name_t, age_t, ID_t, gender_t, profession_t, 
                     training_years_t) {
				m_salaries = 1000 + 100 * training_years_t;
			}

		Runners(const Runners& obj) : Athlete(obj) {
			m_salaries = obj.m_salaries;
		}

		Runners& operator=(const Runners& obj) {
			m_salaries = obj.m_salaries;
			Athlete::operator=(obj);

			return *this;
		}


        // inherited from Athlete
        void setTrainingYears(const int& training_years_t); 

        // inherited from Athlete
        void setSalaries(const int& training_years_t);

        // virtual func,execute action belong to Runners
        void doSport() const;

        // behaviour that all Athlete owned
        void train() const;

        void sleep() const; // inherited from Human

        void entertain() const; // inherited from Human

        void selfIntroduction() const; // inherited from Human

        void doAction() const; // inherited from Human

        ~Runners() {}
};


#endif
