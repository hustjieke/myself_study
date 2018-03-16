//===================================================================
// Copyright(c) : 2016-20xx BONC.Inc
// FileName     : athletes.h (UTF-8)
// Summary      : define subclass(Athlete) inherited from parent(Human) 
// Author       : Gaoriyao
// Version      : v1.0
// CreatTime    : 2016-5-22
// Description  : Hello World in C++, Ansi-style
// History      : #
//===================================================================

#ifndef PERSON_DESIGN_INCLUDE_ATHLETE_H_
#define PERSON_DESIGN_INCLUDE_ATHLETE_H_

#include "human.h"

// ClassName: Athlete
// Author   : Gaoriyao    
// Brief    : inherited all menbers from Human ,define specific members
//            belong to Athlete
class Athlete : public Human {
    public:
        Athlete() {}

        Athlete(string name_t, int age_t, string ID_t, bool gender_t,
                string profession_t, int training_years_t)
            :Human(name_t, age_t, ID_t, gender_t, profession_t),
            m_training_years(training_years_t) {}

        Athlete(const Athlete& obj) : Human(obj) {
            m_training_years = obj.m_training_years;
        }

        Athlete& operator=(const Athlete& obj) {
            Human::operator=(obj);            
            m_training_years = obj.m_training_years;

            return *this;
        }


        virtual void setTrainingYears(const int& training_years_t) = 0;

        // behaviour that all Athlete owned
        virtual void train() const = 0;

        // diffirent subclasses execute diffirent sport 
        virtual void doSport() const = 0;

        ~Athlete() {}

    protected:
        int m_training_years;
        double m_salaries;

        // follow change with trainning years
        virtual void setSalaries(const int& training_years_t) = 0;
};

#endif
