//===================================================================
// Copyright(c) : 2016-20xx BONC.Inc
// FileName     : basketball_player.h (UTF-8)
// Summary      : define subclass(BasketballPlayer) inherited from parent(Athlete) 
// Author       : Gaoriyao
// Version      : v1.0
// CreatTime    : 2016-5-22
// Description  : Hello World in C++, Ansi-style
// History      : #
//===================================================================


#ifndef PERSON_DESIGN_INCLUDE_BASKETBALL_PLAYER_H_
#define PERSON_DESIGN_INCLUDE_BASKETBALL_PLAYER_H_

#include "athletes.h"

// ClassName: Student
// Author   : Gaoriyaoi 
// Brief    : inherited all menbers from Athlete,define specific members
//            belong to BasketballPlayer
class BasketballPlayer : public Athlete {
	public:
		BasketballPlayer() {}

		BasketballPlayer(string name_t, int age_t, string ID_t, bool gender_t,
				string profession_t, int training_years_t, string club_t)
			:Athlete(name_t, 
					age_t, 
					ID_t, 
					gender_t, 
                    profession_t,
					training_years_t), 
			m_club(club_t) {
				m_salaries = 1200 + 80 * training_years_t;
			}

		BasketballPlayer(const BasketballPlayer& obj) : Athlete(obj) {
			m_salaries  = obj.m_salaries;
			m_club 	    = obj.m_club;
		}

        // inherited from Athlete
        void setTrainingYears(const int& training_years_t); 

        // inherited from Athlete
        void setSalaries(const int& training_years_t);

		void setClub(string club_t);

		// virtual func,execute action belong to Runners
		void doSport() const;

		// virtual func,execute action belong to Runners
		void train() const;

        // inherited from Human
		void sleep() const; 

        // inherited from Human
		void entertain() const; 

        // inherited from Human
        void selfIntroduction() const;

		// virtual func,execute all actions including Human basic action
		void doAction() const;

		~BasketballPlayer() {}

	private:
		string m_club;
};

#endif


