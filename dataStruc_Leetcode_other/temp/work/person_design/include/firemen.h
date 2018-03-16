//===================================================================
// Copyright(c) : 2016-20xx BONC.Inc
// FileName     : firemen.h (UTF-8)
// Summary      : define subclass(Firemen) inherited from parent(Human) 
// Author       : Gaoriyao
// Version      : v1.0
// CreatTime    : 2016-5-22
// Description  : Hello World in C++, Ansi-style
// History      : #
//===================================================================


#ifndef PERSON_DESIGN_INCLUDE_FIREMEN_H_
#define PERSON_DESIGN_INCLUDE_FIREMEN_H_

#include "human.h"

using namespace std;

// ClassName: Athlete
// Author   : Gaoriyaoi 
// Brief    : inherited all menbers from Human ,define specific members
//            belong to Firemen
class Firemen : public Human {
    public:
        Firemen() {}

        Firemen(string name_t, int age_t, string ID_t, bool gender_t, string 
                profession_t, string fire_station_t, int years_of_service_t)
            :Human(name_t, age_t, ID_t, gender_t, profession_t),
            m_fire_station(fire_station_t),
            m_years_of_service(years_of_service_t) {
                m_salaries = 100 * age_t;
            }

        Firemen(const Firemen& obj) : Human(obj) {
            m_fire_station = obj.m_fire_station;
            m_years_of_service = obj.m_years_of_service;
            m_salaries = obj.m_salaries;
        }

        Firemen& operator=(const Firemen& obj) {
            Human::operator=(obj);
            m_fire_station = obj.m_fire_station;
            m_years_of_service = obj.m_years_of_service;
            m_salaries = obj.m_salaries;

            return *this;
        }

        void setFireStation(const string& fire_station_t);    
        void setYearsOfService(const int& years_of_service_t);

        void putOutFire() const; // action belong to firemen

        // virtual inherited
        void sleep() const;
        void entertain() const;
        void selfIntroduction() const;

        // overload
        void setAge(const int& age_t);

        // virtual inherited, execute behaviours that Firemen owned
        void doAction() const; 

        ~Firemen() {}

    private:
        string m_fire_station;
        int  m_years_of_service;
        double m_salaries;
        void setSalaries(const int& m_age);
};

#endif
