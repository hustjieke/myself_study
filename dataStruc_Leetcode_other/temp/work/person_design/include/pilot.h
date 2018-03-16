//===================================================================
// Copyright(c) : 2016-20xx BONC.Inc
// FileName     : pilot.h(UTF-8)
// Summary      : define subclass(Pilot) inherited from parent(Human) 
// Author       : Gaoriyao
// Version      : v1.0
// CreatTime    : 2016-5-22
// Description  : Hello World in C++, Ansi-style
// History      : #
//===================================================================

#ifndef PERSON_DESIGN_INCLUDE_PILOT_H_
#define PERSON_DESIGN_INCLUDE_PILOT_H_

#include "human.h"

using namespace std;

// ClassName: Athlete
// Author   : Gaoriyaoi 
// Brief    : inherited all menbers from Human ,define specific members
//            belong to Pilot
class Pilot : public Human {
    public:
        Pilot() {}

        Pilot(string name_t, int age_t, string ID_t, bool gender_t,
              string profession_t, string airline_comp_t, string model_drived_t)
            :Human(name_t, age_t, ID_t, gender_t, profession_t), 
            m_airline_comp(airline_comp_t),
            m_model_drived(model_drived_t) {
                m_salaries = 200 * age_t;
            }

        Pilot(const Pilot& obj) : Human(obj) {
            m_airline_comp = obj.m_airline_comp;
            m_model_drived = obj.m_model_drived;
            m_salaries     = obj.m_salaries;
        }

        Pilot& operator=(const Pilot& obj) {
            Human::operator=(obj);
            m_airline_comp = obj.m_airline_comp;
            m_model_drived = obj.m_model_drived;
            m_salaries     = obj.m_salaries;

            return *this;
        }
             
        void setAirlineComp(const string& airline_comp_t);
        void setModelDrived(const string& model_drived_t);

        // virtual inherited from Human
        void sleep() const; 
        void entertain() const; 
        void selfIntroduction() const;

        // overload 
        void setAge(const int& age_t);

        // action belong to Pilot
        void drivePlane() const;

        // virtual func, execute all behaviours that Pilot owned
        void doAction() const;

        ~Pilot() {}

    private:
        string m_airline_comp; // which company belong to
        string m_model_drived; // Aircraft Model drived
        double m_salaries;
        void setSalaries(const int& salaries_t);
};


#endif
