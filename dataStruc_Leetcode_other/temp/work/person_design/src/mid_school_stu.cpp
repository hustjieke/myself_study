//
//
//

#include "mid_school_stu.h"
#include <iostream>

using namespace std;


void MidSchoolStu::study() const {
	cout << "I am study world history" << endl;
}

void MidSchoolStu::exam() const {
	cout << "I am doing world history examination" << endl;
}

void MidSchoolStu::sleep() const {
	cout << "I sleep 9 hours one day" << endl;
}

void MidSchoolStu::selfIntroduction() const {
    cout << "My name is: " << m_name << " Age: " << m_age
        << " ID: " << m_ID << endl;
	cout << "My job is " << m_profession << endl;
}

void MidSchoolStu::doAction() const {
    selfIntroduction();

	eat(); // inherited from Human
	sleep();
	entertain(); // inherited from Student
	study();
	exam();
}
