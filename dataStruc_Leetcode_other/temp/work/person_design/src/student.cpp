//========================================================
// Copyright(c) : 2016-20xx BONC.Inc
// FileName     : student.cpp (UTF-8)
// Summary      : define class member functions in header file "student.h"
// Author       : Gaoriyao
// Version      : v1.0
// CreatTime    : 2016-5-22
// Description  : Hello World in C++, Ansi-style
// History      : # 
//========================================================


#include "human.h"
#include "student.h"
#include "judge_string.h"

#include <iostream>

using namespace std;

// set school name
void Student::setSchool(string school_t) {
    // judge string correct or not 
    judgeString(school_t); 

    m_school = school_t;
}

// set student ID 
void Student::setStudentID(string student_ID_t) {
    // judge string correct or not 
    judgeString(student_ID_t); 

    m_student_ID = student_ID_t;
}

// set grade for a student
void Student::setGrade(string grade_t) {
    // judge string correct or not 
    judgeString(grade_t);

    m_grade = grade_t;
}

void Student::entertain() const {
	cout << "Entertain: " << "play games" << endl;
}

