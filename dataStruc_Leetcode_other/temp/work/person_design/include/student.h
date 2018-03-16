//===================================================================
// Copyright(c) : 2016-20xx BONC.Inc
// FileName     : student.h (UTF-8)
// Summary      : define subclass(Student) inherited from parent(Human) 
// Author       : Gaoriyao
// Version      : v1.0
// CreatTime    : 2016-5-22
// Description  : Hello World in C++, Ansi-style
// History      : #
//===================================================================


#ifndef PERSON_DESIGN_INCLUDE_STUDENT_H_
#define PERSON_DESIGN_INCLUDE_STUDENT_H_

#include "human.h"

// ClassName: Student
// Author   : Gaoriyaoi 
// Brief    : inherited all menbers from Human,define specific members
//               belong to student
class Student : public Human {
    public:
        Student() {};

        Student(string name_t, int age_t, string ID_t, bool gender_t, 
                string profession_t,
                string school_t, string student_ID_t, string grade_t)
            :Human(name_t, age_t, ID_t, gender_t, profession_t),
            m_school(school_t), 
            m_student_ID(student_ID_t), 
            m_grade(grade_t) {}

		Student(const Student& obj) : m_school(obj.m_school),
		m_student_ID(obj.m_student_ID), m_grade(obj.m_grade) {}

		Student& operator=(const Student& obj) {
			Human::operator=(obj);
			m_school 	 = obj.m_school;
			m_student_ID = obj.m_student_ID;
			m_grade		 = obj.m_grade;

			return *this;
		}

        void setSchool(string school_t);
        void setStudentID(string student_ID_t);
        void setGrade(string grade_t);

		void entertain() const;
        virtual void study() const = 0; // action belong to student
        virtual void exam() const = 0; // action belong to student

        ~Student() {}

    protected:
        string m_school;
        string m_student_ID;
        string m_grade;
        //string profession;
};

#endif
