//========================================================
// Copyright(c) : 2016-20xx BONC.Inc
// FileName     : human.h (UTF-8)
// Summary      : define base class Human 
// Author       : Gaoriyao
// Version      : v1.0
// CreatTime    : 2016-5-22
// Description  : Hello World in C++, Ansi-style
// History      : # 
//========================================================

#ifndef PERSON_DESIGN_INCLUDE_HUMAN_H_
#define PERSON_DESIGN_INCLUDE_HUMAN_H_

#include <string.h>
#include <iostream>

using namespace std;

// ClassName: Human 
// Author   : Gaoriyaoi 
// Brief    : Declare basic private and public members 
class Human {

    public:
        Human() {};

        Human(string name_t, int age_t, string ID_t, bool gender_t, 
                string profession_t)
            :m_name(name_t), 
            m_age(age_t), 
            m_ID(ID_t), 
            m_gender(gender_t), 
            m_profession(profession_t) { obj_count++; }

        Human(const Human& obj)
            :m_name(obj.m_name), 
            m_age(obj.m_age), 
            m_ID(obj.m_ID), 
            m_gender(obj.m_gender), 
            m_profession(obj.m_profession) {}

        Human& operator=(const Human& obj) {
            m_name    = obj.m_name;
            m_age     = obj.m_age;
            m_ID      = obj.m_ID;
            m_gender  = obj.m_gender;
            return *this;
        }

        void setName(const string& name_t);

        void setAge(const int& age_t);

        void setID(const string& ID_t);

        void setGender(const bool& gender_t);

        virtual void eat() const; // common action

        virtual void sleep() const = 0; 

        virtual void entertain() const = 0; 

        virtual void selfIntroduction() const = 0;

        // show out all basic behaviours that human owned
        virtual void doAction() const = 0;

        // calculator how many obj creat and exist
        static int obj_count; 
        static void telepathicFunction();  

        virtual ~Human() { obj_count--; }

    protected:
        string m_name;
        int  m_age;
        string m_ID;
        bool m_gender;
        string m_profession;
};

#endif
